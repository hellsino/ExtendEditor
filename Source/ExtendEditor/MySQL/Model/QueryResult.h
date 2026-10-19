// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

struct EXTENDEDITOR_API FQueryResult
{
	bool bSuccess = false;
	FString ErrorMessage;
	FString Value;
};
