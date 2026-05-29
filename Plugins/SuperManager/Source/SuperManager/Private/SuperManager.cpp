// Copyright Epic Games, Inc. All Rights Reserved.

#include "SuperManager.h"
#include "ContentBrowserModule.h"
#include "DebugHeader.h"
#include "EditorAssetLibrary.h"
#include "ObjectTools.h"
#include "AssetRegistryModule.h"
#include "AssetToolsModule.h"
#include "SlateWidgets/AdvanceDeleteWidget.h"
#include "CustomStyle/SuperManagerStyle.h"
#include "LevelEditor.h"
#include "Engine/Selection.h"
#include "Subsystems/EditorActorSubsystem.h"
#include "CustomUICommands/SuperManagerUICommands.h"
#include "SceneOutlinerModule.h"
#include "CustomOutlinerColumn/OutlinerSelectionLockColumn.h"

#define LOCTEXT_NAMESPACE "FSuperManagerModule"

void FSuperManagerModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

	FSuperManagerStyle::InitializeIcon();

	InitContentBrowserMenuExtension();

	RegisterAdvanceDeleteTab();

	FSuperManagerUICommands::Register();

	InitCustomUICommands();

	InitLevelEditorExtension();

	InitCustomSelectionEvent();

	InitSceneOutlinerColumnExtension();
}

void FSuperManagerModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	FGlobalTabmanager::Get()->UnregisterNomadTabSpawner(FName("AdvanceDelete"));

	FSuperManagerStyle::ShutDown();

	FSuperManagerUICommands::Unregister();

	UnRegisterSceneOutlinerColumnExtension();
}

#pragma region ContentBrowserMenuExtension
void FSuperManagerModule::InitContentBrowserMenuExtension()
{
	FContentBrowserModule& ContentBrowserModule =
		FModuleManager::LoadModuleChecked<FContentBrowserModule>(TEXT("ContentBrowser"));

	// Get hold of all the menu extenders
	TArray<FContentBrowserMenuExtender_SelectedPaths>& ContentBrowserMenuExtenders =
		ContentBrowserModule.GetAllPathViewContextMenuExtenders();

	// 写法1：
	// FContentBrowserMenuExtender_SelectedPaths Delegate;
	// Delegate.BindRaw(this, &FSuperManagerModule::ContentBrowserMenuExtender);
	// ContentBrowserMenuExtenders.Add(Delegate);

	// 写法2：（推荐）
	// We add custom delegate to all the existing delegate
	ContentBrowserMenuExtenders.Add(
		FContentBrowserMenuExtender_SelectedPaths::CreateRaw(
			this, &FSuperManagerModule::ContentBrowserMenuExtender
		)
	);
}

// To define the position for inserting menu entry
TSharedRef<FExtender> FSuperManagerModule::ContentBrowserMenuExtender(const TArray<FString>& SelectedPaths)
{
	TSharedRef<FExtender> MenuExtender(new FExtender());

	if (SelectedPaths.Num() > 0)
	{
		MenuExtender->AddMenuExtension(
			// Extend hook,position to insert
			FName("Delete"),
			// Insert before or after
			EExtensionHook::After,
			// Custom hot keys
			TSharedPtr<FUICommandList>(),
			// Second binding, will define details for this menu entry
			FMenuExtensionDelegate::CreateRaw(this, &FSuperManagerModule::AddContentBrowserMenuEntry)
		);

		// Get all select path
		FolderPathSelected = SelectedPaths;
	}

	return MenuExtender;
}

