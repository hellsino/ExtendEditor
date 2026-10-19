// Copyright Epic Games, Inc. All Rights Reserved.

#include "ExtendEditor.h"
#include "MySQL.h"
#include "Modules/ModuleManager.h"

class FExtendEditorModule : public FDefaultGameModuleImpl
{
public:
	virtual void StartupModule() override
	{
		FDefaultGameModuleImpl::StartupModule();

		const FMySQLQueryResult Result = FMySQL::SelectOneFromDual();
		if (Result.bSuccess)
		{
			UE_LOG(LogTemp, Log, TEXT("[MySQL] SELECT 1 FROM DUAL => %s"), *Result.Value);
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("[MySQL] 查询失败: %s"), *Result.ErrorMessage);
		}
	}
};

IMPLEMENT_PRIMARY_GAME_MODULE(FExtendEditorModule, ExtendEditor, "ExtendEditor");
