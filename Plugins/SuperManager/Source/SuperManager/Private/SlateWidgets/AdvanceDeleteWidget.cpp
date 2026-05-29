// Fill out your copyright notice in the Description page of Project Settings.


#include "SlateWidgets/AdvanceDeleteWidget.h"
#include "SlateBasics.h"
#include "DebugHeader.h"
#include "SuperManager.h"

#define ListAll TEXT("List All Available Assets")
#define ListUnused TEXT("List Unused Assets")
#define ListSameName TEXT("List Assets With Same Name")

void SAdvanceDeleteTab::Construct(const FArguments& InArgs)
{
	bCanSupportFocus = true;

	StoredAssetData = InArgs._AssetDataToStore;
	DisplayedAssetData = StoredAssetData;

	CheckBoxArray.Empty();
	AssetDataToDeleteArray.Empty();
	ComboBoxSourceItems.Empty();

	ComboBoxSourceItems.Add(MakeShared<FString>(ListAll));
	ComboBoxSourceItems.Add(MakeShared<FString>(ListUnused));
	ComboBoxSourceItems.Add(MakeShared<FString>(ListSameName));

	FSlateFontInfo TitleTextFont = GetEmbossedTextFont();
	TitleTextFont.Size = 30;

	ChildSlot
	[
		// SNew(STextBlock)
		// .Text(FText::FromString(InArgs._TestString))

		// Main vertical Box
		SNew(SVerticalBox)

		// First vertical Slot for title text
		+ SVerticalBox::Slot()
		.AutoHeight()
		[
			SNew(STextBlock)
			.Text(FText::FromString(TEXT("Advance Delete")))
			.Font(TitleTextFont)
			.Justification(ETextJustify::Center)
			.ColorAndOpacity(FColor::White)
		]

		// Second slot for drop down to specify the listing condition and help text
		+ SVerticalBox::Slot()
		.AutoHeight()
		[
			SNew(SHorizontalBox)

			// ComboBox Box Slot
			+ SHorizontalBox::Slot()
			.AutoWidth()
			[
				ConstructComboBox()
			]

			// Help text for combo box slot
			+ SHorizontalBox::Slot()
			.FillWidth(.6f)
			[
				ConstructComboHelpTexts(TEXT(
					"Specify the listing condition in the drop down. Left mouse click to go to where asset is located"),
				                        ETextJustify::Center)
			]

			// Help text for folder path
			+ SHorizontalBox::Slot()
			.FillWidth(.1f)
			[
				ConstructComboHelpTexts(TEXT("Current Folder:\n") + InArgs._CurrentSelectedFolder, ETextJustify::Right)
			]
		]

		// Third slot for the asset list
		+ SVerticalBox::Slot()
		.VAlign(VAlign_Fill)
		[
			SNew(SScrollBox)

			+ SScrollBox::Slot()
			[
				// SNew(SListView<TSharedPtr<FAssetData>>)
				// .ItemHeight(24.f)
				// .ListItemsSource(&StoredAssetData)
				// .OnGenerateRow(this, &SAdvanceDeleteTab::OnGenerateRowForList)

				ConstructAssetListView()
			]
		]

		// Fourth slot for 3 buttons
		+ SVerticalBox::Slot()
		.AutoHeight()
		[
			SNew(SHorizontalBox)

			// Button1 slot
			+ SHorizontalBox::Slot()
			.FillWidth(10.f)
			.Padding(5.f)
			[
				ConstructDeleteAllButton()
			]

			// Button2 slot
			+ SHorizontalBox::Slot()
			.FillWidth(10.f)
			.Padding(5.f)
			[
				ConstructSelectAllButton()
			]

			// Button3 slot
			+ SHorizontalBox::Slot()
			.FillWidth(10.f)
			.Padding(5.f)
			[
				ConstructDeselectAllButton()
			]
		]
	];
}

