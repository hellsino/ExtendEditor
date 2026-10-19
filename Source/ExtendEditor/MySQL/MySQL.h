// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

struct FMySQLQueryResult
{
	bool bSuccess = false;
	FString ErrorMessage;
	FString Value;
};

class EXTENDEDITOR_API FMySQL
{
public:
	/** 使用 DefaultEngine.ini [MySQL] 连接并执行 SELECT 1 FROM DUAL */
	static FMySQLQueryResult SelectOneFromDual();
};