// Define details for the custom menu entry
void FSuperManagerModule::AddContentBrowserMenuEntry(FMenuBuilder& MenuBuilder)
{
	MenuBuilder.AddMenuEntry
	(
		// Title text for menu entry
		FText::FromString(TEXT("Delete Unused Assets")),
		// Tooltip text
		FText::FromString(TEXT("Safely delete all unused assets under folder")),
		// Custom icon
		FSlateIcon(FSuperManagerStyle::GetStyleSetName(), "ContentBrowser.DeleteUnusedAssets"),
		// The actual function to execute
		FExecuteAction::CreateRaw(this, &FSuperManagerModule::OnDeleteUnusedAssetButtonClicked)
	);

	MenuBuilder.AddMenuEntry
	(
		// Title text for menu entry
		FText::FromString(TEXT("Delete Empty Folders")),
		// Tooltip text
		FText::FromString(TEXT("Safely delete all empty folders")),
		// Custom icon
		FSlateIcon(FSuperManagerStyle::GetStyleSetName(), "ContentBrowser.DeleteEmptyFolders"),
		// The actual function to execute
		FExecuteAction::CreateRaw(this, &FSuperManagerModule::OnDeleteEmptyFolderButtonClicked)
	);

	MenuBuilder.AddMenuEntry
	(
		// Title text for menu entry
		FText::FromString(TEXT("Advance Delete")),
		// Tooltip text
		FText::FromString(TEXT("List assets by specific condition in a tab for deleting")),
		// Custom icon
		FSlateIcon(FSuperManagerStyle::GetStyleSetName(), "ContentBrowser.AdvanceDelete"),
		// The actual function to execute
		FExecuteAction::CreateRaw(this, &FSuperManagerModule::OnAdvanceDeleteButtonClicked)
	);
}

void FSuperManagerModule::OnDeleteUnusedAssetButtonClicked()
{
	if (ConstructedDockTab.IsValid())
	{
		DebugHeader::ShowMsgDialog(EAppMsgType::Ok,TEXT("Please close advance deletion tab before this operation"));
		return;
	}

	if (FolderPathSelected.Num() > 1)
	{
		DebugHeader::ShowMsgDialog(EAppMsgType::Ok,TEXT("You can only do this to one folder"));
		return;
	}

	TArray<FString> AssetPathNames = UEditorAssetLibrary::ListAssets(FolderPathSelected[0]);

	// Whether there are assets under selected folder
	if (AssetPathNames.Num() == 0)
	{
		DebugHeader::ShowMsgDialog(EAppMsgType::Ok,TEXT("No asset found under selected folder"), false);
		return;
	}

	FixUpRedirector();

	TArray<FAssetData> UnusedAssetDataArray;

	for (const FString& AssetPathName : AssetPathNames)
	{
		// Don't touch root folder
		if (AssetPathName.Contains(TEXT("Developers")) || AssetPathName.Contains(TEXT("Collections")) ||
			AssetPathName.Contains(TEXT("__ExternalActors__")) || AssetPathName.Contains(TEXT("__ExternalObjects__")))
		{
			continue;
		}

		if (!UEditorAssetLibrary::DoesAssetExist(AssetPathName)) continue;

		TArray<FString> AssetReferencer = UEditorAssetLibrary::FindPackageReferencersForAsset(AssetPathName);

		if (AssetReferencer.Num() == 0)
		{
			const FAssetData UnusedAssetData = UEditorAssetLibrary::FindAssetData(AssetPathName);
			UnusedAssetDataArray.Add(UnusedAssetData);
		}
	}

	if (UnusedAssetDataArray.Num() > 0)
	{
		DebugHeader::ShowMsgDialog(EAppMsgType::YesNo,TEXT("There are ") + FString::FromInt(UnusedAssetDataArray.Num())
		                           + TEXT(" unused assets.\nDo you want to delete them?"), false);

		ObjectTools::DeleteAssets(UnusedAssetDataArray);
	}
	else
	{
		DebugHeader::ShowMsgDialog(EAppMsgType::Ok,TEXT("No unused asset found under selected folder"), false);
	}
}

