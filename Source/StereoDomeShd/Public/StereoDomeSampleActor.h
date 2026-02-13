#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "StereoDomeSampleActor.generated.h"

/**
 * 돔 스테레오 테스트를 위한 샘플 환경을 자동으로 구축하는 액터
 */
UCLASS()
class STEREODOMESHD_API AStereoDomeSampleActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AStereoDomeSampleActor();

protected:
	virtual void BeginPlay() override;

public:	
	// 샘플 환경 구축 기능
	UFUNCTION(BlueprintCallable, Category = "StereoDome|Sample")
	void SetupSampleLevel();

	// 시퀀서 자동 생성 기능 (Editor Only 로직 권장되나 런타임 샘플로 작성)
	UFUNCTION(BlueprintCallable, Category = "StereoDome|Sample")
	void CreateSampleSequence();

private:
	UPROPERTY()
	class USceneComponent* Root;
};
