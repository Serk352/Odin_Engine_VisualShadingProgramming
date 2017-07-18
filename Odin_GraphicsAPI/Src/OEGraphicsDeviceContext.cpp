#include "OEGraphicsDeviceContext.h"
#include <d3d11.h>

namespace OE_SDK
{

	struct GraphicsDeviceContext::DeviceContextData	
	{
		ID3D11DeviceContext* m_pObj;
	};

	GraphicsDeviceContext::GraphicsDeviceContext()
	{
		m_DeviceContext = new DeviceContextData;
		m_DeviceContext->m_pObj = nullptr;
	}


	GraphicsDeviceContext::~GraphicsDeviceContext()
	{
		SAFE_DELETE(m_DeviceContext);
	}




	void* GraphicsDeviceContext::GetObj()
	{
		return reinterpret_cast<void*> (m_DeviceContext->m_pObj);
	}

	void** GraphicsDeviceContext::GetReference()
	{
		return reinterpret_cast<void**>(&m_DeviceContext->m_pObj); 
	}

}