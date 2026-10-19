// Copyright Epic Games, Inc. All Rights Reserved.

#include "ExtendEditor.h"
#include "MySQL/MySQL.h"
#include "Modules/ModuleManager.h"

class FExtendEditorModule : public FDefaultGameModuleImpl
{
public:
	virtual void StartupModule() override
	{
		FDefaultGameModuleImpl::StartupModule();

		const FQueryResult QueryResult = FMySQL::SelectOneFromDual();
		if (QueryResult.bSuccess)
		{
			UE_LOG(LogTemp, Log, TEXT("[MySQL] SELECT 1 FROM DUAL => %s"), *QueryResult.Value);
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("[MySQL] %s"), *QueryResult.ErrorMessage);
		}
	}
};

IMPLEMENT_PRIMARY_GAME_MODULE(FExtendEditorModule, ExtendEditor, "ExtendEditor");
