// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

struct FMySQLConfig;
struct MYSQL;

class EXTENDEDITOR_API FMySQLConnection
{
public:
	FMySQLConnection() = default;
	~FMySQLConnection();
	FMySQLConnection(const FMySQLConnection&) = delete;
	FMySQLConnection(FMySQLConnection&& Other) noexcept;
	FMySQLConnection& operator=(const FMySQLConnection&) = delete;
	FMySQLConnection& operator=(FMySQLConnection&& Other) noexcept;

	static bool ConnectFromEngineIni(FMySQLConnection& OutConnection);
	static bool Connect(const FMySQLConfig& Config, FMySQLConnection& OutConnection);

	MYSQL* GetConn() const { return Conn; }

private:
	MYSQL* Conn = nullptr;
	void Close();
};
