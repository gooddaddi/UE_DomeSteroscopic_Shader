#pragma once

#include "CoreMinimal.h"
#include "MovieRenderPipelineDataTypes.h"
#include "MoviePipelineDeferredPass.h"
#include "StereoDomeRenderPass.generated.h"

/**
 * Movie Render Queue에서 돔 스테레오 렌더링을 처리하기 위한 커스텀 패스
 */
UCLASS()
class STEREODOMESHD_API UStereoDomeRenderPass : public UMoviePipelineDeferredPassBase
{
	GENERATED_BODY()

public:
	UStereoDomeRenderPass();

protected:
	virtual void SetupImpl(const TArray<UMoviePipelineSetting*>& InAllSettings) override;
	virtual void RenderSample_GameThreadImpl(const FMoviePipelineRenderPassMetrics& InSampleMetrics) override;

	// 좌/우안 개별 렌더링 제어
	void RenderEye(const FMoviePipelineRenderPassMetrics& InSampleMetrics, int32 InViewIndex);
};
