#include "OESampler.h"
#include "OEGraphicsAPI.h"

#include <d3d11.h>

namespace OE_SDK
{
	struct C_Sampler::SamplerData
	{
		ID3D11SamplerState* pObject;
	};

	C_Sampler::C_Sampler()
	{
		m_Sampler = new SamplerData;
		m_Sampler->pObject = nullptr;
	}

	C_Sampler::~C_Sampler()
	{
		SAFE_DELETE(m_Sampler);
	}


	//////////////////////////////////////////////////////////////////////////

	void C_Sampler::CreateSamplerState(nSamplingFilters::eSamplingFilter prmFilter,
									   nTextureAddresModes::eTextureAddresMode prmU,
									   nTextureAddresModes::eTextureAddresMode prmV,
									   nTextureAddresModes::eTextureAddresMode prmW,
									   nComparisonFunctions::eComparisonFunc  prmCompFunc)
	{

		D3D11_SAMPLER_DESC SamplerDesc;
		memset(&SamplerDesc, 0, sizeof(D3D11_SAMPLER_DESC));
		SamplerDesc.Filter = nSamplingFilters::TranslateFilter(prmFilter);
		SamplerDesc.AddressU = nTextureAddresModes::TranslateTextureAddressMode(prmU);
		SamplerDesc.AddressV = nTextureAddresModes::TranslateTextureAddressMode(prmV);
		SamplerDesc.AddressW = nTextureAddresModes::TranslateTextureAddressMode(prmW);
		SamplerDesc.ComparisonFunc = nComparisonFunctions::TranslateComparisonFunc(prmCompFunc);
		SamplerDesc.MinLOD = -FLT_MAX;
		SamplerDesc.MaxLOD = FLT_MAX;
		SamplerDesc.MaxAnisotropy = 1;
		SamplerDesc.MipLODBias = 0.0f;

		//////////////////////////////////////////////////////////////////////////
		ID3D11Device* pDevice = reinterpret_cast<ID3D11Device*>(g_GraphicsAPI().GetDevice());
		pDevice->CreateSamplerState(&SamplerDesc, &m_Sampler->pObject);

	}

	void C_Sampler::SetForVertexShader(unsigned int StartSlot, 
									   unsigned int NumSamplers)
	{

		ID3D11DeviceContext* pDeviceContext = 
				reinterpret_cast<ID3D11DeviceContext*> (g_GraphicsAPI().GetDeviceContext());

		pDeviceContext->VSSetSamplers(StartSlot,
									  NumSamplers, 
									  &m_Sampler->pObject);
	}

	void C_Sampler::SetForPixelShader(unsigned int StartSlot,
									  unsigned int NumSamplers)
	{

		ID3D11DeviceContext* pDeviceContext =
				reinterpret_cast<ID3D11DeviceContext*>(g_GraphicsAPI().GetDeviceContext());
		
		pDeviceContext->PSSetSamplers(StartSlot, 
									  NumSamplers, 
									  &m_Sampler->pObject);
	}


	void* C_Sampler::GetObj()
	{
		return reinterpret_cast<void*>(m_Sampler->pObject);
	}


	void** C_Sampler::GetReference()
	{
		return reinterpret_cast<void**>(&m_Sampler->pObject);
	}

}