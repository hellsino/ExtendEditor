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

		// MySQL C API (libmysqlclient), Win64 only — 见 ThirdParty/libmysql
		if (Target.Platform == UnrealTargetPlatform.Win64)
		{
			string MySqlRoot = Path.GetFullPath(Path.Combine(ModuleDirectory, "../../ThirdParty/libmysql"));
			string IncludeDir = Path.Combine(MySqlRoot, "include");
			string LibDir = Path.Combine(MySqlRoot, "lib");

			PublicIncludePaths.Add(IncludeDir);
			PublicAdditionalLibraries.Add(Path.Combine(LibDir, "libmysql.lib"));

			PublicDelayLoadDLLs.Add("libmysql.dll");
			RuntimeDependencies.Add("$(TargetOutputDir)/libmysql.dll", Path.Combine(LibDir, "libmysql.dll"));
		}

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
