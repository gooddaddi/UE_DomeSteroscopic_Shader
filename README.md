# UE Stereo Dome Shader

Unreal Engine 기반의 돔 스테레오스코픽(Stereoscopic) 쉐이더 프로젝트입니다. 대형 돔 스크린이나 VR 환경에서의 입체 렌더링을 위한 글로벌 쉐이더 및 렌더 패스 구현을 포함하고 있습니다.

## 주요 기능
- **Dome Stereoscopic Rendering**: 돔 환경을 위한 고품질 입체 렌더링.
- **Custom Render Pass**: 엔진 렌더 파이프라인에 통합된 커스텀 패스.
- **MRQ Support**: Movie Render Queue를 통한 좌/우안 개별 시퀀스 렌더링.
- **Global Shader**: C++ 기반 글로벌 쉐이더 및 USF 연동.

## 프로젝트 구조
- `Source/`: C++ 소스 코드 (렌더 패스, 장치 구현, 샘플 액터).
- `Shaders/Private/`: `.usf` 글로벌 쉐이더 파일.
- `StereoDomeShd.uproject`: 언리얼 엔진 프로젝트 파일.

## 설치 및 준비
1. 이 저장소를 클론합니다.
2. `.uproject` 파일 우클릭 -> 'Generate Visual Studio project files'.
3. `.sln` 파일을 열어 프로젝트를 빌드합니다.
4. 언리얼 에디터에서 프로젝트를 실행합니다.

## 샘플 예제 사용 방법

이 프로젝트에는 돔 스테레오 환경을 빠르게 테스트해볼 수 있는 `StereoDomeSampleActor`가 포함되어 있습니다.

### 1. 샘플 액터 배치 및 환경 구축
- **액터 검색**: 콘텐츠 브라우저나 액터 배치 패널에서 `StereoDomeSampleActor`를 찾습니다.
- **레벨에 배치**: 액터를 레벨의 중앙(0, 0, 0)에 드래그하여 배치합니다.
- **자동 환경 구축**: 
    - 이 액터는 `BeginPlay` 시점에 자동으로 테스트용 구체(Sphere)들과 조명(Point Light)을 배치합니다.
    - 에디터에서 **Play(심뮬레이션)**를 누르면 카메라 전방에 테스트 환경이 구성되는 것을 확인할 수 있습니다.

### 2. 돔 스테레오 렌더링 확인
- **결과 확인**: 렌더링 된 결과물이 돔 투영 방식(Equirectangular 또는 Fisheye 등 설정된 방식)으로 왜곡되어 출력되는지 확인합니다.
- **스테레오 분리**: 좌/우안의 시점 차이가 정상적으로 발생하는지 체크합니다.

### 3. Movie Render Queue(MRQ) 연동
- **시퀀스 생성**: 레벨 시퀀스를 생성하고 카메라 애니메이션을 추가합니다.
- **렌더 설정**: MRQ 렌더 설정에서 `StereoDomeRenderPass` 관련 설정을 추가합니다. (프로젝트 설정 및 플러그인 확인 필요)
- **배치 렌더링**: 좌안(Left)과 우안(Right) 시퀀스를 각각 또는 동시에 렌더링 하도록 구성합니다.

## 개발 환경
- **Unreal Engine**: 5.5 이상
- **Visual Studio**: 2022

## 라이선스
해당 저장소의 라이선스 정책을 따릅니다.
