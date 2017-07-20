#include "OEInputLayout.h"
#include "OEGraphicsAPI.h"
#include "OEVertexShader.h"

#include <d3d11.h>

namespace OE_SDK
{
	struct OEInputLayout::InputLayoutData
	{
		ID3D11InputLayout* m_pObject;
		Vector<D3D11_INPUT_ELEMENT_DESC> m_vElements;
	};

	OEInputLayout::OEInputLayout()
	{
		//m_InputLayoutData->m_VertexLayout = nullptr;
		m_InputLayoutData = new(InputLayoutData);
	}

	OEInputLayout::~OEInputLayout()
	{
		SAFE_DELETE(m_InputLayoutData);
	}

	void OEInputLayout::create(OEVertexShader* prmVShader)
	{
	//	m_InputLayoutData = new(InputLayoutData);


		SIZE_T SizeVector = m_InputLayoutData->m_vElements.size();

		ID3D11Device* pDevice = reinterpret_cast<ID3D11Device*>(g_GraphicsAPI().GetDevice());
		HRESULT hr = pDevice->CreateInputLayout(m_InputLayoutData->m_vElements.data(),
												  static_cast<UINT>(SizeVector),
												  prmVShader->m_ShaderData->myShader->GetBufferPointer(), 
												  prmVShader->m_ShaderData->myShader->GetBufferSize(), 
												  &m_InputLayoutData->m_pObject);
		if (FAILED(hr))
		{
			__debugbreak();
		}
	}


	void OEInputLayout::AddInputElement(const char * prmSemanticName, uint32 prmSemanticIndex, DXGI_FORMAT prmFormat, uint32 prmInputSlot, uint32 prmAlignedByteOffset, D3D11_INPUT_CLASSIFICATION prmInputSlotClass, uint32 prmInstanceDataStepRate)
	{
		//Descriptor que se incluirá al vector

		D3D11_INPUT_ELEMENT_DESC m_Temp;

		//Set de los miembros del descriptor
		m_Temp.SemanticName = prmSemanticName;
		m_Temp.SemanticIndex = prmSemanticIndex;
		m_Temp.Format = prmFormat;
		m_Temp.InputSlot = prmInputSlot;
		m_Temp.AlignedByteOffset = prmAlignedByteOffset;
		m_Temp.InputSlotClass = prmInputSlotClass;
		m_Temp.InstanceDataStepRate = prmInstanceDataStepRate;

		//Se inserta el elemento en la lista
		m_InputLayoutData->m_vElements.push_back(m_Temp);

	}

	void OEInputLayout::Set()
	{
		//Setear el/los "Valores" de Input Layout
		ID3D11DeviceContext* pDeviceContext = reinterpret_cast<ID3D11DeviceContext*>(g_GraphicsAPI().GetDeviceContext());
		pDeviceContext->IASetInputLayout(m_InputLayoutData->m_pObject);
	}

	

}
