#include "CoreMinimal.h"
#include "GlobalShader.h"
#include "ShaderParameterMacros.h"

class FMyTestVS : public FGlobalShader
{
public:
	DECLARE_GLOBAL_SHADER(FMyTestVS);
	SHADER_USE_PARAMETER_STRUCT(FMyTestVS, FGlobalShader);

	BEGIN_SHADER_PARAMETER_STRUCT(FParameters, )
		SHADER_PARAMETER(FVector4f, MyColor)
	END_SHADER_PARAMETER_STRUCT()

	static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters& Parameters)
	{
		return true;
	}
};

class FMyTestPS : public FGlobalShader
{
public:
	DECLARE_GLOBAL_SHADER(FMyTestPS);
	SHADER_USE_PARAMETER_STRUCT(FMyTestPS, FGlobalShader);

	BEGIN_SHADER_PARAMETER_STRUCT(FParameters, )
		SHADER_PARAMETER(FVector4f, MyColor)
	END_SHADER_PARAMETER_STRUCT()

	static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters& Parameters)
	{
		return true;
	}
};
