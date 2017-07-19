#include "OEMesh.h"
#include "OEGraphicsAPI.h"


namespace OE_SDK
{

	void C_GraphicsMesh::Init()
	{
	}

	void C_GraphicsMesh::Render()
	{
		ID3D11DeviceContext* pDeviceContext = reinterpret_cast<ID3D11DeviceContext*>(g_GraphicsAPI().GetDeviceContext());
		m_IndexBuffer.SetBuffer(0);
		m_VertexBuffer.SetBuffer(0);

		//////////////////////////////////////////////////////////////////////////
		m_Size = m_IndexBuffer.GetIndexCount();
		pDeviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
		//////////////////////////////////////////////////////////////////////////
		pDeviceContext->DrawIndexed(static_cast<UINT>(m_Size), 0, 0);
	}

	void C_GraphicsMesh::Release()
	{
	}

}