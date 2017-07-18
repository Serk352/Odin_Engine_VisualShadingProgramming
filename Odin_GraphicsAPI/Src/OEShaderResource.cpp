#include "OEShaderResource.h"
#include "OEGraphicsAPI.h"
#include <d3d11.h>
#include "OEFormats.h"

namespace OE_SDK
{

	struct C_ShaderResource::ResourceData
	{
		ID3D11ShaderResourceView* m_pObject;
	};


	C_ShaderResource::C_ShaderResource()
	{
		m_Resource = new ResourceData;
		m_Resource->m_pObject = nullptr;
	}


	C_ShaderResource::~C_ShaderResource()
	{
		delete m_Resource;
	}

	


	void C_ShaderResource::Create(C_Texture2D Resource,
								  int MipLevels, 
								  int MDMipMap)
	{

		ID3D11Texture2D* Temp;

		Temp = reinterpret_cast<ID3D11Texture2D*>(Resource.GetObj());

		D3D11_SHADER_RESOURCE_VIEW_DESC Desc;
		memset(&Desc, 0, sizeof(D3D11_SHADER_RESOURCE_VIEW_DESC));
		Desc.Texture2D.MipLevels = MipLevels;
		Desc.Texture2D.MostDetailedMip = MDMipMap;
		Desc.Format = nFormats::TranslateFormat(Resource.m_Format);
		Desc.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;

		//////////////////////////////////////////////////////////////////////////
		ID3D11Device* pDevice = reinterpret_cast<ID3D11Device*>(g_GraphicsAPI().GetDevice());
		pDevice->CreateShaderResourceView(Temp, &Desc, &m_Resource->m_pObject);

	}


	void C_ShaderResource::SetForPixelShader(unsigned int prmStartSlot, 
											 unsigned int prmNumViews)
	{
		ID3D11DeviceContext* pDeviceContext = 
			reinterpret_cast<ID3D11DeviceContext*>(g_GraphicsAPI().GetDeviceContext());

		pDeviceContext->PSSetShaderResources(prmStartSlot, 
											 prmNumViews, 
											 &m_Resource->m_pObject);
		
	}



	void C_ShaderResource::SetForVertexShader(unsigned int prmStartSlot,
											  unsigned int prmNumViews)
	{
		ID3D11DeviceContext* pDeviceContext =
			reinterpret_cast<ID3D11DeviceContext*>(g_GraphicsAPI().GetDeviceContext());

		pDeviceContext->VSSetShaderResources(prmStartSlot,
			prmNumViews,
			&m_Resource->m_pObject);

	}


	//Puntero es para usarla
	//La refenrencia es para modificarla

}

