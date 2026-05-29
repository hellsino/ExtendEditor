// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SuperManager/Public/ActorActions/QuickActorActionsWidget.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeQuickActorActionsWidget() {}
// Cross Module References
	SUPERMANAGER_API UEnum* Z_Construct_UEnum_SuperManager_E_DuplicationAxis();
	UPackage* Z_Construct_UPackage__Script_SuperManager();
	SUPERMANAGER_API UScriptStruct* Z_Construct_UScriptStruct_FRandomActorRotation();
	SUPERMANAGER_API UClass* Z_Construct_UClass_UQuickActorActionsWidget_NoRegister();
	SUPERMANAGER_API UClass* Z_Construct_UClass_UQuickActorActionsWidget();
	BLUTILITY_API UClass* Z_Construct_UClass_UEditorUtilityWidget();
	COREUOBJECT_API UEnum* Z_Construct_UEnum_CoreUObject_ESearchCase();
	UNREALED_API UClass* Z_Construct_UClass_UEditorActorSubsystem_NoRegister();
// End Cross Module References
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_E_DuplicationAxis;
	static UEnum* E_DuplicationAxis_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_E_DuplicationAxis.OuterSingleton)
		{
			Z_Registration_Info_UEnum_E_DuplicationAxis.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_SuperManager_E_DuplicationAxis, Z_Construct_UPackage__Script_SuperManager(), TEXT("E_DuplicationAxis"));
		}
		return Z_Registration_Info_UEnum_E_DuplicationAxis.OuterSingleton;
	}
	template<> SUPERMANAGER_API UEnum* StaticEnum<E_DuplicationAxis>()
	{
		return E_DuplicationAxis_StaticEnum();
	}
	struct Z_Construct_UEnum_SuperManager_E_DuplicationAxis_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_SuperManager_E_DuplicationAxis_Statics::Enumerators[] = {
		{ "E_DuplicationAxis::EDA_XAxis", (int64)E_DuplicationAxis::EDA_XAxis },
		{ "E_DuplicationAxis::EDA_YAxis", (int64)E_DuplicationAxis::EDA_YAxis },
		{ "E_DuplicationAxis::EDA_ZAxis", (int64)E_DuplicationAxis::EDA_ZAxis },
		{ "E_DuplicationAxis::EDA_MAX", (int64)E_DuplicationAxis::EDA_MAX },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_SuperManager_E_DuplicationAxis_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "EDA_MAX.DisplayName", "Default Max" },
		{ "EDA_MAX.Name", "E_DuplicationAxis::EDA_MAX" },
		{ "EDA_XAxis.DisplayName", "X Axis" },
		{ "EDA_XAxis.Name", "E_DuplicationAxis::EDA_XAxis" },
		{ "EDA_YAxis.DisplayName", "Y Axis" },
		{ "EDA_YAxis.Name", "E_DuplicationAxis::EDA_YAxis" },
		{ "EDA_ZAxis.DisplayName", "Z Axis" },
		{ "EDA_ZAxis.Name", "E_DuplicationAxis::EDA_ZAxis" },
		{ "ModuleRelativePath", "Public/ActorActions/QuickActorActionsWidget.h" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_SuperManager_E_DuplicationAxis_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_SuperManager,
		nullptr,
		"E_DuplicationAxis",
		"E_DuplicationAxis",
		Z_Construct_UEnum_SuperManager_E_DuplicationAxis_Statics::Enumerators,
		UE_ARRAY_COUNT(Z_Construct_UEnum_SuperManager_E_DuplicationAxis_Statics::Enumerators),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(Z_Construct_UEnum_SuperManager_E_DuplicationAxis_Statics::Enum_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UEnum_SuperManager_E_DuplicationAxis_Statics::Enum_MetaDataParams))
	};
	UEnum* Z_Construct_UEnum_SuperManager_E_DuplicationAxis()
	{
		if (!Z_Registration_Info_UEnum_E_DuplicationAxis.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_E_DuplicationAxis.InnerSingleton, Z_Construct_UEnum_SuperManager_E_DuplicationAxis_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_E_DuplicationAxis.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_RandomActorRotation;
class UScriptStruct* FRandomActorRotation::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_RandomActorRotation.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_RandomActorRotation.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FRandomActorRotation, Z_Construct_UPackage__Script_SuperManager(), TEXT("RandomActorRotation"));
	}
	return Z_Registration_Info_UScriptStruct_RandomActorRotation.OuterSingleton;
}
template<> SUPERMANAGER_API UScriptStruct* StaticStruct<FRandomActorRotation>()
{
	return FRandomActorRotation::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FRandomActorRotation_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bRandomizeRotYaw_MetaData[];
#endif
		static void NewProp_bRandomizeRotYaw_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bRandomizeRotYaw;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RotYawMin_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_RotYawMin;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RotYawMax_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_RotYawMax;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bRandomizeRotPitch_MetaData[];
#endif
		static void NewProp_bRandomizeRotPitch_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bRandomizeRotPitch;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RotPitchMin_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_RotPitchMin;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RotPitchMax_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_RotPitchMax;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bRandomizeRotRoll_MetaData[];
#endif
		static void NewProp_bRandomizeRotRoll_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bRandomizeRotRoll;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RotRollMin_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_RotRollMin;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RotRollMax_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_RotRollMax;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FRandomActorRotation_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/ActorActions/QuickActorActionsWidget.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FRandomActorRotation>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_bRandomizeRotYaw_MetaData[] = {
		{ "Category", "RandomActorRotation" },
		{ "ModuleRelativePath", "Public/ActorActions/QuickActorActionsWidget.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_bRandomizeRotYaw_SetBit(void* Obj)
	{
		((FRandomActorRotation*)Obj)->bRandomizeRotYaw = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_bRandomizeRotYaw = { "bRandomizeRotYaw", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(FRandomActorRotation), &Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_bRandomizeRotYaw_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_bRandomizeRotYaw_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_bRandomizeRotYaw_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_RotYawMin_MetaData[] = {
		{ "Category", "RandomActorRotation" },
		{ "EditCondition", "bRandomizeRotYaw" },
		{ "ModuleRelativePath", "Public/ActorActions/QuickActorActionsWidget.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_RotYawMin = { "RotYawMin", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FRandomActorRotation, RotYawMin), METADATA_PARAMS(Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_RotYawMin_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_RotYawMin_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_RotYawMax_MetaData[] = {
		{ "Category", "RandomActorRotation" },
		{ "EditCondition", "bRandomizeRotYaw" },
		{ "ModuleRelativePath", "Public/ActorActions/QuickActorActionsWidget.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_RotYawMax = { "RotYawMax", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FRandomActorRotation, RotYawMax), METADATA_PARAMS(Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_RotYawMax_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_RotYawMax_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_bRandomizeRotPitch_MetaData[] = {
		{ "Category", "RandomActorRotation" },
		{ "ModuleRelativePath", "Public/ActorActions/QuickActorActionsWidget.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_bRandomizeRotPitch_SetBit(void* Obj)
	{
		((FRandomActorRotation*)Obj)->bRandomizeRotPitch = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_bRandomizeRotPitch = { "bRandomizeRotPitch", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(FRandomActorRotation), &Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_bRandomizeRotPitch_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_bRandomizeRotPitch_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_bRandomizeRotPitch_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_RotPitchMin_MetaData[] = {
		{ "Category", "RandomActorRotation" },
		{ "EditCondition", "bRandomizeRotPitch" },
		{ "ModuleRelativePath", "Public/ActorActions/QuickActorActionsWidget.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_RotPitchMin = { "RotPitchMin", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FRandomActorRotation, RotPitchMin), METADATA_PARAMS(Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_RotPitchMin_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_RotPitchMin_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_RotPitchMax_MetaData[] = {
		{ "Category", "RandomActorRotation" },
		{ "EditCondition", "bRandomizeRotPitch" },
		{ "ModuleRelativePath", "Public/ActorActions/QuickActorActionsWidget.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_RotPitchMax = { "RotPitchMax", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FRandomActorRotation, RotPitchMax), METADATA_PARAMS(Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_RotPitchMax_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_RotPitchMax_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_bRandomizeRotRoll_MetaData[] = {
		{ "Category", "RandomActorRotation" },
		{ "ModuleRelativePath", "Public/ActorActions/QuickActorActionsWidget.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_bRandomizeRotRoll_SetBit(void* Obj)
	{
		((FRandomActorRotation*)Obj)->bRandomizeRotRoll = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_bRandomizeRotRoll = { "bRandomizeRotRoll", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(FRandomActorRotation), &Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_bRandomizeRotRoll_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_bRandomizeRotRoll_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_bRandomizeRotRoll_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_RotRollMin_MetaData[] = {
		{ "Category", "RandomActorRotation" },
		{ "EditCondition", "bRandomizeRotRoll" },
		{ "ModuleRelativePath", "Public/ActorActions/QuickActorActionsWidget.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_RotRollMin = { "RotRollMin", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FRandomActorRotation, RotRollMin), METADATA_PARAMS(Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_RotRollMin_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_RotRollMin_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_RotRollMax_MetaData[] = {
		{ "Category", "RandomActorRotation" },
		{ "EditCondition", "bRandomizeRotRoll" },
		{ "ModuleRelativePath", "Public/ActorActions/QuickActorActionsWidget.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_RotRollMax = { "RotRollMax", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FRandomActorRotation, RotRollMax), METADATA_PARAMS(Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_RotRollMax_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_RotRollMax_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FRandomActorRotation_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_bRandomizeRotYaw,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_RotYawMin,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_RotYawMax,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_bRandomizeRotPitch,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_RotPitchMin,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_RotPitchMax,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_bRandomizeRotRoll,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_RotRollMin,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_RotRollMax,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FRandomActorRotation_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_SuperManager,
		nullptr,
		&NewStructOps,
		"RandomActorRotation",
		sizeof(FRandomActorRotation),
		alignof(FRandomActorRotation),
		Z_Construct_UScriptStruct_FRandomActorRotation_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FRandomActorRotation_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FRandomActorRotation_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FRandomActorRotation_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FRandomActorRotation()
	{
		if (!Z_Registration_Info_UScriptStruct_RandomActorRotation.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_RandomActorRotation.InnerSingleton, Z_Construct_UScriptStruct_FRandomActorRotation_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_RandomActorRotation.InnerSingleton;
	}
	DEFINE_FUNCTION(UQuickActorActionsWidget::execRandomizeActorTransform)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->RandomizeActorTransform();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UQuickActorActionsWidget::execDuplicateActors)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->DuplicateActors();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UQuickActorActionsWidget::execSelectAllActorWithSimilarName)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SelectAllActorWithSimilarName();
		P_NATIVE_END;
	}
	void UQuickActorActionsWidget::StaticRegisterNativesUQuickActorActionsWidget()
	{
		UClass* Class = UQuickActorActionsWidget::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "DuplicateActors", &UQuickActorActionsWidget::execDuplicateActors },
			{ "RandomizeActorTransform", &UQuickActorActionsWidget::execRandomizeActorTransform },
			{ "SelectAllActorWithSimilarName", &UQuickActorActionsWidget::execSelectAllActorWithSimilarName },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UQuickActorActionsWidget_DuplicateActors_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UQuickActorActionsWidget_DuplicateActors_Statics::Function_MetaDataParams[] = {
		{ "Category", "ActorBatchDuplication" },
		{ "ModuleRelativePath", "Public/ActorActions/QuickActorActionsWidget.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UQuickActorActionsWidget_DuplicateActors_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UQuickActorActionsWidget, nullptr, "DuplicateActors", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UQuickActorActionsWidget_DuplicateActors_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UQuickActorActionsWidget_DuplicateActors_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UQuickActorActionsWidget_DuplicateActors()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UQuickActorActionsWidget_DuplicateActors_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UQuickActorActionsWidget_RandomizeActorTransform_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UQuickActorActionsWidget_RandomizeActorTransform_Statics::Function_MetaDataParams[] = {
		{ "Category", "RandomizeActorTransform" },
		{ "ModuleRelativePath", "Public/ActorActions/QuickActorActionsWidget.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UQuickActorActionsWidget_RandomizeActorTransform_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UQuickActorActionsWidget, nullptr, "RandomizeActorTransform", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UQuickActorActionsWidget_RandomizeActorTransform_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UQuickActorActionsWidget_RandomizeActorTransform_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UQuickActorActionsWidget_RandomizeActorTransform()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UQuickActorActionsWidget_RandomizeActorTransform_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UQuickActorActionsWidget_SelectAllActorWithSimilarName_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UQuickActorActionsWidget_SelectAllActorWithSimilarName_Statics::Function_MetaDataParams[] = {
		{ "Category", "ActorBatchSelection" },
		{ "ModuleRelativePath", "Public/ActorActions/QuickActorActionsWidget.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UQuickActorActionsWidget_SelectAllActorWithSimilarName_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UQuickActorActionsWidget, nullptr, "SelectAllActorWithSimilarName", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UQuickActorActionsWidget_SelectAllActorWithSimilarName_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UQuickActorActionsWidget_SelectAllActorWithSimilarName_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UQuickActorActionsWidget_SelectAllActorWithSimilarName()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UQuickActorActionsWidget_SelectAllActorWithSimilarName_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UQuickActorActionsWidget);
	UClass* Z_Construct_UClass_UQuickActorActionsWidget_NoRegister()
	{
		return UQuickActorActionsWidget::StaticClass();
	}
	struct Z_Construct_UClass_UQuickActorActionsWidget_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SearchCase_MetaData[];
#endif
		static const UECodeGen_Private::FBytePropertyParams NewProp_SearchCase;
		static const UECodeGen_Private::FBytePropertyParams NewProp_AxisForDuplication_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AxisForDuplication_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_AxisForDuplication;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_NumberOfDuplicates_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_NumberOfDuplicates;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OffsetDist_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_OffsetDist;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RandomActorRotation_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_RandomActorRotation;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bRandomizeScale_MetaData[];
#endif
		static void NewProp_bRandomizeScale_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bRandomizeScale;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ScaleMin_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ScaleMin;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ScaleMax_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ScaleMax;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bRandomizeOffset_MetaData[];
#endif
		static void NewProp_bRandomizeOffset_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bRandomizeOffset;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OffsetMin_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_OffsetMin;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OffsetMax_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_OffsetMax;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_EditorActorSubsystem_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_EditorActorSubsystem;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UQuickActorActionsWidget_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UEditorUtilityWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_SuperManager,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UQuickActorActionsWidget_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UQuickActorActionsWidget_DuplicateActors, "DuplicateActors" }, // 3752446688
		{ &Z_Construct_UFunction_UQuickActorActionsWidget_RandomizeActorTransform, "RandomizeActorTransform" }, // 24665601
		{ &Z_Construct_UFunction_UQuickActorActionsWidget_SelectAllActorWithSimilarName, "SelectAllActorWithSimilarName" }, // 4152535035
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UQuickActorActionsWidget_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "ActorActions/QuickActorActionsWidget.h" },
		{ "ModuleRelativePath", "Public/ActorActions/QuickActorActionsWidget.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_SearchCase_MetaData[] = {
		{ "Category", "ActorBatchSelection" },
		{ "ModuleRelativePath", "Public/ActorActions/QuickActorActionsWidget.h" },
	};
#endif
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_SearchCase = { "SearchCase", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UQuickActorActionsWidget, SearchCase), Z_Construct_UEnum_CoreUObject_ESearchCase, METADATA_PARAMS(Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_SearchCase_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_SearchCase_MetaData)) }; // 1578437248
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_AxisForDuplication_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_AxisForDuplication_MetaData[] = {
		{ "Category", "ActorBatchDuplication" },
		{ "ModuleRelativePath", "Public/ActorActions/QuickActorActionsWidget.h" },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_AxisForDuplication = { "AxisForDuplication", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UQuickActorActionsWidget, AxisForDuplication), Z_Construct_UEnum_SuperManager_E_DuplicationAxis, METADATA_PARAMS(Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_AxisForDuplication_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_AxisForDuplication_MetaData)) }; // 2179350869
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_NumberOfDuplicates_MetaData[] = {
		{ "Category", "ActorBatchDuplication" },
		{ "ModuleRelativePath", "Public/ActorActions/QuickActorActionsWidget.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_NumberOfDuplicates = { "NumberOfDuplicates", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UQuickActorActionsWidget, NumberOfDuplicates), METADATA_PARAMS(Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_NumberOfDuplicates_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_NumberOfDuplicates_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_OffsetDist_MetaData[] = {
		{ "Category", "ActorBatchDuplication" },
		{ "ModuleRelativePath", "Public/ActorActions/QuickActorActionsWidget.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_OffsetDist = { "OffsetDist", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UQuickActorActionsWidget, OffsetDist), METADATA_PARAMS(Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_OffsetDist_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_OffsetDist_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_RandomActorRotation_MetaData[] = {
		{ "Category", "RandomizeActorTransform" },
		{ "ModuleRelativePath", "Public/ActorActions/QuickActorActionsWidget.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_RandomActorRotation = { "RandomActorRotation", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UQuickActorActionsWidget, RandomActorRotation), Z_Construct_UScriptStruct_FRandomActorRotation, METADATA_PARAMS(Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_RandomActorRotation_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_RandomActorRotation_MetaData)) }; // 372347066
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_bRandomizeScale_MetaData[] = {
		{ "Category", "RandomizeActorTransform" },
		{ "ModuleRelativePath", "Public/ActorActions/QuickActorActionsWidget.h" },
	};
#endif
	void Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_bRandomizeScale_SetBit(void* Obj)
	{
		((UQuickActorActionsWidget*)Obj)->bRandomizeScale = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_bRandomizeScale = { "bRandomizeScale", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UQuickActorActionsWidget), &Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_bRandomizeScale_SetBit, METADATA_PARAMS(Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_bRandomizeScale_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_bRandomizeScale_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_ScaleMin_MetaData[] = {
		{ "Category", "RandomizeActorTransform" },
		{ "EditCondition", "bRandomizeScale" },
		{ "ModuleRelativePath", "Public/ActorActions/QuickActorActionsWidget.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_ScaleMin = { "ScaleMin", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UQuickActorActionsWidget, ScaleMin), METADATA_PARAMS(Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_ScaleMin_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_ScaleMin_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_ScaleMax_MetaData[] = {
		{ "Category", "RandomizeActorTransform" },
		{ "EditCondition", "bRandomizeScale" },
		{ "ModuleRelativePath", "Public/ActorActions/QuickActorActionsWidget.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_ScaleMax = { "ScaleMax", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UQuickActorActionsWidget, ScaleMax), METADATA_PARAMS(Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_ScaleMax_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_ScaleMax_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_bRandomizeOffset_MetaData[] = {
		{ "Category", "RandomizeActorTransform" },
		{ "ModuleRelativePath", "Public/ActorActions/QuickActorActionsWidget.h" },
	};
#endif
	void Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_bRandomizeOffset_SetBit(void* Obj)
	{
		((UQuickActorActionsWidget*)Obj)->bRandomizeOffset = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_bRandomizeOffset = { "bRandomizeOffset", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UQuickActorActionsWidget), &Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_bRandomizeOffset_SetBit, METADATA_PARAMS(Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_bRandomizeOffset_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_bRandomizeOffset_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_OffsetMin_MetaData[] = {
		{ "Category", "RandomizeActorTransform" },
		{ "EditCondition", "bRandomizeOffset" },
		{ "ModuleRelativePath", "Public/ActorActions/QuickActorActionsWidget.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_OffsetMin = { "OffsetMin", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UQuickActorActionsWidget, OffsetMin), METADATA_PARAMS(Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_OffsetMin_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_OffsetMin_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_OffsetMax_MetaData[] = {
		{ "Category", "RandomizeActorTransform" },
		{ "EditCondition", "bRandomizeOffset" },
		{ "ModuleRelativePath", "Public/ActorActions/QuickActorActionsWidget.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_OffsetMax = { "OffsetMax", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UQuickActorActionsWidget, OffsetMax), METADATA_PARAMS(Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_OffsetMax_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_OffsetMax_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_EditorActorSubsystem_MetaData[] = {
		{ "ModuleRelativePath", "Public/ActorActions/QuickActorActionsWidget.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_EditorActorSubsystem = { "EditorActorSubsystem", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UQuickActorActionsWidget, EditorActorSubsystem), Z_Construct_UClass_UEditorActorSubsystem_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_EditorActorSubsystem_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_EditorActorSubsystem_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UQuickActorActionsWidget_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_SearchCase,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_AxisForDuplication_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_AxisForDuplication,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_NumberOfDuplicates,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_OffsetDist,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_RandomActorRotation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_bRandomizeScale,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_ScaleMin,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_ScaleMax,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_bRandomizeOffset,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_OffsetMin,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_OffsetMax,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_EditorActorSubsystem,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UQuickActorActionsWidget_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UQuickActorActionsWidget>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UQuickActorActionsWidget_Statics::ClassParams = {
		&UQuickActorActionsWidget::StaticClass,
		"Editor",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UQuickActorActionsWidget_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UQuickActorActionsWidget_Statics::PropPointers),
		0,
		0x00B010A4u,
		METADATA_PARAMS(Z_Construct_UClass_UQuickActorActionsWidget_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UQuickActorActionsWidget_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UQuickActorActionsWidget()
	{
		if (!Z_Registration_Info_UClass_UQuickActorActionsWidget.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UQuickActorActionsWidget.OuterSingleton, Z_Construct_UClass_UQuickActorActionsWidget_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UQuickActorActionsWidget.OuterSingleton;
	}
	template<> SUPERMANAGER_API UClass* StaticClass<UQuickActorActionsWidget>()
	{
		return UQuickActorActionsWidget::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UQuickActorActionsWidget);
	struct Z_CompiledInDeferFile_FID_ExtendEditor_Plugins_SuperManager_Source_SuperManager_Public_ActorActions_QuickActorActionsWidget_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ExtendEditor_Plugins_SuperManager_Source_SuperManager_Public_ActorActions_QuickActorActionsWidget_h_Statics::EnumInfo[] = {
		{ E_DuplicationAxis_StaticEnum, TEXT("E_DuplicationAxis"), &Z_Registration_Info_UEnum_E_DuplicationAxis, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2179350869U) },
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ExtendEditor_Plugins_SuperManager_Source_SuperManager_Public_ActorActions_QuickActorActionsWidget_h_Statics::ScriptStructInfo[] = {
		{ FRandomActorRotation::StaticStruct, Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewStructOps, TEXT("RandomActorRotation"), &Z_Registration_Info_UScriptStruct_RandomActorRotation, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FRandomActorRotation), 372347066U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ExtendEditor_Plugins_SuperManager_Source_SuperManager_Public_ActorActions_QuickActorActionsWidget_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UQuickActorActionsWidget, UQuickActorActionsWidget::StaticClass, TEXT("UQuickActorActionsWidget"), &Z_Registration_Info_UClass_UQuickActorActionsWidget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UQuickActorActionsWidget), 1688233777U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ExtendEditor_Plugins_SuperManager_Source_SuperManager_Public_ActorActions_QuickActorActionsWidget_h_2856328551(TEXT("/Script/SuperManager"),
		Z_CompiledInDeferFile_FID_ExtendEditor_Plugins_SuperManager_Source_SuperManager_Public_ActorActions_QuickActorActionsWidget_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ExtendEditor_Plugins_SuperManager_Source_SuperManager_Public_ActorActions_QuickActorActionsWidget_h_Statics::ClassInfo),
		Z_CompiledInDeferFile_FID_ExtendEditor_Plugins_SuperManager_Source_SuperManager_Public_ActorActions_QuickActorActionsWidget_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ExtendEditor_Plugins_SuperManager_Source_SuperManager_Public_ActorActions_QuickActorActionsWidget_h_Statics::ScriptStructInfo),
		Z_CompiledInDeferFile_FID_ExtendEditor_Plugins_SuperManager_Source_SuperManager_Public_ActorActions_QuickActorActionsWidget_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ExtendEditor_Plugins_SuperManager_Source_SuperManager_Public_ActorActions_QuickActorActionsWidget_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
