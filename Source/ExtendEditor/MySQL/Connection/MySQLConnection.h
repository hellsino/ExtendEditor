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

	bool IsConnected() const { return Conn != nullptr; }
	MYSQL* Get() const { return Conn; }
	static bool Connect(const FMySQLConfig& Config, FMySQLConnection& OutConnection, FString& OutError);
	static bool ConnectFromEngineIni(FMySQLConnection& OutConnection, FString& OutError);

private:
	void Close();
	MYSQL* Conn = nullptr;
};
