#include "StereoDomeRenderPass.h"
#include "StereoDomeDevice.h"

UStereoDomeRenderPass::UStereoDomeRenderPass()
{
}

void UStereoDomeRenderPass::SetupImpl(const TArray<UMoviePipelineSetting*>& InAllSettings)
{
	Super::SetupImpl(InAllSettings);
}

void UStereoDomeRenderPass::RenderSample_GameThreadImpl(const FMoviePipelineRenderPassMetrics& InSampleMetrics)
{
	// 1. 좌안 렌더링
	RenderEye(InSampleMetrics, 0);

	// 2. 우안 렌더링
	RenderEye(InSampleMetrics, 1);
}

void UStereoDomeRenderPass::RenderEye(const FMoviePipelineRenderPassMetrics& InSampleMetrics, int32 InViewIndex)
{
	// 여기에서 StereoDomeDevice의 파라미터를 해당 ViewIndex에 맞춰 강제 설정하고
	// 렌더 타겟을 캡처하는 로직이 들어갑니다.
	// 실제 구현은 엔진의 SceneCapture 또는 MRQ 내부 큐를 활용합니다.
}
