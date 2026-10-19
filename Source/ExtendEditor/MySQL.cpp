// Copyright Epic Games, Inc. All Rights Reserved.

#include "MySQL.h"
#include "Misc/ConfigCacheIni.h"

#if PLATFORM_WINDOWS
THIRD_PARTY_INCLUDES_START
#include <memory>
#include <string>
#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable : 5040)
#endif
#include <mysql/jdbc.h>
#if defined(_MSC_VER)
#pragma warning(pop)
#endif
THIRD_PARTY_INCLUDES_END
#endif

FMySQLQueryResult FMySQL::SelectOneFromDual()
{
	FMySQLQueryResult Result;

	bool bEnabled = false;
	FString Host, Database, User, Password;
	int32 Port = 3306;

	GConfig->GetBool(TEXT("MySQL"), TEXT("Enabled"), bEnabled, GEngineIni);
	GConfig->GetString(TEXT("MySQL"), TEXT("Host"), Host, GEngineIni);
	GConfig->GetInt(TEXT("MySQL"), TEXT("Port"), Port, GEngineIni);
	GConfig->GetString(TEXT("MySQL"), TEXT("Database"), Database, GEngineIni);
	GConfig->GetString(TEXT("MySQL"), TEXT("User"), User, GEngineIni);
	GConfig->GetString(TEXT("MySQL"), TEXT("Password"), Password, GEngineIni);

	if (!bEnabled || Host.IsEmpty() || Database.IsEmpty())
	{
		Result.ErrorMessage = TEXT("[MySQL] 未启用或配置不完整");
		return Result;
	}

#if !PLATFORM_WINDOWS
	Result.ErrorMessage = TEXT("仅 Win64 支持 MySQL");
	return Result;
#else
	try
	{
		sql::Driver* Driver = sql::mysql::get_mysql_driver_instance();
		sql::ConnectOptionsMap Options;
		Options["hostName"] = TCHAR_TO_UTF8(*Host);
		Options["userName"] = TCHAR_TO_UTF8(*User);
		Options["password"] = TCHAR_TO_UTF8(*Password);
		Options["schema"] = TCHAR_TO_UTF8(*Database);
		Options["port"] = Port > 0 ? Port : 3306;

		std::unique_ptr<sql::Connection> Conn(Driver->connect(Options));
		std::unique_ptr<sql::Statement> Stmt(Conn->createStatement());
		std::unique_ptr<sql::ResultSet> Rs(Stmt->executeQuery("SELECT 1 FROM DUAL"));

		if (!Rs || !Rs->next())
		{
			Result.ErrorMessage = TEXT("无查询结果");
			return Result;
		}

		Result.Value = FString(UTF8_TO_TCHAR(Rs->getString(1).c_str()));
		Result.bSuccess = true;
	}
	catch (const sql::SQLException& E)
	{
		Result.ErrorMessage = FString::Printf(TEXT("%d: %s"), E.getErrorCode(), UTF8_TO_TCHAR(E.what()));
	}
	catch (...)
	{
		Result.ErrorMessage = TEXT("MySQL 异常");
	}
	return Result;
#endif
}
