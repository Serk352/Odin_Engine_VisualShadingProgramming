#include "OEDevice.h"
#	include "d3d11.h"



namespace OE_SDK
{

	struct GraphicsDevice::DeviceData
	{
		ID3D11Device* pObject;
	};


	GraphicsDevice::GraphicsDevice()
	{
		m_Device = new DeviceData;
		m_Device->pObject = nullptr;
	}

	GraphicsDevice::~GraphicsDevice()
	{
		SAFE_DELETE(m_Device);
	}


	
	void* GraphicsDevice::GetObj()
	{
		return reinterpret_cast<void*>(m_Device->pObject);
	}

	void** GraphicsDevice::GetReference()
	{
		return reinterpret_cast<void**>(&m_Device->pObject);
	}
}