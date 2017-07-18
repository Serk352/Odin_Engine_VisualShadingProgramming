#include "OESwapChain.h"
#include "OEGraphicsAPI.h"
#include <d3d11.h>


namespace OE_SDK
{

	struct C_SwapChain::SwapChainData
	{
		IDXGISwapChain* m_pObject;
	};

	C_SwapChain::C_SwapChain()
	{
		m_SwapChain = new SwapChainData;
		m_SwapChain->m_pObject = nullptr;
	}

	C_SwapChain::~C_SwapChain()
	{
		delete m_SwapChain;
	}


	void C_SwapChain::Create(void* scrHandle, uint32 width, uint32 height)
	{
		DXGI_MODE_DESC bufferDesc;

		ZeroMemory(&bufferDesc, sizeof(DXGI_MODE_DESC));

		//Se rellena la estructura del descriptor
		bufferDesc.Width = width;
		bufferDesc.Height = height;
		bufferDesc.RefreshRate.Numerator = 60;
		bufferDesc.RefreshRate.Denominator = 1;
		bufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
		bufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
		bufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;

		DXGI_SWAP_CHAIN_DESC swapChainDesc;

		ZeroMemory(&swapChainDesc, sizeof(DXGI_SWAP_CHAIN_DESC));

		//Se rellena la estructura del descriptor
		swapChainDesc.BufferDesc = bufferDesc;
		swapChainDesc.SampleDesc.Count = 1;
		swapChainDesc.SampleDesc.Quality = 0;
		swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
		swapChainDesc.BufferCount = 1;
		swapChainDesc.OutputWindow = reinterpret_cast<HWND>(scrHandle);
		swapChainDesc.Windowed = true;
		swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;

		uint32 iFlags = 0;
#if ODIN_ENGINE_DEBUG_MODE
		iFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif 

		ID3D11Device** pDevice = reinterpret_cast<ID3D11Device**>(g_GraphicsAPI().GetDeviceReference());
		ID3D11DeviceContext** pDeviceContext = reinterpret_cast<ID3D11DeviceContext**>(g_GraphicsAPI().GetDeviceContextReference());

		D3D11CreateDeviceAndSwapChain(NULL, D3D_DRIVER_TYPE_HARDWARE, NULL, iFlags,
			NULL, NULL, D3D11_SDK_VERSION, &swapChainDesc, &m_SwapChain->m_pObject,
			pDevice, NULL, pDeviceContext);
	}


	void* C_SwapChain::GetBuffer()
	{
		ID3D11Texture2D* pBackBuffer = nullptr;
		m_SwapChain->m_pObject->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)&pBackBuffer);

		return reinterpret_cast<void*>(pBackBuffer);
	}

	void C_SwapChain::Present()
	{
		m_SwapChain->m_pObject->Present(0, 0);
	}

	void*  C_SwapChain::GetObj()
	{
		return reinterpret_cast<void*>(m_SwapChain->m_pObject);
	}
	void** C_SwapChain::GetReference()
	{
		return reinterpret_cast<void**>(&m_SwapChain->m_pObject);
	}
}