#pragma region RowWidgetForAssetListView
TSharedRef<ITableRow> SAdvanceDeleteTab::OnGenerateRowForList(TSharedPtr<FAssetData> AssetDataToDisplay,
                                                              const TSharedRef<STableViewBase>& OwnerTable)
{
	if (!AssetDataToDisplay.IsValid()) return SNew(STableRow<TSharedPtr<FAssetData>>, OwnerTable);

	const FString DisplayAssetClassName = AssetDataToDisplay->AssetClass.ToString();
	const FString DisplayAssetName = AssetDataToDisplay->AssetName.ToString();

	FSlateFontInfo AssetClassNameFont = GetEmbossedTextFont();
	AssetClassNameFont.Size = 10;
	FSlateFontInfo AssetNameFont = GetEmbossedTextFont();
	AssetNameFont.Size = 15;

	TSharedRef<STableRow<TSharedPtr<FAssetData>>> ListViewRowWidget =
		SNew(STableRow<TSharedPtr<FAssetData>>, OwnerTable).Padding(FMargin(5.f))
		[
			// SNew(STextBlock)
			// .Text(FText::FromString(DisplayAssetName))

			SNew(SHorizontalBox)

			// First slot for check box
			+ SHorizontalBox::Slot()
			.HAlign(HAlign_Left)
			.VAlign(VAlign_Center)
			.FillWidth(.05f)
			[
				ConstructCheckBox(AssetDataToDisplay)
			]

			// Second slot for displaying asset class name
			+ SHorizontalBox::Slot()
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Fill)
			.FillWidth(.5f)
			[
				ConstructTextForRowWidget(DisplayAssetClassName, AssetClassNameFont)
			]

			// Third slot for displaying asset name
			+ SHorizontalBox::Slot()
			.HAlign(HAlign_Left)
			.VAlign(VAlign_Fill)
			[
				// SNew(STextBlock)
				// .Text(FText::FromString(DisplayAssetName))

				ConstructTextForRowWidget(DisplayAssetName, AssetNameFont)
			]

			// Fourth slot for a button
			+ SHorizontalBox::Slot()
			.HAlign(HAlign_Right)
			.VAlign(VAlign_Fill)
			[
				ConstructButtonForRowWidget(AssetDataToDisplay)
			]

		];

	return ListViewRowWidget;
}

TSharedRef<SCheckBox> SAdvanceDeleteTab::ConstructCheckBox(const TSharedPtr<FAssetData>& AssetDataToDisplay)
{
	TSharedRef<SCheckBox> ConstructCheckBox = SNew(SCheckBox)
		.Type(ESlateCheckBoxType::CheckBox)
		.OnCheckStateChanged(this, &SAdvanceDeleteTab::OnCheckBoxStateChanged, AssetDataToDisplay)
		.Visibility(EVisibility::Visible);

	CheckBoxArray.Add(ConstructCheckBox);

	return ConstructCheckBox;
}

void SAdvanceDeleteTab::OnCheckBoxStateChanged(ECheckBoxState NewState, TSharedPtr<FAssetData> AssetData)
{
	switch (NewState)
	{
	case ECheckBoxState::Unchecked:
		// DebugHeader::Print(AssetData->AssetName.ToString() + TEXT(" is unchecked"), FColor::Red);
		if (AssetDataToDeleteArray.Contains(AssetData))
		{
			AssetDataToDeleteArray.Remove(AssetData);
		}
		break;

	case ECheckBoxState::Checked:
		// DebugHeader::Print(AssetData->AssetName.ToString() + TEXT(" is checked"), FColor::Red);
		AssetDataToDeleteArray.AddUnique(AssetData);
		break;

	case ECheckBoxState::Undetermined:
		break;

	default:
		break;
	}
}

TSharedRef<STextBlock> SAdvanceDeleteTab::ConstructTextForRowWidget(const FString& TextContent,
                                                                    const FSlateFontInfo& FontToUse)
{
	TSharedRef<STextBlock> ConstructTextBlock = SNew(STextBlock)
		.Text(FText::FromString(TextContent))
		.Font(FontToUse)
		.ColorAndOpacity(FColor::White);

	return ConstructTextBlock;
}

TSharedRef<SButton> SAdvanceDeleteTab::ConstructButtonForRowWidget(const TSharedPtr<FAssetData>& AssetDataToDisplay)
{
	TSharedRef<SButton> ConstructedButton = SNew(SButton)
		.Text(FText::FromString(TEXT("Delete")))
		.OnClicked(this, &SAdvanceDeleteTab::OnDeleteButtonClicked, AssetDataToDisplay);

	return ConstructedButton;
}

