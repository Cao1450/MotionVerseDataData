// Copyright Epic Games, Inc. All Rights Reserved.

using System.IO;
using UnrealBuildTool;

public class MvHumanDriverEditor : ModuleRules
{
	private bool IsSourceOpened()
	{
		// Check if source is available
		string SourceFilesPath = Path.Combine(ModuleDirectory, "Private");
		return Directory.Exists(SourceFilesPath) &&
		       Directory.GetFiles(SourceFilesPath).Length > 0;
	}
	
	public MvHumanDriverEditor(ReadOnlyTargetRules Target) : base(Target)
	{
		bUsePrecompiled = !IsSourceOpened();
		
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicIncludePaths.AddRange(
			new string[] {
				// ... add public include paths required here ...
			}
			);
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
				// ... add other private include paths required here ...
			}
			);
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				//https://blog.csdn.net/u012863565/article/details/122109409
				"Core",
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
				"InputCore",
				"UnrealEd",
				"AnimGraph",
				"AnimGraphRuntime",
				"BlueprintGraph",
				// ... add other public dependencies that you statically link with here ...
				
				"MvHumanDriverRuntime",
				"MvUtilsTools",
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
				// ... add private dependencies that you statically link with here ...	
			}
			);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);
    }
}
