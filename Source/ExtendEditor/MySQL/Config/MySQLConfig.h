// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

/** DefaultEngine.ini [MySQL] 节中的连接配置 */
struct EXTENDEDITOR_API FMySQLConfig
{
	bool bEnabled = false;
	FString Host;
	int32 Port = 3306;
	FString Database;
	FString User;
	FString Password;

	/** 从 GEngineIni 读取 [MySQL] 配置 */
	static FMySQLConfig LoadFromEngineIni();
};