FReply SAdvanceDeleteTab::OnDeleteButtonClicked(TSharedPtr<FAssetData> ClickedAssetData)
{
	// DebugHeader::Print(ClickedAssetData->AssetName.ToString() + TEXT(" is clicked"), FColor::Green);

	FSuperManagerModule& SuperManagerModule =
		FModuleManager::LoadModuleChecked<FSuperManagerModule>(TEXT("SuperManager"));

	const bool bAssetDeleted = SuperManagerModule.DeleteSingleForAssetList(*ClickedAssetData.Get());

	if (bAssetDeleted)
	{
		// Updating the list source items
		if (StoredAssetData.Contains(ClickedAssetData))
		{
			StoredAssetData.Remove(ClickedAssetData);
		}

		if (DisplayedAssetData.Contains(ClickedAssetData))
		{
			DisplayedAssetData.Remove(ClickedAssetData);
		}

		// Refresh the list
		RefreshAssetListView();
	}

	return FReply::Handled();
}

TSharedRef<SListView<TSharedPtr<FAssetData>>> SAdvanceDeleteTab::ConstructAssetListView()
{
	ConstructedAssetListView = SNew(SListView<TSharedPtr<FAssetData>>)
		.ItemHeight(24.f)
		.ListItemsSource(&DisplayedAssetData)
		.OnGenerateRow(this, &SAdvanceDeleteTab::OnGenerateRowForList)
		.OnMouseButtonClick(this, &SAdvanceDeleteTab::OnRowWidgetMouseButtonClicked);

	return ConstructedAssetListView.ToSharedRef();
}

void SAdvanceDeleteTab::RefreshAssetListView()
{
	AssetDataToDeleteArray.Empty();
	CheckBoxArray.Empty();

	if (ConstructedAssetListView.IsValid())
	{
		ConstructedAssetListView->RebuildList();
	}
}

void SAdvanceDeleteTab::OnRowWidgetMouseButtonClicked(TSharedPtr<FAssetData> ClickedData)
{
	FSuperManagerModule& SuperManagerModule =
		FModuleManager::LoadModuleChecked<FSuperManagerModule>(TEXT("SuperManager"));

	SuperManagerModule.SyncContentBrowserForAssetList(ClickedData->ObjectPath.ToString());
}
#pragma endregion

#pragma region TabButtons
TSharedRef<SButton> SAdvanceDeleteTab::ConstructDeleteAllButton()
{
	TSharedRef<SButton> DeleteAllButton = SNew(SButton)
		.ContentPadding(FMargin(5.f))
		.OnClicked(this, &SAdvanceDeleteTab::OnDeleteAllButtonClicked);

	DeleteAllButton->SetContent(ConstructTextForTabButtons(TEXT("Delete All")));

	return DeleteAllButton;
}

TSharedRef<SButton> SAdvanceDeleteTab::ConstructSelectAllButton()
{
	TSharedRef<SButton> SelectAllButton = SNew(SButton)
		.ContentPadding(FMargin(5.f))
		.OnClicked(this, &SAdvanceDeleteTab::OnSelectAllButtonClicked);

	SelectAllButton->SetContent(ConstructTextForTabButtons(TEXT("Select All")));

	return SelectAllButton;
}

TSharedRef<SButton> SAdvanceDeleteTab::ConstructDeselectAllButton()
{
	TSharedRef<SButton> DeselectAllButton = SNew(SButton)
		.ContentPadding(FMargin(5.f))
		.OnClicked(this, &SAdvanceDeleteTab::OnDeselectAllButtonClicked);

	DeselectAllButton->SetContent(ConstructTextForTabButtons(TEXT("Deselect All")));

	return DeselectAllButton;
}

FReply SAdvanceDeleteTab::OnDeleteAllButtonClicked()
{
	// DebugHeader::Print(TEXT("Delete All Button Clicked"), FColor::Green);
	if (AssetDataToDeleteArray.Num() == 0)
	{
		DebugHeader::ShowMsgDialog(EAppMsgType::Ok,TEXT("No asset currently selected"));
		return FReply::Handled();
	}

	TArray<FAssetData> AssetDataToDelete;

	for (const TSharedPtr<FAssetData>& Data : AssetDataToDeleteArray)
	{
		AssetDataToDelete.Add(*Data.Get());
	}

	FSuperManagerModule& SuperManagerModule =
		FModuleManager::LoadModuleChecked<FSuperManagerModule>(TEXT("SuperManager"));

	const bool bAssetDeleted = SuperManagerModule.DeleteMultipleForAssetList(AssetDataToDelete);

	if (bAssetDeleted)
	{
		for (const TSharedPtr<FAssetData>& DeletedData : AssetDataToDeleteArray)
		{
			// Updating the stored asset data
			if (StoredAssetData.Contains(DeletedData))
			{
				StoredAssetData.Remove(DeletedData);
			}
			if (DisplayedAssetData.Contains(DeletedData))
			{
				DisplayedAssetData.Remove(DeletedData);
			}
		}

		RefreshAssetListView();
	}

	// Pass data to our module for deletion
	return FReply::Handled();
}

