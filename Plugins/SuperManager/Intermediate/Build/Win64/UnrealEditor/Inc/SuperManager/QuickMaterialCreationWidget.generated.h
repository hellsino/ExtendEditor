// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef SUPERMANAGER_QuickMaterialCreationWidget_generated_h
#error "QuickMaterialCreationWidget.generated.h already included, missing '#pragma once' in QuickMaterialCreationWidget.h"
#endif
#define SUPERMANAGER_QuickMaterialCreationWidget_generated_h

#define FID_ExtendEditor_Plugins_SuperManager_Source_SuperManager_Public_AssetActions_QuickMaterialCreationWidget_h_25_SPARSE_DATA
#define FID_ExtendEditor_Plugins_SuperManager_Source_SuperManager_Public_AssetActions_QuickMaterialCreationWidget_h_25_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execCreateMaterialFromSelectedTextures);


#define FID_ExtendEditor_Plugins_SuperManager_Source_SuperManager_Public_AssetActions_QuickMaterialCreationWidget_h_25_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execCreateMaterialFromSelectedTextures);


#define FID_ExtendEditor_Plugins_SuperManager_Source_SuperManager_Public_AssetActions_QuickMaterialCreationWidget_h_25_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUQuickMaterialCreationWidget(); \
	friend struct Z_Construct_UClass_UQuickMaterialCreationWidget_Statics; \
public: \
	DECLARE_CLASS(UQuickMaterialCreationWidget, UEditorUtilityWidget, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/SuperManager"), NO_API) \
	DECLARE_SERIALIZER(UQuickMaterialCreationWidget)


#define FID_ExtendEditor_Plugins_SuperManager_Source_SuperManager_Public_AssetActions_QuickMaterialCreationWidget_h_25_INCLASS \
private: \
	static void StaticRegisterNativesUQuickMaterialCreationWidget(); \
	friend struct Z_Construct_UClass_UQuickMaterialCreationWidget_Statics; \
public: \
	DECLARE_CLASS(UQuickMaterialCreationWidget, UEditorUtilityWidget, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/SuperManager"), NO_API) \
	DECLARE_SERIALIZER(UQuickMaterialCreationWidget)


#define FID_ExtendEditor_Plugins_SuperManager_Source_SuperManager_Public_AssetActions_QuickMaterialCreationWidget_h_25_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UQuickMaterialCreationWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UQuickMaterialCreationWidget) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UQuickMaterialCreationWidget); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UQuickMaterialCreationWidget); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UQuickMaterialCreationWidget(UQuickMaterialCreationWidget&&); \
	NO_API UQuickMaterialCreationWidget(const UQuickMaterialCreationWidget&); \
public:


#define FID_ExtendEditor_Plugins_SuperManager_Source_SuperManager_Public_AssetActions_QuickMaterialCreationWidget_h_25_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UQuickMaterialCreationWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UQuickMaterialCreationWidget(UQuickMaterialCreationWidget&&); \
	NO_API UQuickMaterialCreationWidget(const UQuickMaterialCreationWidget&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UQuickMaterialCreationWidget); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UQuickMaterialCreationWidget); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UQuickMaterialCreationWidget)


#define FID_ExtendEditor_Plugins_SuperManager_Source_SuperManager_Public_AssetActions_QuickMaterialCreationWidget_h_22_PROLOG
#define FID_ExtendEditor_Plugins_SuperManager_Source_SuperManager_Public_AssetActions_QuickMaterialCreationWidget_h_25_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_ExtendEditor_Plugins_SuperManager_Source_SuperManager_Public_AssetActions_QuickMaterialCreationWidget_h_25_SPARSE_DATA \
	FID_ExtendEditor_Plugins_SuperManager_Source_SuperManager_Public_AssetActions_QuickMaterialCreationWidget_h_25_RPC_WRAPPERS \
	FID_ExtendEditor_Plugins_SuperManager_Source_SuperManager_Public_AssetActions_QuickMaterialCreationWidget_h_25_INCLASS \
	FID_ExtendEditor_Plugins_SuperManager_Source_SuperManager_Public_AssetActions_QuickMaterialCreationWidget_h_25_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_ExtendEditor_Plugins_SuperManager_Source_SuperManager_Public_AssetActions_QuickMaterialCreationWidget_h_25_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_ExtendEditor_Plugins_SuperManager_Source_SuperManager_Public_AssetActions_QuickMaterialCreationWidget_h_25_SPARSE_DATA \
	FID_ExtendEditor_Plugins_SuperManager_Source_SuperManager_Public_AssetActions_QuickMaterialCreationWidget_h_25_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_ExtendEditor_Plugins_SuperManager_Source_SuperManager_Public_AssetActions_QuickMaterialCreationWidget_h_25_INCLASS_NO_PURE_DECLS \
	FID_ExtendEditor_Plugins_SuperManager_Source_SuperManager_Public_AssetActions_QuickMaterialCreationWidget_h_25_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SUPERMANAGER_API UClass* StaticClass<class UQuickMaterialCreationWidget>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_ExtendEditor_Plugins_SuperManager_Source_SuperManager_Public_AssetActions_QuickMaterialCreationWidget_h


#define FOREACH_ENUM_E_CHANNELPACKINGTYPE(op) \
	op(E_ChannelPackingType::ECPT_NoChannelPacking) \
	op(E_ChannelPackingType::ECPT_ORM) 

enum class E_ChannelPackingType : uint8;
template<> SUPERMANAGER_API UEnum* StaticEnum<E_ChannelPackingType>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
