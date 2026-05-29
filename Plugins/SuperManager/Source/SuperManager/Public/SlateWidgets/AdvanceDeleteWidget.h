// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Widgets/SCompoundWidget.h"

class SAdvanceDeleteTab : public SCompoundWidget
{
	SLATE_BEGIN_ARGS(SAdvanceDeleteTab)
		{
		}

		SLATE_ARGUMENT(TArray<TSharedPtr<FAssetData>>, AssetDataToStore)

		SLATE_ARGUMENT(FString, CurrentSelectedFolder)

	SLATE_END_ARGS()

public:
	void Construct(const FArguments& InArgs);

private:
	TArray<TSharedPtr<FAssetData>> StoredAssetData;
	TArray<TSharedPtr<FAssetData>> DisplayedAssetData;
	TArray<TSharedRef<SCheckBox>> CheckBoxArray;
	TArray<TSharedPtr<FAssetData>> AssetDataToDeleteArray;
	TSharedPtr<SListView<TSharedPtr<FAssetData>>> ConstructedAssetListView;

#pragma region RowWidgetForAssetListView
	TSharedRef<ITableRow> OnGenerateRowForList(TSharedPtr<FAssetData> AssetDataToDisplay,
	                                           const TSharedRef<STableViewBase>& OwnerTable);
	TSharedRef<SCheckBox> ConstructCheckBox(const TSharedPtr<FAssetData>& AssetDataToDisplay);
	void OnCheckBoxStateChanged(ECheckBoxState NewState, TSharedPtr<FAssetData> AssetData);
	TSharedRef<STextBlock> ConstructTextForRowWidget(const FString& TextContent, const FSlateFontInfo& FontToUse);
	TSharedRef<SButton> ConstructButtonForRowWidget(const TSharedPtr<FAssetData>& AssetDataToDisplay);
	FReply OnDeleteButtonClicked(TSharedPtr<FAssetData> ClickedAssetData);
	FSlateFontInfo GetEmbossedTextFont() const { return FCoreStyle::Get().GetFontStyle(FName("EmbossedText")); }
	TSharedRef<SListView<TSharedPtr<FAssetData>>> ConstructAssetListView();
	void RefreshAssetListView();
	void OnRowWidgetMouseButtonClicked(TSharedPtr<FAssetData> ClickedData);
#pragma endregion

#pragma region TabButtons
	TSharedRef<SButton> ConstructDeleteAllButton();
	TSharedRef<SButton> ConstructSelectAllButton();
	TSharedRef<SButton> ConstructDeselectAllButton();

	FReply OnDeleteAllButtonClicked();
	FReply OnSelectAllButtonClicked();
	FReply OnDeselectAllButtonClicked();

	TSharedRef<STextBlock> ConstructTextForTabButtons(const FString& TextContent);
#pragma endregion

#pragma region ComboBoxForListingCondition
	TArray<TSharedPtr<FString>> ComboBoxSourceItems;
	TSharedPtr<STextBlock> ComboDisplayTextBlock;

	TSharedRef<SComboBox<TSharedPtr<FString>>> ConstructComboBox();
	TSharedRef<SWidget> OnGenerateComboContent(TSharedPtr<FString> SourceItem);
	void OnComboSelectChanged(TSharedPtr<FString> SelectedOption, ESelectInfo::Type InSelectInfo);
	TSharedRef<STextBlock> ConstructComboHelpTexts(const FString& TextContent, ETextJustify::Type TextJustify);
#pragma endregion
};
