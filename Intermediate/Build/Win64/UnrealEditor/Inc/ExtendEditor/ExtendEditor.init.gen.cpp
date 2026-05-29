// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeExtendEditor_init() {}
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_ExtendEditor;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_ExtendEditor()
	{
		if (!Z_Registration_Info_UPackage__Script_ExtendEditor.OuterSingleton)
		{
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/ExtendEditor",
				nullptr,
				0,
				PKG_CompiledIn | 0x00000000,
				0x38FEAF5D,
				0x49F8F513,
				METADATA_PARAMS(nullptr, 0)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_ExtendEditor.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_ExtendEditor.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_ExtendEditor(Z_Construct_UPackage__Script_ExtendEditor, TEXT("/Script/ExtendEditor"), Z_Registration_Info_UPackage__Script_ExtendEditor, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x38FEAF5D, 0x49F8F513));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
