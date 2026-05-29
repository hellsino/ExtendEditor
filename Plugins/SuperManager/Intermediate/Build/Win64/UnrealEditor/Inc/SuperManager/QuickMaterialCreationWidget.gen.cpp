// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SuperManager/Public/AssetActions/QuickMaterialCreationWidget.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeQuickMaterialCreationWidget() {}
// Cross Module References
	SUPERMANAGER_API UEnum* Z_Construct_UEnum_SuperManager_E_ChannelPackingType();
	UPackage* Z_Construct_UPackage__Script_SuperManager();
	SUPERMANAGER_API UClass* Z_Construct_UClass_UQuickMaterialCreationWidget_NoRegister();
	SUPERMANAGER_API UClass* Z_Construct_UClass_UQuickMaterialCreationWidget();
	BLUTILITY_API UClass* Z_Construct_UClass_UEditorUtilityWidget();
// End Cross Module References
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_E_ChannelPackingType;
	static UEnum* E_ChannelPackingType_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_E_ChannelPackingType.OuterSingleton)
		{
			Z_Registration_Info_UEnum_E_ChannelPackingType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_SuperManager_E_ChannelPackingType, Z_Construct_UPackage__Script_SuperManager(), TEXT("E_ChannelPackingType"));
		}
		return Z_Registration_Info_UEnum_E_ChannelPackingType.OuterSingleton;
	}
	template<> SUPERMANAGER_API UEnum* StaticEnum<E_ChannelPackingType>()
	{
		return E_ChannelPackingType_StaticEnum();
	}
	struct Z_Construct_UEnum_SuperManager_E_ChannelPackingType_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_SuperManager_E_ChannelPackingType_Statics::Enumerators[] = {
		{ "E_ChannelPackingType::ECPT_NoChannelPacking", (int64)E_ChannelPackingType::ECPT_NoChannelPacking },
		{ "E_ChannelPackingType::ECPT_ORM", (int64)E_ChannelPackingType::ECPT_ORM },
		{ "E_ChannelPackingType::ECPT_MAX", (int64)E_ChannelPackingType::ECPT_MAX },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_SuperManager_E_ChannelPackingType_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ECPT_MAX.DisplayName", "DefaultMAX" },
		{ "ECPT_MAX.Name", "E_ChannelPackingType::ECPT_MAX" },
		{ "ECPT_NoChannelPacking.DisplayName", "No Channel Packing" },
		{ "ECPT_NoChannelPacking.Name", "E_ChannelPackingType::ECPT_NoChannelPacking" },
		{ "ECPT_ORM.DisplayName", "OcclusionRoughnessMetallic" },
		{ "ECPT_ORM.Name", "E_ChannelPackingType::ECPT_ORM" },
		{ "ModuleRelativePath", "Public/AssetActions/QuickMaterialCreationWidget.h" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_SuperManager_E_ChannelPackingType_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_SuperManager,
		nullptr,
		"E_ChannelPackingType",
		"E_ChannelPackingType",
		Z_Construct_UEnum_SuperManager_E_ChannelPackingType_Statics::Enumerators,
		UE_ARRAY_COUNT(Z_Construct_UEnum_SuperManager_E_ChannelPackingType_Statics::Enumerators),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(Z_Construct_UEnum_SuperManager_E_ChannelPackingType_Statics::Enum_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UEnum_SuperManager_E_ChannelPackingType_Statics::Enum_MetaDataParams))
	};
	UEnum* Z_Construct_UEnum_SuperManager_E_ChannelPackingType()
	{
		if (!Z_Registration_Info_UEnum_E_ChannelPackingType.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_E_ChannelPackingType.InnerSingleton, Z_Construct_UEnum_SuperManager_E_ChannelPackingType_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_E_ChannelPackingType.InnerSingleton;
	}
	DEFINE_FUNCTION(UQuickMaterialCreationWidget::execCreateMaterialFromSelectedTextures)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->CreateMaterialFromSelectedTextures();
		P_NATIVE_END;
	}
	void UQuickMaterialCreationWidget::StaticRegisterNativesUQuickMaterialCreationWidget()
	{
		UClass* Class = UQuickMaterialCreationWidget::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "CreateMaterialFromSelectedTextures", &UQuickMaterialCreationWidget::execCreateMaterialFromSelectedTextures },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UQuickMaterialCreationWidget_CreateMaterialFromSelectedTextures_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UQuickMaterialCreationWidget_CreateMaterialFromSelectedTextures_Statics::Function_MetaDataParams[] = {
		{ "Category", "CreateMaterialFromSelectedTextures" },
		{ "ModuleRelativePath", "Public/AssetActions/QuickMaterialCreationWidget.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UQuickMaterialCreationWidget_CreateMaterialFromSelectedTextures_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UQuickMaterialCreationWidget, nullptr, "CreateMaterialFromSelectedTextures", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UQuickMaterialCreationWidget_CreateMaterialFromSelectedTextures_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UQuickMaterialCreationWidget_CreateMaterialFromSelectedTextures_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UQuickMaterialCreationWidget_CreateMaterialFromSelectedTextures()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UQuickMaterialCreationWidget_CreateMaterialFromSelectedTextures_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UQuickMaterialCreationWidget);
	UClass* Z_Construct_UClass_UQuickMaterialCreationWidget_NoRegister()
	{
		return UQuickMaterialCreationWidget::StaticClass();
	}
	struct Z_Construct_UClass_UQuickMaterialCreationWidget_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UECodeGen_Private::FBytePropertyParams NewProp_ChannelPackingType_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ChannelPackingType_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_ChannelPackingType;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bCustomMaterialName_MetaData[];
#endif
		static void NewProp_bCustomMaterialName_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bCustomMaterialName;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MaterialName_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_MaterialName;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bCreateMaterialInstance_MetaData[];
#endif
		static void NewProp_bCreateMaterialInstance_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bCreateMaterialInstance;
		static const UECodeGen_Private::FStrPropertyParams NewProp_BaseColorArray_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_BaseColorArray_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_BaseColorArray;
		static const UECodeGen_Private::FStrPropertyParams NewProp_MetallicArray_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MetallicArray_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_MetallicArray;
		static const UECodeGen_Private::FStrPropertyParams NewProp_RoughnessArray_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RoughnessArray_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_RoughnessArray;
		static const UECodeGen_Private::FStrPropertyParams NewProp_NormalArray_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_NormalArray_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_NormalArray;
		static const UECodeGen_Private::FStrPropertyParams NewProp_AmbientOcclusionArray_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AmbientOcclusionArray_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_AmbientOcclusionArray;
		static const UECodeGen_Private::FStrPropertyParams NewProp_ORMArray_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ORMArray_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ORMArray;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UEditorUtilityWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_SuperManager,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UQuickMaterialCreationWidget_CreateMaterialFromSelectedTextures, "CreateMaterialFromSelectedTextures" }, // 1633615543
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "AssetActions/QuickMaterialCreationWidget.h" },
		{ "ModuleRelativePath", "Public/AssetActions/QuickMaterialCreationWidget.h" },
	};
