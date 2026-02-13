using UnrealBuildTool;

public class StereoDomeShd : ModuleRules
{
	public StereoDomeShd(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { 
            "Core", 
            "CoreUObject", 
            "Engine", 
            "InputCore", 
            "RenderCore", 
            "RHI", 
            "Projects" 
        });

		PrivateDependencyModuleNames.AddRange(new string[] {  });
	}
}
