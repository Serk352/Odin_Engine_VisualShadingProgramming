#include "OEConstantBuffer.h"
#include "d3d11.h"

namespace OE_SDK
{

// 
// 	C_ConstantBuffer::C_ConstantBuffer()
// 	{
// 
// 	}
// 
// 
// 	C_ConstantBuffer::~C_ConstantBuffer()
// 	{
// 
// 	}


	void OEConstantBuffer::Create(OEGraphicsDevice* prmDevice, int32 flags)
	{

		UNREFERENCED_PARAMETER(flags);
		UNREFERENCED_PARAMETER(prmDevice);

		D3D11_SUBRESOURCE_DATA resourceData;
		memset(&resourceData, 0, sizeof(D3D11_SUBRESOURCE_DATA));

		D3D11_BUFFER_DESC ConstantBufferDesc;
		memset(&ConstantBufferDesc, 0, sizeof(D3D11_BUFFER_DESC));

		ConstantBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
		//ConstantBufferDesc.ByteWidth = sizeof(Vertex) * m_VertexVector.size();
		ConstantBufferDesc.CPUAccessFlags = 0;
		ConstantBufferDesc.StructureByteStride = 0;
		ConstantBufferDesc.Usage = D3D11_USAGE_DEFAULT;
		//resourceData.pSysMem = &m_VertexVector[0];

		//5pDevice->pDevice->CreateBuffer(&VertexBufferDesc. &resourceData, &m_BufferData->m_Buffer)

		//pDevice->pDevice->CreateBuffer(&VertexBufferDesc, &resourceData, &m_BufferData->m_Buffer);



	}



	void OEConstantBuffer::SetBuffer(OEGraphicsDeviceContext* prmDeviceContext, uint32 StarSlot /* = 0 */)
	{
		UNREFERENCED_PARAMETER(StarSlot);
		UNREFERENCED_PARAMETER(prmDeviceContext);
	}
}