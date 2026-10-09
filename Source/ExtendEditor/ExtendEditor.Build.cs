// Copyright Epic Games, Inc. All Rights Reserved.

using System.IO;
using UnrealBuildTool;

public class ExtendEditor : ModuleRules
{
	public ExtendEditor(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });

		PrivateDependencyModuleNames.AddRange(new string[] { });

		// MySQL Connector/C++ 8, Win64 only
		if (Target.Platform == UnrealTargetPlatform.Win64)
		{
			PrivateDefinitions.Add("STATIC_CONCPP");

			string MySQLPath =
				Path.GetFullPath(Path.Combine(ModuleDirectory, "../../ThirdParty/mysql-connector-c++-8.0.20-winx64"));
			string MySQLLibPath = Path.Combine(MySQLPath, "lib64/vs14");
			string MySQLDllPath = Path.Combine(MySQLPath, "lib64");

			PrivateIncludePaths.Add(Path.Combine(MySQLPath, "include"));

			// Recommended library link order
			PublicAdditionalLibraries.Add(Path.Combine(MySQLLibPath, "mysqlcppconn8-static.lib"));
			PublicAdditionalLibraries.Add(Path.Combine(MySQLLibPath, "libssl.lib"));
			PublicAdditionalLibraries.Add(Path.Combine(MySQLLibPath, "libcrypto.lib"));

			// Connector 仍依赖 OpenSSL 动态库
			RuntimeDependencies.Add("$(BinaryOutputDir)/libcrypto-1_1-x64.dll",
				Path.Combine(MySQLDllPath, "libcrypto-1_1-x64.dll"));
			RuntimeDependencies.Add("$(BinaryOutputDir)/libssl-1_1-x64.dll",
				Path.Combine(MySQLDllPath, "libssl-1_1-x64.dll"));
		}

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}