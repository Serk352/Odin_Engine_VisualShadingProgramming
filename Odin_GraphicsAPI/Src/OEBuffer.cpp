#include "OEBuffer.h"
#include "OEGraphicsAPI.h"

#include "d3d11.h"

namespace OE_SDK
{

	struct C_Buffer::BufferData
	{
		ID3D11Buffer* pObject;
	};


	C_Buffer::C_Buffer()
	{
		m_Buffer = new BufferData;
		m_Buffer->pObject = nullptr;
	}

	C_Buffer::~C_Buffer()
	{
		SAFE_DELETE(m_Buffer);
	}

	void C_Buffer::Create(void* prmData, SIZE_T ByteSize)
	{
		D3D11_BUFFER_DESC BufDesc;
		ZeroMemory(&BufDesc, sizeof(D3D11_BUFFER_DESC));
		BufDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
		BufDesc.ByteWidth = static_cast<uint32>(ByteSize);
		BufDesc.Usage = D3D11_USAGE_DEFAULT;

		HRESULT hr;

		ID3D11Device* pDevice = reinterpret_cast<ID3D11Device*>(g_GraphicsAPI().GetDevice());
		if (prmData != NULL)
		{
			D3D11_SUBRESOURCE_DATA Data;
			Data.pSysMem = prmData;
			Data.SysMemPitch = static_cast<uint32>(ByteSize);
			Data.SysMemSlicePitch = 0;

			hr = pDevice->CreateBuffer(&BufDesc, &Data, &m_Buffer->pObject);
		}
		else
		{
			hr = pDevice->CreateBuffer(&BufDesc, NULL, &m_Buffer->pObject);
		}		
	}


	void C_Buffer::SetData(const void* pData, uint32 ByteSize)
	{
		ID3D11DeviceContext* pDeviceContext = 
			reinterpret_cast<ID3D11DeviceContext*>(g_GraphicsAPI().GetDeviceContext());
		
		pDeviceContext->UpdateSubresource(m_Buffer->pObject, 
										  0, 
										  NULL, 
										  pData, 
										  ByteSize,
										  0);
	}

	void C_Buffer::SetForPixelSahder(unsigned int StartSlot)
	{
		ID3D11DeviceContext* pDeviceContext = reinterpret_cast<ID3D11DeviceContext*>(g_GraphicsAPI().GetDeviceContext());

		pDeviceContext->PSSetConstantBuffers(StartSlot, 1, &m_Buffer->pObject);
	}

	void C_Buffer::SetForVertexShader(unsigned int StartSlot)
	{
		ID3D11DeviceContext* pDeviceContext = reinterpret_cast<ID3D11DeviceContext*>(g_GraphicsAPI().GetDeviceContext());

		pDeviceContext->VSSetConstantBuffers(StartSlot, 1, &m_Buffer->pObject);
	}


	
	void* C_Buffer::GetObj()
	{
		return reinterpret_cast<void*> (m_Buffer->pObject);
	}

	void** C_Buffer::GetReference()
	{
		return reinterpret_cast<void**> (&m_Buffer->pObject);
	}
	

}