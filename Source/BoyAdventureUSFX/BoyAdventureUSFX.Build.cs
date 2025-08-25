// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class BoyAdventureUSFX : ModuleRules
{
	public BoyAdventureUSFX(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
