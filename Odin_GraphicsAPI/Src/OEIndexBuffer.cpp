#include "OEIndexBuffer.h"
#include "OEGraphicsAPI.h"

#include <d3d11.h>

namespace OE_SDK
{
	template<typename T>
	struct OEIndexBufferTemplate<T>::BufferData
	{
		ID3D11Buffer* m_pObject;
	};
	
	template<typename T>
	OEIndexBufferTemplate<T>::OEIndexBufferTemplate()
	{
		m_Buffer = new BufferData;
		m_Buffer->m_pObject = nullptr;
	}

	template<typename T>
	OEIndexBufferTemplate<T>::~OEIndexBufferTemplate()
	{
		SAFE_DELETE(m_Buffer);
	}

	template<typename T>
	void OEIndexBufferTemplate<T>::Create(int32)
	{
		D3D11_SUBRESOURCE_DATA resourceData;
		memset(&resourceData, 0, sizeof(D3D11_SUBRESOURCE_DATA));

		D3D11_BUFFER_DESC IndexBufferDesc;
		memset(&IndexBufferDesc, 0, sizeof(D3D11_BUFFER_DESC));

		IndexBufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
		IndexBufferDesc.ByteWidth = static_cast<UINT>(sizeof(T) * m_IndexVector.size());
		IndexBufferDesc.CPUAccessFlags = 0;
		IndexBufferDesc.StructureByteStride = 0;
		IndexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
		resourceData.pSysMem = &m_IndexVector[0];
	
		//////////////////////////////////////////////////////////////////////////
		ID3D11Device* pDevice = reinterpret_cast<ID3D11Device*>(g_GraphicsAPI().GetDevice());
		pDevice->CreateBuffer(&IndexBufferDesc, &resourceData, &m_Buffer->m_pObject);
	}

	template<typename T>
	void OEIndexBufferTemplate<T>::SetBuffer(uint32 StartSlot)
	{
		UNREFERENCED_PARAMETER(StartSlot);
		//Log: Debe informar que este formato no est� soportado
	}

	template<>
	void OEIndexBufferTemplate<uint16>::SetBuffer(uint32 StartSlot)
	{
		UNREFERENCED_PARAMETER(StartSlot);
		ID3D11DeviceContext* pDeviceContext = reinterpret_cast<ID3D11DeviceContext*>(g_GraphicsAPI().GetDeviceContext());
		pDeviceContext->IASetIndexBuffer(m_Buffer->m_pObject, DXGI_FORMAT_R16_UINT, 0);
	}

	template<>
	void OEIndexBufferTemplate<uint32>::SetBuffer(uint32 StartSlot)
	{
		UNREFERENCED_PARAMETER(StartSlot);
		ID3D11DeviceContext* pDeviceContext = reinterpret_cast<ID3D11DeviceContext*>(g_GraphicsAPI().GetDeviceContext());
		pDeviceContext->IASetIndexBuffer(m_Buffer->m_pObject, DXGI_FORMAT_R32_UINT, 0);
	}


	template<typename T>
	void OEIndexBufferTemplate<T>::InsertIndex(T prmIndex)
	{
		m_IndexVector.push_back(prmIndex);
	}


	template<typename T>
	void OEIndexBufferTemplate<T>::InsertIndexVector(const Vector<T>& prmIndex)
	{
		m_IndexVector.insert(m_IndexVector.end(), prmIndex.begin(), prmIndex.end());
	}

	template<typename T>
	SIZE_T OEIndexBufferTemplate<T>::GetIndexCount()
	{
		return m_IndexVector.size();
	}

	template class OEIndexBufferTemplate<uint16>;
	template class OEIndexBufferTemplate<uint32>;
}