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

		// MySQL Connector/C++ 8 Legacy JDBC API, Win64 only
		if (Target.Platform == UnrealTargetPlatform.Win64)
		{
			bEnableExceptions = true;

			string MySqlRoot = Path.GetFullPath(Path.Combine(ModuleDirectory, "../../ThirdParty/mysql-connector-c++-8.0.20-winx64"));
			string IncludeDir = Path.Combine(MySqlRoot, "include");
			string LibDir = Path.Combine(MySqlRoot, "lib64/vs14");
			string DllDir = Path.Combine(MySqlRoot, "lib64");

			// Legacy JDBC 头文件依赖 boost/shared_ptr.hpp（使用引擎自带 Boost）
			string BoostIncludeDir = Path.Combine(EngineDirectory, "Source/ThirdParty/Boost/boost-1_70_0/include");
			PublicSystemIncludePaths.Add(BoostIncludeDir);

			PublicIncludePaths.Add(IncludeDir);

			// Recommended library link order
			PublicAdditionalLibraries.Add(Path.Combine(LibDir, "mysqlcppconn.lib"));
			PublicAdditionalLibraries.Add(Path.Combine(LibDir, "libssl.lib"));
			PublicAdditionalLibraries.Add(Path.Combine(LibDir, "libcrypto.lib"));

			PublicDelayLoadDLLs.Add("mysqlcppconn-7-vs14.dll");
			PublicDelayLoadDLLs.Add("libssl-1_1-x64.dll");
			PublicDelayLoadDLLs.Add("libcrypto-1_1-x64.dll");

			RuntimeDependencies.Add("$(TargetOutputDir)/mysqlcppconn-7-vs14.dll", Path.Combine(DllDir, "mysqlcppconn-7-vs14.dll"));
			RuntimeDependencies.Add("$(TargetOutputDir)/libssl-1_1-x64.dll", Path.Combine(DllDir, "libssl-1_1-x64.dll"));
			RuntimeDependencies.Add("$(TargetOutputDir)/libcrypto-1_1-x64.dll", Path.Combine(DllDir, "libcrypto-1_1-x64.dll"));
		}

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}