void FSuperManagerModule::OnDeleteEmptyFolderButtonClicked()
{
	if (ConstructedDockTab.IsValid())
	{
		DebugHeader::ShowMsgDialog(EAppMsgType::Ok,TEXT("Please close advance deletion tab before this operation"));
		return;
	}

	FixUpRedirector();

	TArray<FString> EmptyFolderPathArray;
	FString EmptyFolderPathNames;
	uint32 Counter = 0;

	TArray<FString> FolderPathArray = UEditorAssetLibrary::ListAssets(FolderPathSelected[0], true, true);

	for (const FString& FolderPath : FolderPathArray)
	{
		if (FolderPath.Contains(TEXT("Developers")) || FolderPath.Contains(TEXT("Collections")) ||
			FolderPath.Contains(TEXT("__ExternalActors__")) || FolderPath.Contains(TEXT("__ExternalObjects__")))
		{
			continue;
		}

		if (!UEditorAssetLibrary::DoesDirectoryExist(FolderPath)) continue;

		if (!UEditorAssetLibrary::DoesDirectoryHaveAssets(FolderPath))
		{
			EmptyFolderPathNames.Append(FolderPath);
			EmptyFolderPathNames.Append(TEXT("\n"));

			EmptyFolderPathArray.Add(FolderPath);
		}
	}

	if (EmptyFolderPathArray.Num() == 0)
	{
		DebugHeader::ShowMsgDialog(EAppMsgType::Ok,TEXT("No empty folder found under selected folder"), false);
		return;
	}

	EAppReturnType::Type ConfirmResult =
		DebugHeader::ShowMsgDialog(
			EAppMsgType::OkCancel,
			TEXT("Empty folders found in:\n") + EmptyFolderPathNames + TEXT("\nWould you like to delete all?"),
			false
		);

	if (ConfirmResult == EAppReturnType::Cancel) return;

	for (const FString& EmptyFolderPath : EmptyFolderPathArray)
	{
		UEditorAssetLibrary::DeleteDirectory(EmptyFolderPath)
			? Counter++
			: DebugHeader::Print(TEXT("Failed to delete " + EmptyFolderPath), FColor::Red);
	}

	if (Counter > 0)
	{
		DebugHeader::ShowNotifyInfo(TEXT("Successfully deleted ") + FString::FromInt(Counter) + TEXT(" folders"));
	}
}

void FSuperManagerModule::OnAdvanceDeleteButtonClicked()
{
	FixUpRedirector();

	FGlobalTabmanager::Get()->TryInvokeTab(FName("AdvanceDelete"));
}

void FSuperManagerModule::FixUpRedirector()
{
	FAssetRegistryModule& AssetRegistryModule =
		FModuleManager::Get().LoadModuleChecked<FAssetRegistryModule>(TEXT("AssetRegistry"));

	FARFilter Filter;
	Filter.bRecursivePaths = true;
	Filter.PackagePaths.Emplace("/Game");
	Filter.ClassNames.Emplace("ObjectRedirector");

	TArray<UObjectRedirector*> RedirectorsToFixArray;
	TArray<FAssetData> OutAssetData;

	AssetRegistryModule.Get().GetAssets(Filter, OutAssetData);

	for (const FAssetData& Data : OutAssetData)
	{
		if (UObjectRedirector* RedirectorToFix = Cast<UObjectRedirector>(Data.GetAsset()))
		{
			RedirectorsToFixArray.Add(RedirectorToFix);
		}
	}

	FAssetToolsModule& AssetToolsModule = FModuleManager::LoadModuleChecked<FAssetToolsModule>(TEXT("AssetTools"));
	AssetToolsModule.Get().FixupReferencers(RedirectorsToFixArray);
}
#pragma endregion

#pragma region CustomEditorTab
void FSuperManagerModule::RegisterAdvanceDeleteTab()
{
	FGlobalTabmanager::Get()->RegisterNomadTabSpawner(
		                        FName("AdvanceDelete"),
		                        FOnSpawnTab::CreateRaw(this, &FSuperManagerModule::OnSpawnAdvanceDeleteTab))
	                        .SetDisplayName(FText::FromString(TEXT("Advance Delete")))
	                        .SetIcon(FSlateIcon(FSuperManagerStyle::GetStyleSetName(), "ContentBrowser.AdvanceDelete"));
}

