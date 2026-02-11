// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Stealth_Heist : ModuleRules
{
	public Stealth_Heist(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
