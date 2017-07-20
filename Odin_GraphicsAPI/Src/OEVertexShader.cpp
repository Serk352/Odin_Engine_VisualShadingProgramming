#include "OEVertexShader.h"
#include "OEFileManager.h"
#include "OEGraphicsAPI.h"

#include <d3dcompiler.h>

namespace OE_SDK
{
	//Define el modelo de shaders con el que se compilaran todos los VS
	const char* OEVertexShader::VS_SM = "vs_5_0";


	OEVertexShader::OEVertexShader()
	{
	}


	OEVertexShader::~OEVertexShader()
	{
	}



	void OEVertexShader::Create(const String FileName, const String EntryPoint)
	{
		WString Temp = WString(FileName.begin(), FileName.end());
		LPCWSTR File  = LPCWSTR( Temp.c_str());
		LPCSTR Entry = EntryPoint.c_str();

		if(FAILED(D3DCompileFromFile(File, NULL, D3D_COMPILE_STANDARD_FILE_INCLUDE, Entry, VS_SM, D3DCOMPILE_DEBUG | D3DCOMPILE_ENABLE_STRICTNESS, 0, &m_ShaderData->myShader, &m_ShaderData->pErrors)))
		{
			OutputDebugString((char*)m_ShaderData->pErrors->GetBufferPointer());

			std::string s = (char*)m_ShaderData->pErrors->GetBufferPointer();
		}
	
		OEGraphicsAPI* pGraphicsAPI = OEGraphicsAPI::instancePtr();

		ID3D11Device* pDevice = reinterpret_cast<ID3D11Device*>(pGraphicsAPI->GetDevice());
		ID3D11DeviceContext* pDeviceContext = reinterpret_cast<ID3D11DeviceContext*>(pGraphicsAPI->GetDeviceContext());

		pDevice->CreateVertexShader(m_ShaderData->myShader->GetBufferPointer(), m_ShaderData->myShader->GetBufferSize(), NULL, &m_ShaderData->myVertexShader);
	
		pDeviceContext->VSSetShader(m_ShaderData->myVertexShader, NULL, 0);
	}

}