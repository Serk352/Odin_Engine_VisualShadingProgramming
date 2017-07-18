#include "OEDomainShader.h"
#include "OEFileManager.h"
#include "OEGraphicsAPI.h"

#include <d3dcompiler.h>


namespace OE_SDK
{
	const char* C_DomainShader::DS_SM = "ds_5_0";

	C_DomainShader::C_DomainShader()
	{
		m_ShaderData = new(ShaderData);
	}


	C_DomainShader::~C_DomainShader()
	{
		delete m_ShaderData;
	}


	void C_DomainShader::Create(const String FileName, const String EntryPoint)
	{
		WString Temp = WString(FileName.begin(), FileName.end());
		LPCWSTR File = LPCWSTR(Temp.c_str());
		LPCSTR Entry = EntryPoint.c_str();

		if (FAILED(D3DCompileFromFile(File, NULL, D3D_COMPILE_STANDARD_FILE_INCLUDE, Entry, DS_SM, D3DCOMPILE_DEBUG | D3DCOMPILE_ENABLE_STRICTNESS, 0, &m_ShaderData->myShader, &m_ShaderData->pErrors)))
		{

			OutputDebugString((char*)m_ShaderData->pErrors->GetBufferPointer());
			std::string s = (char*)m_ShaderData->pErrors->GetBufferPointer();

		}

		ID3D11Device* pDevice = reinterpret_cast<ID3D11Device*>(g_GraphicsAPI().GetDevice());
		pDevice->CreateDomainShader(m_ShaderData->myShader->GetBufferPointer(), m_ShaderData->myShader->GetBufferSize(), nullptr, &m_ShaderData->myDomainShader);

		ID3D11DeviceContext* pDeviceContext = reinterpret_cast<ID3D11DeviceContext*>(g_GraphicsAPI().GetDeviceContext());
		pDeviceContext->DSSetShader(m_ShaderData->myDomainShader, NULL, 0);

	}
}