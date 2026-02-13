# UE Stereo Dome Shader

Unreal Engine 기반의 돔 스테레오스코픽(Stereoscopic) 쉐이더 프로젝트입니다. 대형 돔 스크린이나 VR 환경에서의 입체 렌더링을 위한 글로벌 쉐이더 및 렌더 패스 구현을 포함하고 있습니다.

## 주요 기능
- **Dome Stereoscopic Rendering**: 180도/360도 돔 환경을 위한 입체 렌더링 지원.
- **Custom Render Pass**: Unreal Engine의 렌더링 파이프라인에 통합된 커스텀 렌더 패스.
- **Left/Right Eye Sequence**: Movie Render Queue(MRQ)를 통한 좌측/우측 안구 시퀀스 별도 렌더링 지원.
- **Global Shader**: C++를 통한 글로벌 쉐이더 구현 및 USF 쉐이더 연동.

## 프로젝트 구조
- `Source/`: C++ 소스 코드 (렌더 패스 및 쉐이더 선언 등).
- `Shaders/Private/`: `.usf` 쉐이더 파일.
- `StereoDomeShd.uproject`: 언리얼 엔진 프로젝트 파일.

## 설치 및 실행 방법
1. 이 저장소를 클론합니다.
2. `.uproject` 파일을 우클릭하여 'Generate Visual Studio project files'를 선택합니다.
3. 생성된 `.sln` 파일을 열어 프로젝트를 빌드합니다.
4. 언리얼 에디터에서 프로젝트를 실행하고 `StereoDomeSampleActor`를 배치하여 기능을 확인합니다.

## 개발 환경
- **Unreal Engine**: 5.5 이상
- **Visual Studio**: 2022 기반

## 라이선스
이 프로젝트의 라이선스는 해당 저장소의 설정을 따릅니다.
