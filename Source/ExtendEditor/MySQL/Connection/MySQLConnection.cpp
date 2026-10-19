// Copyright Epic Games, Inc. All Rights Reserved.

#include "MySQLConnection.h"
#include "../Config/MySQLConfig.h"

THIRD_PARTY_INCLUDES_START
#include <mysql.h>
THIRD_PARTY_INCLUDES_END

FMySQLConnection::~FMySQLConnection()
{
	Close();
}

FMySQLConnection::FMySQLConnection(FMySQLConnection&& Other) noexcept: Conn(Other.Conn)
{
	Other.Conn = nullptr;
}

FMySQLConnection& FMySQLConnection::operator=(FMySQLConnection&& Other) noexcept
{
	if (this != &Other)
	{
		Close();
		Conn = Other.Conn;
		Other.Conn = nullptr;
	}
	return *this;
}

bool FMySQLConnection::ConnectFromEngineIni(FMySQLConnection& OutConnection)
{
	const FMySQLConfig Config = FMySQLConfig::LoadFromEngineIni();
	return Connect(Config, OutConnection);
}

bool FMySQLConnection::Connect(const FMySQLConfig& Config, FMySQLConnection& OutConnection)
{
	OutConnection.Close();

	const FTCHARToUTF8 HostUtf8(*Config.Host);
	const FTCHARToUTF8 UserUtf8(*Config.User);
	const FTCHARToUTF8 PasswordUtf8(*Config.Password);
	const FTCHARToUTF8 DatabaseUtf8(*Config.Database);
	const unsigned int MySqlPort = Config.Port > 0 ? static_cast<unsigned int>(Config.Port) : 3306u;

	MYSQL* RawConn = mysql_init(nullptr);
	MYSQL* Connected = mysql_real_connect(RawConn, HostUtf8.Get(), UserUtf8.Get(), PasswordUtf8.Get(),
	                                      DatabaseUtf8.Get(), MySqlPort, nullptr, 0);
	if (!Connected)
	{
		const FString ErrorMessage(UTF8_TO_TCHAR(mysql_error(RawConn)));
		UE_LOG(LogTemp, Error, TEXT("[MySQL] connect fail: %s"), *ErrorMessage);
		mysql_close(RawConn);
		return false;
	}

	OutConnection.Conn = Connected;
	return true;
}

void FMySQLConnection::Close()
{
	if (Conn)
	{
		mysql_close(Conn);
		Conn = nullptr;
	}
}
