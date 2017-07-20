#include "OEAnimationMesh.h"
#include "d3d11.h"

namespace OE_SDK
{

	void OEAnimationMesh::Init()
	{

	}

	void OEAnimationMesh::Render(OEGraphicsDeviceContext* prmDeviceContext)
	{
		m_IndexBuffer.SetBuffer(0);
		m_VertexAnimationBuffer.SetBuffer(prmDeviceContext, 0);

		m_Size = m_IndexBuffer.GetIndexCount();

		ID3D11DeviceContext* pDeviceContext = reinterpret_cast<ID3D11DeviceContext*>(prmDeviceContext->GetObj());
		pDeviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

		pDeviceContext->DrawIndexed((static_cast<UINT>(m_Size)), 0, 0);

	}


	void OEAnimationMesh::Release()
	{

	}

}