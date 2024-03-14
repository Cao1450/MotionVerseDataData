// Copyright Epic Games, Inc. All Rights Reserved.

using System.IO;
using UnrealBuildTool;

public class MvHumanDriverRuntime : ModuleRules
{
	private bool IsSourceOpened()
	{
		// Check if source is available
		string SourceFilesPath = Path.Combine(ModuleDirectory, "Private");
		return Directory.Exists(SourceFilesPath) &&
		       Directory.GetFiles(SourceFilesPath).Length > 0;
	}
	
	public MvHumanDriverRuntime(ReadOnlyTargetRules Target) : base(Target)
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
				"Core",
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
				
				// ... add other public dependencies that you statically link with here ...
				"AnimGraphRuntime",
				
				// "Json",
				// "JsonUtilities",
				
				"MvUtilsTools",
				"MvRetarget"
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
				//"DMLivelink",
				
				"Json",
				"JsonUtilities",
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
