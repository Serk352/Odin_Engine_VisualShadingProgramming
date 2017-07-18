#include "OEAnimationVertexBuffer.h"
#include <d3d11.h>

namespace OE_SDK
{
	struct C_AnimationVertexBuffer::BufferData
	{
		ID3D11Buffer* m_pObject;
	};

	void  C_AnimationVertexBuffer::Create(GraphicsDevice* prmDevice, int32 flags)
	{
		UNREFERENCED_PARAMETER(flags);

		D3D11_SUBRESOURCE_DATA resourceData;
		memset(&resourceData, 0, sizeof(D3D11_SUBRESOURCE_DATA));

		D3D11_BUFFER_DESC VertexBufferDesc;
		memset(&VertexBufferDesc, 0, sizeof(D3D11_BUFFER_DESC));
		
		VertexBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
		VertexBufferDesc.ByteWidth = static_cast<UINT>(sizeof(VertexAnim) * m_VertexAnimVector.size());
		VertexBufferDesc.CPUAccessFlags = 0;
		VertexBufferDesc.StructureByteStride = 0;
		VertexBufferDesc.Usage = D3D11_USAGE_DEFAULT;

		resourceData.pSysMem = &m_VertexAnimVector[0];

		//5pDevice->pDevice->CreateBuffer(&VertexBufferDesc. &resourceData, &m_BufferData->m_Buffer)
		ID3D11Device* pDevice = reinterpret_cast<ID3D11Device*>(prmDevice->GetObj());
		HRESULT hr = pDevice->CreateBuffer(&VertexBufferDesc, &resourceData, &m_Buffer->m_pObject);
		if (FAILED(hr))
		{
			__debugbreak();
		}
	}


	void C_AnimationVertexBuffer::SetBuffer(GraphicsDeviceContext* prmDeviceContext, uint32 StarSlot)
	{
		uint32 pStrides = sizeof(VertexAnim);
		uint32 pOffsets = 0;

		//////////////////////////////////////////////////////////////////////////
		ID3D11DeviceContext* pDeviceContext = reinterpret_cast<ID3D11DeviceContext*>(prmDeviceContext->GetObj());
		pDeviceContext->IASetVertexBuffers(StarSlot, 1, &m_Buffer->m_pObject, &pStrides, &pOffsets);
	}

	void C_AnimationVertexBuffer::InsertVertex(VertexAnim prmVertex)
	{
		m_VertexAnimVector.push_back(prmVertex);
	}


	void C_AnimationVertexBuffer::InsertVertexVector(const Vector<VertexAnim>& prmVertex)
	{
		for (uint32 i = 0; i < prmVertex.size() - 1; i++)
		{
			m_VertexAnimVector.push_back(prmVertex[i]);
		}
	}


	VertexAnim C_AnimationVertexBuffer::GetVertexAnim(uint32 ID)
	{
		for (uint32 i = 0; i < m_VertexAnimVector.size(); i++)
		{
			if (i == ID)
			{
				return	m_VertexAnimVector[i];
			}
		}
	}

}