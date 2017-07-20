#include "OEDevice.h"
#	include "d3d11.h"



namespace OE_SDK
{

	struct OEGraphicsDevice::DeviceData
	{
		ID3D11Device* pObject;
	};


	OEGraphicsDevice::OEGraphicsDevice()
	{
		m_Device = new DeviceData;
		m_Device->pObject = nullptr;
	}

	OEGraphicsDevice::~OEGraphicsDevice()
	{
		SAFE_DELETE(m_Device);
	}


	
	void* OEGraphicsDevice::GetObj()
	{
		return reinterpret_cast<void*>(m_Device->pObject);
	}

	void** OEGraphicsDevice::GetReference()
	{
		return reinterpret_cast<void**>(&m_Device->pObject);
	}
}