// Copyright Epic Games, Inc. All Rights Reserved.

#include "MySQLConfig.h"

#include "Misc/ConfigCacheIni.h"

FMySQLConfig FMySQLConfig::LoadFromEngineIni()
{
	FMySQLConfig Config;

	GConfig->GetBool(TEXT("MySQL"), TEXT("Enabled"), Config.bEnabled, GEngineIni);
	GConfig->GetString(TEXT("MySQL"), TEXT("Host"), Config.Host, GEngineIni);
	GConfig->GetInt(TEXT("MySQL"), TEXT("Port"), Config.Port, GEngineIni);
	GConfig->GetString(TEXT("MySQL"), TEXT("Database"), Config.Database, GEngineIni);
	GConfig->GetString(TEXT("MySQL"), TEXT("User"), Config.User, GEngineIni);
	GConfig->GetString(TEXT("MySQL"), TEXT("Password"), Config.Password, GEngineIni);

	return Config;
}
