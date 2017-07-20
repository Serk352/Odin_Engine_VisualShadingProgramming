#include "OEGraphicsAPI.h"

#include "OEDevice.h"
#include "OEDeviceContext.h"
#include "OESwapChain.h"

#include "Matrix3.h"
#include "Matrix4.h"
#include "Vector3f.h"


#include "OETexture2D.h"



namespace OE_SDK
{


	struct OEGraphicsAPI::ApiData
	{
		HWND					   m_Hwnd;
		ID3D11RenderTargetView*    m_RenderTargetView;
		ID3D11ShaderResourceView*  m_ShaderResourceView;
		D3D11_VIEWPORT*			   m_viewports;
		OEDepthStencil			  m_DepthStencil;
		OESwapChain					m_SwapChain;


		OEGraphicsDeviceContext   m_DeviceContext;
		OEGraphicsDevice	m_Device;

		ApiData()
		{
			m_Hwnd = 0;
			m_RenderTargetView = nullptr;
		}

	};


	OEGraphicsAPI::OEGraphicsAPI()
	{
		m_APIData = new ApiData;
	}


	OEGraphicsAPI::~OEGraphicsAPI()
	{
		CleanUp();
	}






	//Iniciar DirectX
	void OEGraphicsAPI::Init(void* scrHandle,
		uint32 width,
		uint32 height,
		bool fullscreen)
	{
		UNREFERENCED_PARAMETER(fullscreen);

		HRESULT res = S_OK;
		
		m_Width = width;
		m_Height = height;

		ID3D11Device** pDevice = reinterpret_cast<ID3D11Device**>(m_APIData->m_Device.GetReference());
		ID3D11DeviceContext** pDeviceContext = reinterpret_cast<ID3D11DeviceContext**>(m_APIData->m_DeviceContext.GetReference());

		m_APIData->m_SwapChain.Create(scrHandle, width, height);
		//////////////////////////////////////////////////////////////////////////
		//Create Render Target

		ID3D11Texture2D* pBackBuffer = reinterpret_cast<ID3D11Texture2D*>(m_APIData->m_SwapChain.GetBuffer());

				res = (*pDevice)->CreateRenderTargetView(pBackBuffer, NULL, &m_APIData->m_RenderTargetView);


		m_APIData->m_DepthStencil.Create(width, height);
	
		//Setear el render target
		ID3D11DepthStencilView* pDepthStencil = reinterpret_cast<ID3D11DepthStencilView*>(m_APIData->m_DepthStencil.GetObj());
		(*pDeviceContext)->OMSetRenderTargets(1, &m_APIData->m_RenderTargetView, pDepthStencil);




		//////////////////////////////////////////////////////////////////////////
		//Crear viewport
		m_APIData->m_viewports = new D3D11_VIEWPORT[2];
		ZeroMemory(m_APIData->m_viewports, sizeof(D3D11_VIEWPORT) * 2);

		m_APIData->m_viewports[0].TopLeftX = 0;
		m_APIData->m_viewports[0].TopLeftY = 0;
		m_APIData->m_viewports[0].Width = static_cast<float>(width);//width>>1;
		m_APIData->m_viewports[0].Height = static_cast<float>(height);//height>>1;
		m_APIData->m_viewports[0].MinDepth = 0.0f;
		m_APIData->m_viewports[0].MaxDepth = 1.0f;

		m_APIData->m_viewports[1].TopLeftX = static_cast<float>(width >> 1);
		m_APIData->m_viewports[1].TopLeftY = static_cast<float>(height >> 1);
		m_APIData->m_viewports[1].Width =  static_cast<float>(width >> 1);
		m_APIData->m_viewports[1].Height = static_cast<float>(height >> 1);
		m_APIData->m_viewports[1].MinDepth = 0.0f;
		m_APIData->m_viewports[1].MaxDepth = 1.0f;

		(*pDeviceContext)->RSSetViewports(2, m_APIData->m_viewports);
	

	}

	
	//Todas los parametros de una función deben ser referencias por que no quiero que haga una copia del objeto que recibo, quiero el objeto tal cual, y lo
	//pongo como un constante porque no quiero que cambie los valores, si quiero que los cambie son referencias pero no constantes

	//Una función marcada como constante asegura que no cambiara el valor de la clase en la que existe.
	//Que sea constante es que no puede modificarse
	//Static es  decirle que esuna función global



