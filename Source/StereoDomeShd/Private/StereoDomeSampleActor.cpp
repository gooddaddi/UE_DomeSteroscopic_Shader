#include "StereoDomeSampleActor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/PointLightComponent.h"
#include "Engine/StaticMesh.h"
#include "UObject/ConstructorHelpers.h"

AStereoDomeSampleActor::AStereoDomeSampleActor()
{
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;
}

void AStereoDomeSampleActor::BeginPlay()
{
	Super::BeginPlay();
	
	// 게임 시작 시 자동으로 샘플 환경을 구성합니다.
	SetupSampleLevel();
}

void AStereoDomeSampleActor::SetupSampleLevel()
{
	// 1. 테스트용 기본 구체(Sphere)들 배치
	for (int32 i = 0; i < 5; ++i)
	{
		AActor* SphereActor = GetWorld()->SpawnActor<AActor>();
		if (SphereActor)
		{
			UStaticMeshComponent* MeshComp = NewObject<UStaticMeshComponent>(SphereActor);
			MeshComp->RegisterComponent();
			SphereActor->SetRootComponent(MeshComp);
			
			// 엔진 기본 에셋 참조 (실제 프로젝트에서는 경로 확인 필요)
			static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereMesh(TEXT("/Engine/BasicShapes/Sphere"));
			if (SphereMesh.Succeeded())
			{
				MeshComp->SetStaticMesh(SphereMesh.Object);
			}

			FVector Location(1000.0f, (i - 2) * 400.0f, 200.0f);
			SphereActor->SetActorLocation(Location);
		}
	}

	// 2. 조명(Point Light) 배치
	AActor* LightActor = GetWorld()->SpawnActor<AActor>();
	if (LightActor)
	{
		UPointLightComponent* LightComp = NewObject<UPointLightComponent>(LightActor);
		LightComp->RegisterComponent();
		LightActor->SetRootComponent(LightComp);
		LightActor->SetActorLocation(FVector(500.0f, 0, 500.0f));
		LightComp->Intensity = 5000.0f;
	}
}

void AStereoDomeSampleActor::CreateSampleSequence()
{
	// 시퀀서 에셋 생성 및 카메라 애니메이션 추가 로직 (생략된 개념적 구현)
	// LevelSequence 에셋 생성을 위해서는 LevelSequenceEditor 모듈 필요
}