TSharedRef<SDockTab> FSuperManagerModule::OnSpawnAdvanceDeleteTab(const FSpawnTabArgs& SpawnTabArgs)
{
	if (FolderPathSelected.Num() == 0) return SNew(SDockTab).TabRole(ETabRole::NomadTab);

	ConstructedDockTab = SNew(SDockTab).TabRole(ETabRole::NomadTab)
	[
		SNew(SAdvanceDeleteTab)
		.AssetDataToStore(GetAllAssetDataUnderSelectedFolder())
		.CurrentSelectedFolder(FolderPathSelected[0])
	];

	ConstructedDockTab->SetOnTabClosed(
		SDockTab::FOnTabClosedCallback::CreateRaw(this, &FSuperManagerModule::OnAdvanceDeleteTabClosed));

	return ConstructedDockTab.ToSharedRef();
}

TArray<TSharedPtr<FAssetData>> FSuperManagerModule::GetAllAssetDataUnderSelectedFolder()
{
	TArray<TSharedPtr<FAssetData>> AvailableAssetData;
	TArray<FString> AssetPathNames = UEditorAssetLibrary::ListAssets(FolderPathSelected[0]);

	for (const FString& AssetPathName : AssetPathNames)
	{
		// Don't touch root folder
		if (AssetPathName.Contains(TEXT("Developers")) || AssetPathName.Contains(TEXT("Collections")) ||
			AssetPathName.Contains(TEXT("__ExternalActors__")) || AssetPathName.Contains(TEXT("__ExternalObjects__")))
		{
			continue;
		}

		if (!UEditorAssetLibrary::DoesAssetExist(AssetPathName)) continue;
		const FAssetData Data = UEditorAssetLibrary::FindAssetData(AssetPathName);
		AvailableAssetData.Add(MakeShared<FAssetData>(Data));
	}

	return AvailableAssetData;
}

void FSuperManagerModule::OnAdvanceDeleteTabClosed(TSharedRef<SDockTab> TabToClose)
{
	if (ConstructedDockTab.IsValid())
	{
		ConstructedDockTab.Reset();
		FolderPathSelected.Empty();
	}
}
#pragma endregion

#pragma region LevelEditorMenuExtension
void FSuperManagerModule::InitLevelEditorExtension()
{
	FLevelEditorModule& LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>(TEXT("LevelEditor"));

	TSharedRef<FUICommandList> LevelEditorActions = LevelEditorModule.GetGlobalLevelEditorActions();
	LevelEditorActions->Append(CustomUICommands.ToSharedRef());

	TArray<FLevelEditorModule::FLevelViewportMenuExtender_SelectedActors>& LevelEditorMenuExtenders =
		LevelEditorModule.GetAllLevelViewportContextMenuExtenders();

	LevelEditorMenuExtenders.Add(FLevelEditorModule::FLevelViewportMenuExtender_SelectedActors::
		CreateRaw(this, &FSuperManagerModule::CustomLevelEditorMenuExtender));
}

TSharedRef<FExtender> FSuperManagerModule::CustomLevelEditorMenuExtender(const TSharedRef<FUICommandList> UICommandList,
                                                                         const TArray<AActor*> SelectedActors)
{
	TSharedRef<FExtender> MenuExtender = MakeShareable(new FExtender());

	if (SelectedActors.Num() > 0)
	{
		MenuExtender->AddMenuExtension(
			FName("ActorOptions"),
			EExtensionHook::Before,
			UICommandList,
			FMenuExtensionDelegate::CreateRaw(this, &FSuperManagerModule::AddLevelEditorMenuEntry)
		);
	}

	return MenuExtender;
}

