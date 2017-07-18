#include "OEHullShader.h"
#include "OEFileManager.h"
#include "OEGraphicsAPI.h"

#include <d3dcompiler.h>

namespace OE_SDK
{
	const char* C_HullShader::HS_SM = "hs_5_0";

	C_HullShader::C_HullShader()
	{
		m_ShaderData = new(ShaderData);
	}

	C_HullShader::~C_HullShader()
	{

	}



	void C_HullShader::Create(const String FileName, const String EntryPoint)
	{
		WString Temp =  WString(FileName.begin(), FileName.end());
		LPCWSTR File = LPCWSTR(Temp.c_str());
		LPCSTR Entry = EntryPoint.c_str();

		if (FAILED(D3DCompileFromFile(File, NULL, D3D_COMPILE_STANDARD_FILE_INCLUDE, Entry, HS_SM, D3DCOMPILE_DEBUG | D3DCOMPILE_ENABLE_STRICTNESS, 0, &m_ShaderData->myShader, &m_ShaderData->pErrors)))
		{

			OutputDebugString((char*)m_ShaderData->pErrors->GetBufferPointer());
			std::string s = (char*)m_ShaderData->pErrors->GetBufferPointer();

		}

		ID3D11Device* pDevice = reinterpret_cast<ID3D11Device*>(g_GraphicsAPI().GetDevice());
		pDevice->CreateHullShader(m_ShaderData->myShader->GetBufferPointer(), m_ShaderData->myShader->GetBufferSize(), nullptr, &m_ShaderData->myHullShader);

		ID3D11DeviceContext* pDeviceContext = reinterpret_cast<ID3D11DeviceContext*>(g_GraphicsAPI().GetDeviceContext());
		pDeviceContext->HSSetShader(m_ShaderData->myHullShader, NULL, 0);

	}

}