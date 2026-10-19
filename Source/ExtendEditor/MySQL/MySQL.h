// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Model/QueryResult.h"

class EXTENDEDITOR_API FMySQL
{
public:
	/** 使用 DefaultEngine.ini [MySQL] 连接并执行 SELECT 1 FROM DUAL */
	static FQueryResult SelectOneFromDual();

	static FQueryResult GetUser();
};
