// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FSuperManagerModule : public IModuleInterface
{
public:
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

private:
#pragma region ContentBrowserMenuExtension
	TArray<FString> FolderPathSelected;

	void InitContentBrowserMenuExtension();
	TSharedRef<FExtender> ContentBrowserMenuExtender(const TArray<FString>& SelectedPaths);
	void AddContentBrowserMenuEntry(class FMenuBuilder& MenuBuilder);
	void OnDeleteUnusedAssetButtonClicked();
	void OnDeleteEmptyFolderButtonClicked();
	void OnAdvanceDeleteButtonClicked();
	void FixUpRedirector();
#pragma endregion

#pragma region CustomEditorTab
	TSharedPtr<SDockTab> ConstructedDockTab;

	void RegisterAdvanceDeleteTab();
	TSharedRef<SDockTab> OnSpawnAdvanceDeleteTab(const FSpawnTabArgs& SpawnTabArgs);
	TArray<TSharedPtr<FAssetData>> GetAllAssetDataUnderSelectedFolder();
	void OnAdvanceDeleteTabClosed(TSharedRef<SDockTab> TabToClose);
#pragma endregion

#pragma region LevelEditorMenuExtension
	void InitLevelEditorExtension();
	TSharedRef<FExtender> CustomLevelEditorMenuExtender(const TSharedRef<FUICommandList> UICommandList,
	                                                    const TArray<AActor*> SelectedActors);
	void AddLevelEditorMenuEntry(class FMenuBuilder& MenuBuilder);
	void OnLockActorSelectButtonClicked();
	void OnUnlockActorSelectButtonClicked();
#pragma endregion

#pragma region SelectionLock
	void InitCustomSelectionEvent();
	void OnActorSelected(UObject* SelectedObject);
	void LockActorSelection(AActor* ActorToProcess);
	void UnlockActorSelection(AActor* ActorToProcess);
	void RefreshSceneOutliner();
#pragma endregion

#pragma region CustomEditorUICommands
	TSharedPtr<class FUICommandList> CustomUICommands;
	void InitCustomUICommands();
	void OnSelectionLockHotKeyPressed();
	void OnUnlockActorSelectionHotKeyPressed();
#pragma endregion

#pragma region SceneOutlinerExtension
	void InitSceneOutlinerColumnExtension();
	TSharedRef<class ISceneOutlinerColumn> OnCreateSelectionLockColumn(class ISceneOutliner& SceneOutliner);
	void UnRegisterSceneOutlinerColumnExtension();
#pragma endregion

	TWeakObjectPtr<class UEditorActorSubsystem> WeakEditorActorSubsystem;

	bool GetEditorActorSubsystem();

public:
#pragma region ProccessDataForAdvanceDeletionTab
	bool DeleteSingleForAssetList(const FAssetData& AssetDataToDelete);
	bool DeleteMultipleForAssetList(const TArray<FAssetData>& AssetToDelete);
	void ListUnusedForAssetList(const TArray<TSharedPtr<FAssetData>>& AssetDataToFilter,
	                            TArray<TSharedPtr<FAssetData>>& OutUnusedAssetData);
	void ListSameNameForAssetList(const TArray<TSharedPtr<FAssetData>>& AssetDataToFilter,
	                              TArray<TSharedPtr<FAssetData>>& OutSameNameAssetData);
	void SyncContentBrowserForAssetList(const FString& AssetPathToSync);
#pragma endregion

	bool CheckIsActorSelectionLocked(AActor* ActorToProcess);
	void ProcessLockingForOutliner(AActor* ActorToProcess, bool bShouldLock);
};
