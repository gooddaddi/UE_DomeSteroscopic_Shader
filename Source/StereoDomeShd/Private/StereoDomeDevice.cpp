#include "StereoDomeDevice.h"

FStereoDomeDevice::FStereoDomeDevice()
{
}

void FStereoDomeDevice::AdjustViewRect(int32 ViewIndex, int32& X, int32& Y, uint32& SizeX, uint32& SizeY) const
{
	// 가로로 절반씩 나누어 렌더링 (Side-by-Side 기준)
	SizeX = SizeX / 2;
	if (ViewIndex > 0)
	{
		X += SizeX;
	}
}

void FStereoDomeDevice::CalculateStereoViewOffset(const int32 ViewIndex, FRotator& ViewRotation, const float WorldToMeters, FVector& ViewLocation)
{
	// 좌우안 위치 오프셋 계산 (IPD 적용)
	float PassOffset = (ViewIndex == 0) ? -IPD * 0.5f : IPD * 0.5f;
	ViewLocation += ViewRotation.Quaternion().RotateVector(FVector(0, PassOffset, 0));
}

FMatrix FStereoDomeDevice::GetStereoProjectionMatrix(const int32 ViewIndex) const
{
	// 비대칭 투사 행렬(Off-Axis) 계산
	// 기본 원근 투사 행렬을 베이스로 수평 시프트 적용
	float Left, Right, Top, Bottom;
	float ZNear = 10.0f;
	
	// 가이드 문서의 Off-Axis 수식 적용 (단순화된 예시)
	float Offset = (ViewIndex == 0) ? LensShift : -LensShift;
	
	// 비대칭 절두체(Frustum) 설정
	Left = -ZNear * FMath::Tan(FMath::DegreesToRadians(45.0f)) + Offset;
	Right = ZNear * FMath::Tan(FMath::DegreesToRadians(45.0f)) + Offset;
	Top = ZNear * FMath::Tan(FMath::DegreesToRadians(45.0f));
	Bottom = -ZNear * FMath::Tan(FMath::DegreesToRadians(45.0f));

	return FReversedZPerspectiveMatrix(
		Left, Right, Bottom, Top, ZNear, ZNear
	);
}
