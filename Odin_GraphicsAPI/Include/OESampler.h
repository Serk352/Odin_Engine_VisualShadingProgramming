#pragma once
#include "OEPrerequisitesGraphics.h"
#include "OEDevice.h"
#include "OEDeviceContext.h"
#include "OEFormats.h"

namespace OE_SDK
{
	class ODIN_ENGINE_GRAPHICS_API_UTILITY_EXPORT OESampler
	{
	public:
		OESampler();
		~OESampler();

		
		void CreateSamplerState(nSamplingFilters::eSamplingFilter prmFilter,
								nTextureAddresModes::eTextureAddresMode prmU,
								nTextureAddresModes::eTextureAddresMode prmV, 
								nTextureAddresModes::eTextureAddresMode prmW,
								nComparisonFunctions::eComparisonFunc prmCompFunc);

		void SetForVertexShader(unsigned int  StartSlot, 
								unsigned int NumSamplers);
		void SetForPixelShader(unsigned int StartSlot,
							   unsigned int NumSamplers);

		void* GetObj();
		void** GetReference();

	protected:
		struct SamplerData;
		SamplerData* m_Sampler;
	};
}
