#include "MyShaderDeclaration.h"
#include "ShaderParameterUtils.h"

IMPLEMENT_GLOBAL_SHADER(FMyTestVS, "/Project/Private/MyShader.usf", "MainVS", SF_Vertex);
IMPLEMENT_GLOBAL_SHADER(FMyTestPS, "/Project/Private/MyShader.usf", "MainPS", SF_Pixel);
