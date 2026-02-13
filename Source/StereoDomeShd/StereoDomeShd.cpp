#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FStereoDomeShdModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};

IMPLEMENT_PRIMARY_GAME_MODULE(FStereoDomeShdModule, StereoDomeShd, "StereoDomeShd");

void FStereoDomeShdModule::StartupModule()
{
	// 프로젝트 전용 쉐이더 디렉토리를 가상 경로(/Project)로 매핑합니다.
	FString ShaderDirectory = FPaths::Combine(FPaths::ProjectDir(), TEXT("Shaders"));
	AddShaderSourceDirectoryMapping(TEXT("/Project"), ShaderDirectory);
}

void FStereoDomeShdModule::ShutdownModule()
{
}
