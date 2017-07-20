#include "OEDeviceContext.h"
#include <d3d11.h>

namespace OE_SDK
{

	struct OEGraphicsDeviceContext::DeviceContextData	
	{
		ID3D11DeviceContext* m_pObj;
	};

	OEGraphicsDeviceContext::OEGraphicsDeviceContext()
	{
		m_DeviceContext = new DeviceContextData;
		m_DeviceContext->m_pObj = nullptr;
	}


	OEGraphicsDeviceContext::~OEGraphicsDeviceContext()
	{
		SAFE_DELETE(m_DeviceContext);
	}




	void* OEGraphicsDeviceContext::GetObj()
	{
		return reinterpret_cast<void*> (m_DeviceContext->m_pObj);
	}

	void** OEGraphicsDeviceContext::GetReference()
	{
		return reinterpret_cast<void**>(&m_DeviceContext->m_pObj); 
	}

}