void FSuperManagerModule::AddLevelEditorMenuEntry(FMenuBuilder& MenuBuilder)
{
	MenuBuilder.AddMenuEntry
	(
		FText::FromString(TEXT("Lock Actor Selection")),
		FText::FromString(TEXT("Prevent actor from being selected")),
		FSlateIcon(FSuperManagerStyle::GetStyleSetName(), "LevelEditor.LockSelection"),
		FExecuteAction::CreateRaw(this, &FSuperManagerModule::OnLockActorSelectButtonClicked)
	);

	MenuBuilder.AddMenuEntry
	(
		FText::FromString(TEXT("Unlock All Actor Selection")),
		FText::FromString(TEXT("Remove the selection constraint on all actor")),
		FSlateIcon(FSuperManagerStyle::GetStyleSetName(), "LevelEditor.UnlockSelection"),
		FExecuteAction::CreateRaw(this, &FSuperManagerModule::OnUnlockActorSelectButtonClicked)
	);
}

void FSuperManagerModule::OnLockActorSelectButtonClicked()
{
	// DebugHeader::Print(TEXT("Locked"), FColor::Cyan);

	if (!GetEditorActorSubsystem()) return;

	TArray<AActor*> SelectedActors = WeakEditorActorSubsystem->GetSelectedLevelActors();

	if (SelectedActors.Num() == 0)
	{
		DebugHeader::ShowNotifyInfo(TEXT("No actor selected"));
		return;
	}

	FString CurrentLockedActorNames = TEXT("Locked selection for:");

	for (AActor* SelectedActor : SelectedActors)
	{
		if (!SelectedActor) continue;

		LockActorSelection(SelectedActor);

		WeakEditorActorSubsystem->SetActorSelectionState(SelectedActor, false);

		CurrentLockedActorNames.Append(TEXT("\n"));
		CurrentLockedActorNames.Append(SelectedActor->GetActorLabel());
	}

	RefreshSceneOutliner();

	DebugHeader::ShowNotifyInfo(CurrentLockedActorNames);
}

void FSuperManagerModule::OnUnlockActorSelectButtonClicked()
{
	// DebugHeader::Print(TEXT("Unlocked"), FColor::Red);

	if (!GetEditorActorSubsystem()) return;

	TArray<AActor*> AllActorsInLevel = WeakEditorActorSubsystem->GetAllLevelActors();
	TArray<AActor*> AllLockedActors;

	for (AActor* ActorInLevel : AllActorsInLevel)
	{
		if (!ActorInLevel) continue;

		if (CheckIsActorSelectionLocked(ActorInLevel))
		{
			AllLockedActors.Add(ActorInLevel);
		}
	}

	if (AllLockedActors.Num() == 0)
	{
		DebugHeader::ShowNotifyInfo(TEXT("No selection locked actor currently"));
		return;
	}

	FString UnlockedActorNames = TEXT("Lifted selection constraint for:");

	for (AActor* LockedActor : AllLockedActors)
	{
		UnlockActorSelection(LockedActor);

		UnlockedActorNames.Append(TEXT("\n"));
		UnlockedActorNames.Append(LockedActor->GetActorLabel());
	}

	RefreshSceneOutliner();

	DebugHeader::ShowNotifyInfo(UnlockedActorNames);
}
#pragma endregion

#pragma region SelectionLock
void FSuperManagerModule::InitCustomSelectionEvent()
{
	USelection* UserSelection = GEditor->GetSelectedActors();

	UserSelection->SelectObjectEvent.AddRaw(this, &FSuperManagerModule::OnActorSelected);
}

