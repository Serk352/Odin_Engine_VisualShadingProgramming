#include "OERenderTargetView.h"
#include "OEGraphicsAPI.h"
#include <d3d11.h>

namespace OE_SDK
{
	struct OERenderTargetView::sRenderTargetData
	{
		ID3D11RenderTargetView* m_pObject;

		sRenderTargetData()
		{
			m_pObject  = nullptr;
		}
	};

	OERenderTargetView::OERenderTargetView()
	{
		m_RenderTarget = new sRenderTargetData;
	}

	OERenderTargetView::~OERenderTargetView()
	{
		delete m_RenderTarget;
	}



	void OERenderTargetView::Create(const OETexture2D& prmTexture)
	{
		ID3D11Texture2D* pTexture = reinterpret_cast<ID3D11Texture2D*>(const_cast<OETexture2D&>(prmTexture).GetObj());
		ID3D11Device* pDevice = reinterpret_cast<ID3D11Device*>(g_GraphicsAPI().GetDevice());
		pDevice->CreateRenderTargetView(pTexture, NULL, &m_RenderTarget->m_pObject);
	}

	void* OERenderTargetView::GetObj()
	{
		return reinterpret_cast<void*>(m_RenderTarget->m_pObject);
	}
	void** OERenderTargetView::GetReference()
	{
		return reinterpret_cast<void**>(&m_RenderTarget->m_pObject);
	}


}