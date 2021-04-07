// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class SS_GameAsset3 : ModuleRules
{
	public SS_GameAsset3(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
