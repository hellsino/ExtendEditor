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
	static FMySQLQueryResult SelectOneFromDual();
};
