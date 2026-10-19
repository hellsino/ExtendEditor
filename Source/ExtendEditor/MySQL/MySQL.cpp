// Copyright Epic Games, Inc. All Rights Reserved.

#include "MySQL.h"

#include "Connection/MySQLConnection.h"

THIRD_PARTY_INCLUDES_START
#include <mysql.h>
THIRD_PARTY_INCLUDES_END

FQueryResult FMySQL::SelectOneFromDual()
{
	FQueryResult Result;
	FMySQLConnection Connection;

	if (!FMySQLConnection::ConnectFromEngineIni(Connection))
	{
		return Result;
	}

	MYSQL* Conn = Connection.GetConnection();

	if (mysql_query(Conn, "SELECT 1 FROM DUAL") != 0)
	{
		Result.ErrorMessage = FString(UTF8_TO_TCHAR(mysql_error(Conn)));
		return Result;
	}

	MYSQL_RES* QueryResult = mysql_store_result(Conn);
	if (!QueryResult)
	{
		Result.ErrorMessage = FString(UTF8_TO_TCHAR(mysql_error(Conn)));
		return Result;
	}

	MYSQL_ROW Row = mysql_fetch_row(QueryResult);
	if (!Row || !Row[0])
	{
		Result.ErrorMessage = TEXT("No Query Result.");
		mysql_free_result(QueryResult);
		return Result;
	}

	Result.Value = FString(UTF8_TO_TCHAR(Row[0]));
	Result.bSuccess = true;

	mysql_free_result(QueryResult);
	return Result;
}

FQueryResult FMySQL::GetUser()
{
	FQueryResult Result;
	FMySQLConnection Connection;
	
	if (!FMySQLConnection::ConnectFromEngineIni(Connection))
	{
		return Result;
	}

	MYSQL* Conn = Connection.GetConnection();

	if (mysql_query(Conn, "SELECT * FROM user") != 0)
	{
		Result.ErrorMessage = FString(UTF8_TO_TCHAR(mysql_error(Conn)));
		return Result;
	}

	MYSQL_RES* QueryResult = mysql_store_result(Conn);
	if (!QueryResult)
	{
		Result.ErrorMessage = FString(UTF8_TO_TCHAR(mysql_error(Conn)));
		return Result;
	}

	MYSQL_ROW Row = mysql_fetch_row(QueryResult);
	if (!Row || !Row[0])
	{
		Result.ErrorMessage = TEXT("No Query Result.");
		mysql_free_result(QueryResult);
		return Result;
	}

	Result.Value = FString(UTF8_TO_TCHAR(Row[0]));
	Result.bSuccess = true;

	mysql_free_result(QueryResult);
	return Result;
}