#endif
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_ChannelPackingType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_ChannelPackingType_MetaData[] = {
		{ "Category", "CreateMaterialFromSelectedTextures" },
		{ "ModuleRelativePath", "Public/AssetActions/QuickMaterialCreationWidget.h" },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_ChannelPackingType = { "ChannelPackingType", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UQuickMaterialCreationWidget, ChannelPackingType), Z_Construct_UEnum_SuperManager_E_ChannelPackingType, METADATA_PARAMS(Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_ChannelPackingType_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_ChannelPackingType_MetaData)) }; // 2097743797
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_bCustomMaterialName_MetaData[] = {
		{ "Category", "CreateMaterialFromSelectedTextures" },
		{ "ModuleRelativePath", "Public/AssetActions/QuickMaterialCreationWidget.h" },
	};
#endif
	void Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_bCustomMaterialName_SetBit(void* Obj)
	{
		((UQuickMaterialCreationWidget*)Obj)->bCustomMaterialName = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_bCustomMaterialName = { "bCustomMaterialName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UQuickMaterialCreationWidget), &Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_bCustomMaterialName_SetBit, METADATA_PARAMS(Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_bCustomMaterialName_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_bCustomMaterialName_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_MaterialName_MetaData[] = {
		{ "Category", "CreateMaterialFromSelectedTextures" },
		{ "EditCondition", "bCustomMaterialName" },
		{ "ModuleRelativePath", "Public/AssetActions/QuickMaterialCreationWidget.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_MaterialName = { "MaterialName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UQuickMaterialCreationWidget, MaterialName), METADATA_PARAMS(Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_MaterialName_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_MaterialName_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_bCreateMaterialInstance_MetaData[] = {
		{ "Category", "CreateMaterialFromSelectedTextures" },
		{ "ModuleRelativePath", "Public/AssetActions/QuickMaterialCreationWidget.h" },
	};
#endif
	void Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_bCreateMaterialInstance_SetBit(void* Obj)
	{
		((UQuickMaterialCreationWidget*)Obj)->bCreateMaterialInstance = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_bCreateMaterialInstance = { "bCreateMaterialInstance", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UQuickMaterialCreationWidget), &Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_bCreateMaterialInstance_SetBit, METADATA_PARAMS(Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_bCreateMaterialInstance_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_bCreateMaterialInstance_MetaData)) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_BaseColorArray_Inner = { "BaseColorArray", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_BaseColorArray_MetaData[] = {
		{ "Category", "Supported Texture Names" },
		{ "ModuleRelativePath", "Public/AssetActions/QuickMaterialCreationWidget.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_BaseColorArray = { "BaseColorArray", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UQuickMaterialCreationWidget, BaseColorArray), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_BaseColorArray_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_BaseColorArray_MetaData)) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_MetallicArray_Inner = { "MetallicArray", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_MetallicArray_MetaData[] = {
		{ "Category", "Supported Texture Names" },
		{ "ModuleRelativePath", "Public/AssetActions/QuickMaterialCreationWidget.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_MetallicArray = { "MetallicArray", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UQuickMaterialCreationWidget, MetallicArray), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_MetallicArray_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_MetallicArray_MetaData)) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_RoughnessArray_Inner = { "RoughnessArray", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_RoughnessArray_MetaData[] = {
		{ "Category", "Supported Texture Names" },
		{ "ModuleRelativePath", "Public/AssetActions/QuickMaterialCreationWidget.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_RoughnessArray = { "RoughnessArray", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UQuickMaterialCreationWidget, RoughnessArray), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_RoughnessArray_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_RoughnessArray_MetaData)) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_NormalArray_Inner = { "NormalArray", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_NormalArray_MetaData[] = {
		{ "Category", "Supported Texture Names" },
		{ "ModuleRelativePath", "Public/AssetActions/QuickMaterialCreationWidget.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_NormalArray = { "NormalArray", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UQuickMaterialCreationWidget, NormalArray), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_NormalArray_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_NormalArray_MetaData)) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_AmbientOcclusionArray_Inner = { "AmbientOcclusionArray", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_AmbientOcclusionArray_MetaData[] = {
		{ "Category", "Supported Texture Names" },
		{ "ModuleRelativePath", "Public/AssetActions/QuickMaterialCreationWidget.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_AmbientOcclusionArray = { "AmbientOcclusionArray", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UQuickMaterialCreationWidget, AmbientOcclusionArray), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_AmbientOcclusionArray_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_AmbientOcclusionArray_MetaData)) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_ORMArray_Inner = { "ORMArray", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_ORMArray_MetaData[] = {
		{ "Category", "Supported Texture Names" },
		{ "ModuleRelativePath", "Public/AssetActions/QuickMaterialCreationWidget.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_ORMArray = { "ORMArray", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UQuickMaterialCreationWidget, ORMArray), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_ORMArray_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_ORMArray_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_ChannelPackingType_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_ChannelPackingType,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_bCustomMaterialName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_MaterialName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_bCreateMaterialInstance,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_BaseColorArray_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_BaseColorArray,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_MetallicArray_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_MetallicArray,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_RoughnessArray_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_RoughnessArray,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_NormalArray_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_NormalArray,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_AmbientOcclusionArray_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_AmbientOcclusionArray,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_ORMArray_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_ORMArray,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UQuickMaterialCreationWidget>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::ClassParams = {
		&UQuickMaterialCreationWidget::StaticClass,
		"Editor",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::PropPointers),
		0,
		0x00B010A4u,
		METADATA_PARAMS(Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UQuickMaterialCreationWidget()
	{
		if (!Z_Registration_Info_UClass_UQuickMaterialCreationWidget.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UQuickMaterialCreationWidget.OuterSingleton, Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UQuickMaterialCreationWidget.OuterSingleton;
	}
	template<> SUPERMANAGER_API UClass* StaticClass<UQuickMaterialCreationWidget>()
	{
		return UQuickMaterialCreationWidget::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UQuickMaterialCreationWidget);
	struct Z_CompiledInDeferFile_FID_ExtendEditor_Plugins_SuperManager_Source_SuperManager_Public_AssetActions_QuickMaterialCreationWidget_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ExtendEditor_Plugins_SuperManager_Source_SuperManager_Public_AssetActions_QuickMaterialCreationWidget_h_Statics::EnumInfo[] = {
		{ E_ChannelPackingType_StaticEnum, TEXT("E_ChannelPackingType"), &Z_Registration_Info_UEnum_E_ChannelPackingType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2097743797U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ExtendEditor_Plugins_SuperManager_Source_SuperManager_Public_AssetActions_QuickMaterialCreationWidget_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UQuickMaterialCreationWidget, UQuickMaterialCreationWidget::StaticClass, TEXT("UQuickMaterialCreationWidget"), &Z_Registration_Info_UClass_UQuickMaterialCreationWidget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UQuickMaterialCreationWidget), 2880200895U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ExtendEditor_Plugins_SuperManager_Source_SuperManager_Public_AssetActions_QuickMaterialCreationWidget_h_686496713(TEXT("/Script/SuperManager"),
		Z_CompiledInDeferFile_FID_ExtendEditor_Plugins_SuperManager_Source_SuperManager_Public_AssetActions_QuickMaterialCreationWidget_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ExtendEditor_Plugins_SuperManager_Source_SuperManager_Public_AssetActions_QuickMaterialCreationWidget_h_Statics::ClassInfo),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_ExtendEditor_Plugins_SuperManager_Source_SuperManager_Public_AssetActions_QuickMaterialCreationWidget_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ExtendEditor_Plugins_SuperManager_Source_SuperManager_Public_AssetActions_QuickMaterialCreationWidget_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
