// Fill out your copyright notice in the Description page of Project Settings.


#include "ActorActions/QuickActorActionsWidget.h"
#include "Subsystems/EditorActorSubsystem.h"
#include "DebugHeader.h"

#pragma region ActorBatchSelection
void UQuickActorActionsWidget::SelectAllActorWithSimilarName()
{
	if (!GetEditorActorSubsystem()) return;

	TArray<AActor*> SelectedLevelActors = EditorActorSubsystem->GetSelectedLevelActors();
	uint32 SelectCount = 0;

	if (SelectedLevelActors.Num() == 0)
	{
		DebugHeader::ShowNotifyInfo(TEXT("No actor selected!"));
		return;
	}

	if (SelectedLevelActors.Num() > 1)
	{
		DebugHeader::ShowNotifyInfo(TEXT("You can only select one actor!"));
		return;
	}

	const FString ActorLabel = SelectedLevelActors[0]->GetActorLabel();
	const FString LeftChop = ActorLabel.LeftChop(4);

	TArray<AActor*> AllLevelActors = EditorActorSubsystem->GetAllLevelActors();
	for (AActor* Actor : AllLevelActors)
	{
		if (!Actor) continue;

		if (Actor->GetActorLabel().Contains(LeftChop, SearchCase))
		{
			EditorActorSubsystem->SetActorSelectionState(Actor, true);
			SelectCount++;
		}
	}

	if (SelectCount > 0)
	{
		DebugHeader::ShowNotifyInfo(TEXT("Successfully selected ") + FString::FromInt(SelectCount) + TEXT(" actors."));
	}
	else
	{
		DebugHeader::ShowNotifyInfo(TEXT("No actor with similar name found!"));
	}
}
#pragma endregion

#pragma region ActorBatchDuplication
void UQuickActorActionsWidget::DuplicateActors()
{
	if (!GetEditorActorSubsystem()) return;

	TArray<AActor*> SelectedLevelActors = EditorActorSubsystem->GetSelectedLevelActors();
	uint32 Count = 0;

	if (SelectedLevelActors.Num() == 0)
	{
		DebugHeader::ShowNotifyInfo(TEXT("No actor selected!"));
		return;
	}

	if (NumberOfDuplicates <= 0 || OffsetDist == 0)
	{
		DebugHeader::ShowNotifyInfo(TEXT("Did not specify a number of duplications or an offset distance!"));
		return;
	}

	for (AActor* Actor : SelectedLevelActors)
	{
		if (!Actor) continue;

		for (int32 i = 0; i < NumberOfDuplicates; i++)
		{
			AActor* DuplicatedActor = EditorActorSubsystem->DuplicateActor(Actor, Actor->GetWorld());

			if (!DuplicatedActor) continue;

			const float DuplicationOffsetDist = (i + 1) * OffsetDist;

			switch (AxisForDuplication)
			{
			case E_DuplicationAxis::EDA_XAxis:

				DuplicatedActor->AddActorWorldOffset(FVector(DuplicationOffsetDist, 0.f, 0.f));
				break;

			case E_DuplicationAxis::EDA_YAxis:

				DuplicatedActor->AddActorWorldOffset(FVector(0.f, DuplicationOffsetDist, 0.f));
				break;

			case E_DuplicationAxis::EDA_ZAxis:

				DuplicatedActor->AddActorWorldOffset(FVector(0.f, 0.f, DuplicationOffsetDist));
				break;

			case E_DuplicationAxis::EDA_MAX:
				break;

			default:
				break;
			}

			EditorActorSubsystem->SetActorSelectionState(DuplicatedActor, true);
			Count++;
		}
	}

	if (Count > 0)
	{
		DebugHeader::ShowNotifyInfo(TEXT("Successfully duplicated ") + FString::FromInt(Count) + TEXT(" actors."));
	}
}
#pragma endregion

#pragma region RandomizeActorTransform
void UQuickActorActionsWidget::RandomizeActorTransform()
{
	const bool bConditionNotSet = !RandomActorRotation.bRandomizeRotYaw
		&& !RandomActorRotation.bRandomizeRotPitch && !RandomActorRotation.bRandomizeRotRoll
		&& !bRandomizeScale && !bRandomizeOffset;

	if (bConditionNotSet)
	{
		DebugHeader::ShowNotifyInfo(TEXT("No variation condition specified!"));
		return;
	}

	if (!GetEditorActorSubsystem()) return;

	TArray<AActor*> SelectedLevelActors = EditorActorSubsystem->GetSelectedLevelActors();
	uint32 Count = 0;

	if (SelectedLevelActors.Num() == 0)
	{
		DebugHeader::ShowNotifyInfo(TEXT("No actor selected!"));
		return;
	}

	for (AActor* Actor : SelectedLevelActors)
	{
		if (!Actor) continue;

		if (RandomActorRotation.bRandomizeRotYaw)
		{
			const float RandomRotYawValue = FMath::RandRange(RandomActorRotation.RotYawMin,
			                                                 RandomActorRotation.RotYawMax);

			Actor->AddActorWorldRotation(FRotator(0.f, RandomRotYawValue, 0.f));
		}

		if (RandomActorRotation.bRandomizeRotPitch)
		{
			const float RandomRotPitchValue = FMath::RandRange(RandomActorRotation.RotPitchMin,
			                                                   RandomActorRotation.RotPitchMax);

			Actor->AddActorWorldRotation(FRotator(RandomRotPitchValue, 0.f, 0.f));
		}

		if (RandomActorRotation.bRandomizeRotRoll)
		{
			const float RandomRotRollValue = FMath::RandRange(RandomActorRotation.RotRollMin,
			                                                  RandomActorRotation.RotRollMax);

			Actor->AddActorWorldRotation(FRotator(0.f, 0.f, RandomRotRollValue));
		}

		if (bRandomizeScale)
		{
			Actor->SetActorScale3D(FVector(FMath::RandRange(ScaleMin, ScaleMax)));
		}

		if (bRandomizeOffset)
		{
			const float RandomOffsetValue = FMath::RandRange(OffsetMin, OffsetMax);

			Actor->AddActorWorldOffset(FVector(RandomOffsetValue, RandomOffsetValue, 0.f));
		}

		Count++;
	}

	if (Count > 0)
	{
		DebugHeader::ShowNotifyInfo(TEXT("Successfully set ") + FString::FromInt(Count) + TEXT(" actors."));
	}
}
#pragma endregion

bool UQuickActorActionsWidget::GetEditorActorSubsystem()
{
	if (!EditorActorSubsystem)
	{
		EditorActorSubsystem = GEditor->GetEditorSubsystem<UEditorActorSubsystem>();
	}

	return EditorActorSubsystem != nullptr;
}
