#include "OEVertexBuffer.h"
#include "OEGraphicsAPI.h"
#include <d3d11.h>

namespace OE_SDK
{

	struct OEVertexBuffer::BufferData
	{
		ID3D11Buffer* m_pObject;
	};

	OEVertexBuffer::OEVertexBuffer()
	{
		m_buffer = new BufferData;
		m_buffer->m_pObject = nullptr;
	}

	OEVertexBuffer::~OEVertexBuffer()
	{
		SAFE_RELEASE(m_buffer->m_pObject);
		delete m_buffer;
	}

	//template<typename T>
	void OEVertexBuffer::Create(int32)
	{
		D3D11_SUBRESOURCE_DATA resourceData;
		memset(&resourceData, 0, sizeof(D3D11_SUBRESOURCE_DATA));

		D3D11_BUFFER_DESC VertexBufferDesc;
		memset(&VertexBufferDesc, 0, sizeof(D3D11_BUFFER_DESC));

		VertexBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
		VertexBufferDesc.ByteWidth = static_cast<UINT>(sizeof(Vertex) * m_VertexVector.size());
		VertexBufferDesc.CPUAccessFlags = 0;
		VertexBufferDesc.StructureByteStride = 0;
		VertexBufferDesc.Usage = D3D11_USAGE_DEFAULT;

		resourceData.pSysMem = &m_VertexVector[0];
		resourceData.SysMemPitch = (UINT)(m_VertexVector.size() * sizeof(Vertex));

		//5pDevice->pDevice->CreateBuffer(&VertexBufferDesc. &resourceData, &m_BufferData->m_Buffer)

		ID3D11Device* pDevice = reinterpret_cast<ID3D11Device*>(g_GraphicsAPI().GetDevice());

		HRESULT hr = pDevice->CreateBuffer(&VertexBufferDesc, &resourceData, &m_buffer->m_pObject);
		if (FAILED(hr))
		{
			__debugbreak();
		}
	}

	//template<typename T>
	void OEVertexBuffer::SetBuffer(uint32 StarSlot)// const GraphicsDevice* pDevice, const GraphicsDeviceContext* pDeviceContext)
	{	
		ID3D11DeviceContext* pDContext = reinterpret_cast<ID3D11DeviceContext*>(g_GraphicsAPI().GetDeviceContext());
		uint32 pStrides = sizeof(Vertex);
		uint32 pOffsets = 0;
		pDContext->IASetVertexBuffers(StarSlot, 1, &m_buffer->m_pObject, &pStrides, &pOffsets);
	}

	//template<typename T>
	void OEVertexBuffer::InsertVertex(Vertex prmVertex)
	{
		m_VertexVector.push_back(prmVertex);
	}
	//template<typename T>
	void OEVertexBuffer::InsertVertexVector(const Vector<Vertex>& prmVertex)
	{
		for (uint32 i = 0; i < prmVertex.size() - 1; i++)
		{
			m_VertexVector.push_back(prmVertex[i]);
		}
	}

}