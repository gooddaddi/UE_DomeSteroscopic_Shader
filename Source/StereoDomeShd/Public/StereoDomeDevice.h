#pragma once

#include "CoreMinimal.h"
#include "StereoRendering.h"

/**
 * 돔 스테레오 렌더링을 담당하는 디바이스 클래스
 * IStereoRendering을 상속받아 커스텀 투사 행렬을 적용합니다.
 */
class FStereoDomeDevice : public IStereoRendering, public IT頭edDisplay // 5.7 기준 인터페이스 확인 필요
{
public:
	FStereoDomeDevice();
	virtual ~FStereoDomeDevice() {}

	// IStereoRendering 인터페이스 구현
	virtual bool IsStereoEnabled() const override { return true; }
	virtual bool EnableStereo(bool bStereo = true) override { return true; }
	virtual void AdjustViewRect(int32 ViewIndex, int32& X, int32& Y, uint32& SizeX, uint32& SizeY) const override;
	virtual void CalculateStereoViewOffset(const int32 ViewIndex, FRotator& ViewRotation, const float WorldToMeters, FVector& ViewLocation) override;
	virtual FMatrix GetStereoProjectionMatrix(const int32 ViewIndex) const override;
	
	// 파라미터 제어
	float IPD = 6.4f; // 동공 간 거리 (cm)
	float LensShift = 0.0f;
	
	float DistortionStrength = 1.0f;
	float PrevDistortionStrength = 1.0f;

	void UpdateParameters(float InDistortionStrength)
	{
		PrevDistortionStrength = DistortionStrength;
		DistortionStrength = InDistortionStrength;
	}
};
