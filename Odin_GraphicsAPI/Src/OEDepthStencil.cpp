#include "OEDepthStencil.h"
#include "OEGraphicsAPI.h"
#include <d3d11.h>

namespace OE_SDK
{

	struct  OEDepthStencil::DepthStencilData
	{
		ID3D11DepthStencilView* m_pObject;
		ID3D11Texture2D* m_pTexture;

		DepthStencilData()
		{
			m_pObject = nullptr;
			m_pTexture = nullptr;
		}
	};

	OEDepthStencil::OEDepthStencil()
	{
		m_DepthStencil = new DepthStencilData;
	}

	OEDepthStencil::~OEDepthStencil()
	{
		delete m_DepthStencil;
	}


	void OEDepthStencil::Create(uint32 width, uint32 height)
	{
		ID3D11Device* pDevice = reinterpret_cast<ID3D11Device*>(g_GraphicsAPI().GetDevice());
		
		D3D11_TEXTURE2D_DESC DescDepth;
		memset(&DescDepth, 0, sizeof(D3D11_TEXTURE2D_DESC));
		DescDepth.Width = width;
		DescDepth.Height = height;
		DescDepth.MipLevels = 1;
		DescDepth.ArraySize = 1;
		DescDepth.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
		DescDepth.SampleDesc.Count = 1;
		DescDepth.SampleDesc.Quality = 0;
		DescDepth.Usage = D3D11_USAGE_DEFAULT;
		DescDepth.BindFlags = D3D11_BIND_DEPTH_STENCIL;
		DescDepth.CPUAccessFlags = 0;
		DescDepth.MiscFlags = 0;


		D3D11_DEPTH_STENCIL_VIEW_DESC VDesc;
		memset(&VDesc, 0, sizeof(D3D11_DEPTH_STENCIL_VIEW_DESC));
		VDesc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
		VDesc.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2D;
		VDesc.Flags = 0;
		VDesc.Texture2D.MipSlice = 0;

		pDevice->CreateTexture2D(&DescDepth, NULL, &m_DepthStencil->m_pTexture);

		pDevice->CreateDepthStencilView(m_DepthStencil->m_pTexture, &VDesc, &m_DepthStencil->m_pObject );

	}

	void OEDepthStencil::Set()
	{

	}


	void OEDepthStencil::Clear()
	{
		ID3D11DeviceContext* pDeviceContext = reinterpret_cast<ID3D11DeviceContext*>(g_GraphicsAPI().GetDeviceContext());

		pDeviceContext->ClearDepthStencilView(m_DepthStencil->m_pObject, D3D11_CLEAR_DEPTH, 1.0f, 0);
	}


	void* OEDepthStencil::GetObj()
	{
		return reinterpret_cast<void*>(m_DepthStencil->m_pObject);
	}

	void** OEDepthStencil::GetReference()
	{
		return reinterpret_cast<void**>(&m_DepthStencil->m_pObject);
	}

}