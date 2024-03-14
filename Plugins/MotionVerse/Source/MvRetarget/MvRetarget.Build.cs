using System.IO;
using UnrealBuildTool;

public class MvRetarget : ModuleRules
{
    private bool IsSourceOpened()
    {
        // Check if source is available
        string SourceFilesPath = Path.Combine(ModuleDirectory, "Private");
        return Directory.Exists(SourceFilesPath) &&
               Directory.GetFiles(SourceFilesPath).Length > 0;
    }
    
    public MvRetarget(ReadOnlyTargetRules Target) : base(Target)
    {
        bUsePrecompiled = !IsSourceOpened();
        
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
        OptimizeCode = CodeOptimization.Never;

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
                
                "MvUtilsTools"
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