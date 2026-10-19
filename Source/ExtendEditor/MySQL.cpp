// Copyright Epic Games, Inc. All Rights Reserved.

#include "MySQL.h"

#include "MySQLConfig.h"

THIRD_PARTY_INCLUDES_START
#include <mysql.h>
THIRD_PARTY_INCLUDES_END

FMySQLQueryResult FMySQL::SelectOneFromDual()
{
	FMySQLQueryResult Result;

	const FMySQLConfig Config = FMySQLConfig::LoadFromEngineIni();

	const FTCHARToUTF8 HostUtf8(*Config.Host);
	const FTCHARToUTF8 UserUtf8(*Config.User);
	const FTCHARToUTF8 PasswordUtf8(*Config.Password);
	const FTCHARToUTF8 DatabaseUtf8(*Config.Database);
	const unsigned int MySqlPort =
		Config.Port > 0 ? static_cast<unsigned int>(Config.Port) : 3306u;

	MYSQL* Conn = mysql_init(nullptr);
	if (!Conn)
	{
		Result.ErrorMessage = TEXT("mysql_init 失败");
		return Result;
	}

	MYSQL* Mysql_Real_Connect = mysql_real_connect(Conn, HostUtf8.Get(), UserUtf8.Get(), PasswordUtf8.Get(),
	                                               DatabaseUtf8.Get(), MySqlPort, nullptr, 0);
	if (!Mysql_Real_Connect)
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
}