	void OEGraphicsAPI::SetRenderTargets(const OE_SDK::Vector<OERenderTargetView*>& prmRendertargetsViews, const OEDepthStencil& prmDepthStencil)
	{
		ID3D11DeviceContext* pDeviceContext = NULL; //reinterpret_cast<ID3D11DeviceContext*>(m_APIData->m_DeviceContext.GetObj());
		
		Vector<ID3D11RenderTargetView*> TargetsViews;
		for (int i = 0; i<prmRendertargetsViews.size(); ++i)
		{
			ID3D11RenderTargetView* ActualView = reinterpret_cast<ID3D11RenderTargetView*>( const_cast<Vector<OERenderTargetView*>&>(prmRendertargetsViews)[i]->GetObj() );
			TargetsViews.push_back(ActualView);
		}
//////////////////////////////////////////////////////////////////////////
		ID3D11DepthStencilView* pDepthStencil = reinterpret_cast<ID3D11DepthStencilView*>(const_cast<OEDepthStencil&>(prmDepthStencil).GetObj());
		pDeviceContext->OMGetRenderTargets(static_cast<UINT>(prmRendertargetsViews.size()), &TargetsViews[0], &pDepthStencil);

	}


	//Liberar los punteros
	void OEGraphicsAPI::CleanUp()
	{
		if (m_APIData) {
			//SAFE_RELEASE(m_APIData->m_SwapChain);
			SAFE_RELEASE(m_APIData->m_RenderTargetView);
			//SAFE_RELEASE(m_APIData->m_DeviceContext.pDeviceContext);
			SAFE_DELETE(m_APIData);
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void* OEGraphicsAPI::GetDevice()
	{
		return m_APIData->m_Device.GetObj();
	}


	void** OEGraphicsAPI::GetDeviceReference()
	{
		return m_APIData->m_Device.GetReference();
	}

	//////////////////////////////////////////////////////////////////////////
	void* OEGraphicsAPI::GetDeviceContext()
	{
		return m_APIData->m_DeviceContext.GetObj();
	}


	void** OEGraphicsAPI::GetDeviceContextReference()
	{
		return m_APIData->m_DeviceContext.GetReference();
	}

	//////////////////////////////////////////////////////////////////////////
	void* OEGraphicsAPI::GetSwapChainObject()
	{

		return m_APIData->m_SwapChain.GetObj();
	}

	void** OEGraphicsAPI::GetSwapChainReference()
	{
		return m_APIData->m_SwapChain.GetReference();
	}

	void OEGraphicsAPI::PresentSwapChain()
	{
		m_APIData->m_SwapChain.Present();
	}
//////////////////////////////////////////////////////////////////////////

	void* OEGraphicsAPI::GetRenderTargetViewObject()
	{
		return reinterpret_cast<void*> (m_APIData->m_RenderTargetView);
	}

	void** OEGraphicsAPI::GetRenderTargetViewReference()
	{
		return reinterpret_cast<void**> (&m_APIData->m_RenderTargetView);
	}

//////////////////////////////////////////////////////////////////////////
	void* OEGraphicsAPI::GetShaderResourceViewnObject()
	{

		return reinterpret_cast<void*> (m_APIData->m_ShaderResourceView);
	}

	void** OEGraphicsAPI::GetShaderResourceViewReference()
	{
		return reinterpret_cast<void**> (&m_APIData->m_ShaderResourceView);
	}
//////////////////////////////////////////////////////////////////////////

	void* OEGraphicsAPI::GetDepthStencilViewObject()
	{

		return m_APIData->m_DepthStencil.GetObj();
	}

	void** OEGraphicsAPI::GetDepthStencilViewReference()
	{
		return m_APIData->m_DepthStencil.GetReference();
	}

	void OEGraphicsAPI::ClearDepthStencil()
	{
		m_APIData->m_DepthStencil.Clear();
	}
//////////////////////////////////////////////////////////////////////////
	
	void* OEGraphicsAPI::GetViewPortObject()
	{

		return reinterpret_cast<void*> (m_APIData->m_viewports);
	}

	void** OEGraphicsAPI::GetViewPortReference()
	{
		return reinterpret_cast<void**> (&m_APIData->m_viewports);
	}
//////////////////////////////////////////////////////////////////////////

	ODIN_ENGINE_GRAPHICS_API_UTILITY_EXPORT OEGraphicsAPI & g_GraphicsAPI()
	{
		return OEGraphicsAPI::instance();
	}

}