FReply SAdvanceDeleteTab::OnSelectAllButtonClicked()
{
	// DebugHeader::Print(TEXT("Select All Button Clicked"), FColor::Cyan);

	if (CheckBoxArray.Num() == 0) return FReply::Handled();

	for (const TSharedRef<SCheckBox>& CheckBox : CheckBoxArray)
	{
		if (!CheckBox->IsChecked())
		{
			CheckBox->ToggleCheckedState();
		}
	}

	return FReply::Handled();
}

FReply SAdvanceDeleteTab::OnDeselectAllButtonClicked()
{
	// DebugHeader::Print(TEXT("Deselect All Button Clicked"), FColor::Red);

	if (CheckBoxArray.Num() == 0) return FReply::Handled();

	for (const TSharedRef<SCheckBox>& CheckBox : CheckBoxArray)
	{
		if (CheckBox->IsChecked())
		{
			CheckBox->ToggleCheckedState();
		}
	}

	return FReply::Handled();
}

TSharedRef<STextBlock> SAdvanceDeleteTab::ConstructTextForTabButtons(const FString& TextContent)
{
	FSlateFontInfo ButtonTextFont = GetEmbossedTextFont();
	ButtonTextFont.Size = 15;

	TSharedRef<STextBlock> ConstructedTextBlock = SNew(STextBlock)
		.Text(FText::FromString(TextContent))
		.Font(ButtonTextFont)
		.Justification(ETextJustify::Center);

	return ConstructedTextBlock;
}
#pragma endregion

#pragma region ComboBoxForListingCondition
TSharedRef<SComboBox<TSharedPtr<FString>>> SAdvanceDeleteTab::ConstructComboBox()
{
	TSharedRef<SComboBox<TSharedPtr<FString>>> ConstructedComboBox = SNew(SComboBox<TSharedPtr<FString>>)
		.OptionsSource(&ComboBoxSourceItems)
		.OnGenerateWidget(this, &SAdvanceDeleteTab::OnGenerateComboContent)
		.OnSelectionChanged(this, &SAdvanceDeleteTab::OnComboSelectChanged)
		[
			SAssignNew(ComboDisplayTextBlock, STextBlock)
			.Text(FText::FromString(TEXT("List Assets Option")))
		];

	return ConstructedComboBox;
}

TSharedRef<SWidget> SAdvanceDeleteTab::OnGenerateComboContent(TSharedPtr<FString> SourceItem)
{
	TSharedRef<STextBlock> ConstructedComboText = SNew(STextBlock)
		.Text(FText::FromString(*SourceItem.Get()));

	return ConstructedComboText;
}

void SAdvanceDeleteTab::OnComboSelectChanged(TSharedPtr<FString> SelectedOption, ESelectInfo::Type InSelectInfo)
{
	DebugHeader::Print(*SelectedOption.Get(), FColor::Cyan);

	ComboDisplayTextBlock->SetText(FText::FromString(*SelectedOption.Get()));

	FSuperManagerModule& SuperManagerModule =
		FModuleManager::LoadModuleChecked<FSuperManagerModule>(TEXT("SuperManager"));

	// Pass data for our module to filter based on the selected option
	if (*SelectedOption.Get() == ListAll)
	{
		// List all stored asset data
		DisplayedAssetData = StoredAssetData;
		RefreshAssetListView();
	}
	else if (*SelectedOption.Get() == ListUnused)
	{
		// List all unused assets
		SuperManagerModule.ListUnusedForAssetList(StoredAssetData, DisplayedAssetData);
		RefreshAssetListView();
	}
	else if (*SelectedOption.Get() == ListSameName)
	{
		//List out all assets with same name
		SuperManagerModule.ListSameNameForAssetList(StoredAssetData, DisplayedAssetData);
		RefreshAssetListView();
	}
}

TSharedRef<STextBlock> SAdvanceDeleteTab::ConstructComboHelpTexts(const FString& TextContent,
                                                                  ETextJustify::Type TextJustify)
{
	TSharedRef<STextBlock> ConstructedHelpText =
		SNew(STextBlock).Text(FText::FromString(TextContent)).Justification(TextJustify).AutoWrapText(true);

	return ConstructedHelpText;
}
#pragma endregion
