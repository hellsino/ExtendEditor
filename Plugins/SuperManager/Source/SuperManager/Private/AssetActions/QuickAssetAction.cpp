// Fill out your copyright notice in the Description page of Project Settings.


#include "AssetActions/QuickAssetAction.h"
#include "DebugHeader.h"
#include "EditorUtilityLibrary.h"
#include "EditorAssetLibrary.h"
#include "ObjectTools.h"
#include "AssetRegistryModule.h"
#include "AssetToolsModule.h"

void UQuickAssetAction::DuplicateAssets(int32 NumOfDuplicates)
{
	if (NumOfDuplicates <= 0)
	{
		// Print(TEXT("Please enter a valid number!"), FColor::Red);
		DebugHeader::ShowMsgDialog(EAppMsgType::Ok,TEXT("Please enter a valid number!"));
		return;
	}

	uint32 Counter = 0;
	TArray<FAssetData> AssetDatas = UEditorUtilityLibrary::GetSelectedAssetData();

	for (const FAssetData& AssetData : AssetDatas)
	{
		for (int32 i = 0; i < NumOfDuplicates; i++)
		{
			const FString SourceAssetPath = AssetData.ObjectPath.ToString();
			const FString DuplicatedAssetName = AssetData.AssetName.ToString() + TEXT("_") + FString::FromInt(i + 1);
			const FString DestinationAssetPath = FPaths::Combine(AssetData.PackagePath.ToString(), DuplicatedAssetName);
			if (UEditorAssetLibrary::DuplicateAsset(SourceAssetPath, DestinationAssetPath))
			{
				UEditorAssetLibrary::SaveAsset(DestinationAssetPath, false);
				Counter++;
			}
		}
	}

	if (Counter > 0)
	{
		// Print(TEXT("Successfully duplicated " + FString::FromInt(Counter) + " files"), FColor::Green);
		DebugHeader::ShowNotifyInfo(TEXT("Successfully duplicated " + FString::FromInt(Counter) + " files"));
	}
}

void UQuickAssetAction::AddPrefixes()
{
	uint32 Counter = 0;
	TArray<UObject*> Objects = UEditorUtilityLibrary::GetSelectedAssets();

	for (UObject* Object : Objects)
	{
		if (!Object) continue;

		FString* PrefixFound = PrefixMap.Find(Object->GetClass());

		if (!PrefixFound || PrefixFound->IsEmpty())
		{
			DebugHeader::Print(TEXT("Failed to find prefix for class ") + Object->GetClass()->GetName(), FColor::Red);
			continue;
		}

		FString SourceName = Object->GetName();

		if (SourceName.StartsWith(*PrefixFound))
		{
			DebugHeader::Print(SourceName + TEXT(" already has prefix added"), FColor::Red);
			continue;
		}

		if (Object->IsA<UMaterialInstanceConstant>())
		{
			SourceName.RemoveFromStart(TEXT("M_"));
			SourceName.RemoveFromEnd(TEXT("_Inst"));
		}

		const FString SourceNameWithPrefix = *PrefixFound + SourceName;

		UEditorUtilityLibrary::RenameAsset(Object, SourceNameWithPrefix);

		Counter++;
	}

	if (Counter > 0)
	{
		DebugHeader::ShowNotifyInfo(TEXT("Successfully renamed " + FString::FromInt(Counter) + " assets"));
	}
}

void UQuickAssetAction::RemoveUnusedAssets()
{
	TArray<FAssetData> UnusedAssetsDatas;
	TArray<FAssetData> SelectedAssetDatas = UEditorUtilityLibrary::GetSelectedAssetData();

	FixUpRedirector();

	for (const FAssetData& SelectedAssetData : SelectedAssetDatas)
	{
		TArray<FString> AssetReferencers =
			UEditorAssetLibrary::FindPackageReferencersForAsset(SelectedAssetData.ObjectPath.ToString());

		if (AssetReferencers.Num() == 0)
		{
			UnusedAssetsDatas.Add(SelectedAssetData);
		}
	}

	if (UnusedAssetsDatas.Num() == 0)
	{
		DebugHeader::ShowMsgDialog(EAppMsgType::Ok,TEXT("No unused asset found among selected assets"), false);
		return;
	}

	const int32 NumOfAssetsDeleted = ObjectTools::DeleteAssets(UnusedAssetsDatas);
	if (NumOfAssetsDeleted == 0) return;

	DebugHeader::ShowNotifyInfo(
		TEXT("Successfully deleted " + FString::FromInt(NumOfAssetsDeleted) + TEXT(" unused assets"))
	);
}

void UQuickAssetAction::FixUpRedirector()
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
