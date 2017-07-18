#include "OERenderTargetView.h"
#include "OEGraphicsAPI.h"
#include <d3d11.h>

namespace OE_SDK
{
	struct C_RenderTargetView::sRenderTargetData
	{
		ID3D11RenderTargetView* m_pObject;

		sRenderTargetData()
		{
			m_pObject  = nullptr;
		}
	};

	C_RenderTargetView::C_RenderTargetView()
	{
		m_RenderTarget = new sRenderTargetData;
	}

	C_RenderTargetView::~C_RenderTargetView()
	{
		delete m_RenderTarget;
	}



	void C_RenderTargetView::Create(const C_Texture2D& prmTexture)
	{
		ID3D11Texture2D* pTexture = reinterpret_cast<ID3D11Texture2D*>(const_cast<C_Texture2D&>(prmTexture).GetObj());
		ID3D11Device* pDevice = reinterpret_cast<ID3D11Device*>(g_GraphicsAPI().GetDevice());
		pDevice->CreateRenderTargetView(pTexture, NULL, &m_RenderTarget->m_pObject);
	}

	void* C_RenderTargetView::GetObj()
	{
		return reinterpret_cast<void*>(m_RenderTarget->m_pObject);
	}
	void** C_RenderTargetView::GetReference()
	{
		return reinterpret_cast<void**>(&m_RenderTarget->m_pObject);
	}


}