void FSuperManagerModule::OnActorSelected(UObject* SelectedObject)
{
	if (!GetEditorActorSubsystem()) return;

	if (AActor* SelectedActor = Cast<AActor>(SelectedObject))
	{
		// DebugHeader::Print(SelectedActor->GetActorLabel(), FColor::Cyan);

		if (CheckIsActorSelectionLocked(SelectedActor))
		{
			// Deselect actor right away
			WeakEditorActorSubsystem->SetActorSelectionState(SelectedActor, false);
		}
	}
}

void FSuperManagerModule::LockActorSelection(AActor* ActorToProcess)
{
	if (!ActorToProcess) return;

	if (!ActorToProcess->ActorHasTag(FName("Locked")))
	{
		ActorToProcess->Tags.Add(FName("Locked"));
	}
}

void FSuperManagerModule::UnlockActorSelection(AActor* ActorToProcess)
{
	if (!ActorToProcess) return;

	if (ActorToProcess->ActorHasTag(FName("Locked")))
	{
		ActorToProcess->Tags.Remove(FName("Locked"));
	}
}

void FSuperManagerModule::RefreshSceneOutliner()
{
	FLevelEditorModule& LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>(TEXT("LevelEditor"));
	TSharedPtr<ISceneOutliner> SceneOutliner = LevelEditorModule.GetFirstLevelEditor()->GetSceneOutliner();
	if (SceneOutliner.IsValid())
	{
		SceneOutliner->FullRefresh();
	}
}
#pragma endregion

#pragma region CustomEditorUICommands
void FSuperManagerModule::InitCustomUICommands()
{
	CustomUICommands = MakeShareable(new FUICommandList());

	CustomUICommands->MapAction(
		FSuperManagerUICommands::Get().LockActorSelection,
		FExecuteAction::CreateRaw(this, &FSuperManagerModule::OnSelectionLockHotKeyPressed)
	);

	CustomUICommands->MapAction(
		FSuperManagerUICommands::Get().UnlockActorSelection,
		FExecuteAction::CreateRaw(this, &FSuperManagerModule::OnUnlockActorSelectionHotKeyPressed)
	);
}

void FSuperManagerModule::OnSelectionLockHotKeyPressed()
{
	OnLockActorSelectButtonClicked();
}

void FSuperManagerModule::OnUnlockActorSelectionHotKeyPressed()
{
	OnUnlockActorSelectButtonClicked();
}
#pragma endregion

#pragma region SceneOutlinerExtension
void FSuperManagerModule::InitSceneOutlinerColumnExtension()
{
	FSceneOutlinerModule& SceneOutlinerModule =
		FModuleManager::LoadModuleChecked<FSceneOutlinerModule>(TEXT("SceneOutliner"));

	FSceneOutlinerColumnInfo SelectionLockColumnInfo(
		ESceneOutlinerColumnVisibility::Visible,
		1,
		FCreateSceneOutlinerColumn::CreateRaw(this, &FSuperManagerModule::OnCreateSelectionLockColumn)
	);

	SceneOutlinerModule.RegisterDefaultColumnType<FOutlinerSelectionLockColumn>(SelectionLockColumnInfo);
}

TSharedRef<ISceneOutlinerColumn> FSuperManagerModule::OnCreateSelectionLockColumn(ISceneOutliner& SceneOutliner)
{
	return MakeShareable(new FOutlinerSelectionLockColumn(SceneOutliner));
}

void FSuperManagerModule::UnRegisterSceneOutlinerColumnExtension()
{
	FSceneOutlinerModule& SceneOutlinerModule =
		FModuleManager::LoadModuleChecked<FSceneOutlinerModule>(TEXT("SceneOutliner"));

	SceneOutlinerModule.UnRegisterColumnType<FOutlinerSelectionLockColumn>();
}
#pragma endregion

bool FSuperManagerModule::GetEditorActorSubsystem()
{
	if (!WeakEditorActorSubsystem.IsValid())
	{
		WeakEditorActorSubsystem = GEditor->GetEditorSubsystem<UEditorActorSubsystem>();
	}

	return WeakEditorActorSubsystem.IsValid();
}

