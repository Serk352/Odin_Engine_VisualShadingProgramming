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
		ID3D11DeviceContext* pDeviceContext = reinterpret_cast<ID3D11DeviceContext*>(g_GraphicsAPI().GetDeviceContext());

		D3D11_RASTERIZER_DESC m_RasterDesc;


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

		D3D11_DEPTH_STENCIL_DESC DStencilStateDes;
		ZeroMemory(&DStencilStateDes, sizeof(DStencilStateDes));

		// Set up the description of the stencil state.
		DStencilStateDes.DepthEnable = true;
		DStencilStateDes.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ALL;
		DStencilStateDes.DepthFunc = D3D11_COMPARISON_LESS;

		DStencilStateDes.StencilEnable = true;
		DStencilStateDes.StencilReadMask = 0xFF;
		DStencilStateDes.StencilWriteMask = 0xFF;

	
		// Stencil operations if pixel is front-facing.
		DStencilStateDes.FrontFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
		DStencilStateDes.FrontFace.StencilDepthFailOp = D3D11_STENCIL_OP_INCR;
		DStencilStateDes.FrontFace.StencilPassOp = D3D11_STENCIL_OP_KEEP;
		DStencilStateDes.FrontFace.StencilFunc = D3D11_COMPARISON_ALWAYS;

		// Stencil operations if pixel is back-facing.
		DStencilStateDes.BackFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
		DStencilStateDes.BackFace.StencilDepthFailOp = D3D11_STENCIL_OP_DECR;
		DStencilStateDes.BackFace.StencilPassOp = D3D11_STENCIL_OP_KEEP;
		DStencilStateDes.BackFace.StencilFunc = D3D11_COMPARISON_ALWAYS;


		ID3D11DepthStencilState* m_DepthStencilState;

		pDevice->CreateDepthStencilState(&DStencilStateDes, &m_DepthStencilState);

		D3D11_DEPTH_STENCIL_VIEW_DESC VDesc;
		memset(&VDesc, 0, sizeof(D3D11_DEPTH_STENCIL_VIEW_DESC));
		VDesc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
		VDesc.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2D;
		VDesc.Flags = 0;
		VDesc.Texture2D.MipSlice = 0;

		pDevice->CreateTexture2D(&DescDepth, NULL, &m_DepthStencil->m_pTexture);


		pDevice->CreateDepthStencilState(&DStencilStateDes, &m_DepthStencilState);


		pDeviceContext->OMSetDepthStencilState(m_DepthStencilState, 1);


		pDevice->CreateDepthStencilView(m_DepthStencil->m_pTexture, &VDesc, &m_DepthStencil->m_pObject );


		ID3D11RasterizerState* m_rasterState;
		D3D11_RASTERIZER_DESC rasterDesc;

		rasterDesc.AntialiasedLineEnable = false;
		rasterDesc.CullMode = D3D11_CULL_BACK;
		rasterDesc.DepthBias = 0;
		rasterDesc.DepthBiasClamp = 0.0f;
		rasterDesc.DepthClipEnable = true;
		rasterDesc.FillMode = D3D11_FILL_SOLID;
		rasterDesc.FrontCounterClockwise = false;
		rasterDesc.MultisampleEnable = false;
		rasterDesc.ScissorEnable = false;
		rasterDesc.SlopeScaledDepthBias = 0.0f;

		pDevice->CreateRasterizerState(&rasterDesc, &m_rasterState);
		pDeviceContext->RSSetState(m_rasterState);

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