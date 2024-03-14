// Copyright Epic Games, Inc. All Rights Reserved.

using System.IO;
using UnrealBuildTool;

public class MvUtilsTools : ModuleRules
{
	private bool IsSourceOpened()
	{
		// Check if source is available
		string SourceFilesPath = Path.Combine(ModuleDirectory, "Private");
		return Directory.Exists(SourceFilesPath) &&
		       Directory.GetFiles(SourceFilesPath).Length > 0;
	}
	
	public MvUtilsTools(ReadOnlyTargetRules Target) : base(Target)
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
				// ... add other public dependencies that you statically link with here ...
				"HTTP",
				"Json",
				"JsonUtilities",
				"Projects", 
				"InputCore",
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",			
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{

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
