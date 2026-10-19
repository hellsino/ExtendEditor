// Copyright Epic Games, Inc. All Rights Reserved.

#include "MySQL.h"
#include "Misc/ConfigCacheIni.h"

#if PLATFORM_WINDOWS
THIRD_PARTY_INCLUDES_START
#include <mysql.h>
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

#if !PLATFORM_WINDOWS
	Result.ErrorMessage = TEXT("仅 Win64 支持 MySQL C API");
	return Result;
#else
	const FTCHARToUTF8 HostUtf8(*Host);
	const FTCHARToUTF8 UserUtf8(*User);
	const FTCHARToUTF8 PasswordUtf8(*Password);
	const FTCHARToUTF8 DatabaseUtf8(*Database);
	const unsigned int MySqlPort = Port > 0 ? static_cast<unsigned int>(Port) : 3306u;

	MYSQL* Conn = mysql_init(nullptr);
	if (!Conn)
	{
		Result.ErrorMessage = TEXT("mysql_init 失败");
		return Result;
	}

	if (!mysql_real_connect(Conn,HostUtf8.Get(),UserUtf8.Get(),PasswordUtf8.Get(),DatabaseUtf8.Get(),MySqlPort,nullptr,0))
	{
		Result.ErrorMessage = FString(UTF8_TO_TCHAR(mysql_error(Conn)));
		mysql_close(Conn);
		return Result;
	}

	if (mysql_query(Conn, "SELECT 1 FROM DUAL") != 0)
	{
		Result.ErrorMessage = FString(UTF8_TO_TCHAR(mysql_error(Conn)));
		mysql_close(Conn);
		return Result;
	}

	MYSQL_RES* QueryResult = mysql_store_result(Conn);
	if (!QueryResult)
	{
		Result.ErrorMessage = FString(UTF8_TO_TCHAR(mysql_error(Conn)));
		mysql_close(Conn);
		return Result;
	}

	MYSQL_ROW Row = mysql_fetch_row(QueryResult);
	if (!Row || !Row[0])
	{
		Result.ErrorMessage = TEXT("无查询结果");
		mysql_free_result(QueryResult);
		mysql_close(Conn);
		return Result;
	}

	Result.Value = FString(UTF8_TO_TCHAR(Row[0]));
	Result.bSuccess = true;

	mysql_free_result(QueryResult);
	mysql_close(Conn);
	return Result;
#endif
}