#pragma region ProccessDataForAdvanceDeletionTab
bool FSuperManagerModule::DeleteSingleForAssetList(const FAssetData& AssetDataToDelete)
{
	TArray<FAssetData> AssetDataForDelete;
	AssetDataForDelete.Add(AssetDataToDelete);

	if (ObjectTools::DeleteAssets(AssetDataForDelete) > 0)
	{
		return true;
	}

	return false;
}

bool FSuperManagerModule::DeleteMultipleForAssetList(const TArray<FAssetData>& AssetToDelete)
{
	if (ObjectTools::DeleteAssets(AssetToDelete) > 0)
	{
		return true;
	}

	return false;
}

void FSuperManagerModule::ListUnusedForAssetList(const TArray<TSharedPtr<FAssetData>>& AssetDataToFilter,
                                                 TArray<TSharedPtr<FAssetData>>& OutUnusedAssetData)
{
	OutUnusedAssetData.Empty();

	for (const TSharedPtr<FAssetData>& DataSharedPtr : AssetDataToFilter)
	{
		TArray<FString> AssetReferencer = UEditorAssetLibrary::FindPackageReferencersForAsset(
			DataSharedPtr->ObjectPath.ToString());

		if (AssetReferencer.Num() == 0)
		{
			OutUnusedAssetData.Add(DataSharedPtr);
		}
	}
}

void FSuperManagerModule::ListSameNameForAssetList(const TArray<TSharedPtr<FAssetData>>& AssetDataToFilter,
                                                   TArray<TSharedPtr<FAssetData>>& OutSameNameAssetData)
{
	OutSameNameAssetData.Empty();

	// Multimap for supporting finding asset with same name
	TMultiMap<FString, TSharedPtr<FAssetData>> AssetInfoMultiMap;

	for (const TSharedPtr<FAssetData>& DataSharedPtr : AssetDataToFilter)
	{
		AssetInfoMultiMap.Emplace(DataSharedPtr->AssetName.ToString(), DataSharedPtr);
	}

	for (const TSharedPtr<FAssetData>& DataSharedPtr : AssetDataToFilter)
	{
		TArray<TSharedPtr<FAssetData>> OutAssetData;
		AssetInfoMultiMap.MultiFind(DataSharedPtr->AssetName.ToString(), OutAssetData);

		if (OutAssetData.Num() <= 1) continue;

		for (const TSharedPtr<FAssetData>& SameNameData : OutAssetData)
		{
			if (SameNameData.IsValid())
			{
				OutSameNameAssetData.AddUnique(SameNameData);
			}
		}
	}
}

void FSuperManagerModule::SyncContentBrowserForAssetList(const FString& AssetPathToSync)
{
	TArray<FString> AssetPathToSyncArray;
	AssetPathToSyncArray.Add(AssetPathToSync);

	UEditorAssetLibrary::SyncBrowserToObjects(AssetPathToSyncArray);
}
#pragma endregion

bool FSuperManagerModule::CheckIsActorSelectionLocked(AActor* ActorToProcess)
{
	if (!ActorToProcess) return false;

	return ActorToProcess->ActorHasTag(FName("Locked"));
}

void FSuperManagerModule::ProcessLockingForOutliner(AActor* ActorToProcess, bool bShouldLock)
{
	if (!GetEditorActorSubsystem()) return;

	if (bShouldLock)
	{
		LockActorSelection(ActorToProcess);

		WeakEditorActorSubsystem->SetActorSelectionState(ActorToProcess, false);

		DebugHeader::ShowNotifyInfo(TEXT("Locked selection for:\n") + ActorToProcess->GetActorLabel());
	}
	else
	{
		UnlockActorSelection(ActorToProcess);

		DebugHeader::ShowNotifyInfo(TEXT("Removed selection lock for:\n") + ActorToProcess->GetActorLabel());
	}
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FSuperManagerModule, SuperManager)
