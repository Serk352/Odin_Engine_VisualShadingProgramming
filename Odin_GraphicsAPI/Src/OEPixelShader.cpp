#include "OEPixelShader.h"
#include "OEFileManager.h"
#include "OEGraphicsAPI.h"

#include <d3dcompiler.h>


namespace OE_SDK
{
	const char* OEPixelShader::PS_SM = "ps_5_0";

	OEPixelShader::OEPixelShader()
	{
		m_ShaderData = new(ShaderData);
	}


	OEPixelShader::~OEPixelShader()
	{
	}

	//myPixelShader
	/*void C_PixelShader::CompileFromFile(const WCHAR* FileName, const char* EntryPoint, const char* ShaderModel)
	{
		
		if (FAILED(D3DCompileFromFile(FileName, NULL, D3D_COMPILE_STANDARD_FILE_INCLUDE, EntryPoint, ShaderModel, D3DCOMPILE_DEBUG | D3DCOMPILE_ENABLE_STRICTNESS, 0, &m_ShaderData->myShader, &m_ShaderData->pErrors)))
		{  
			OutputDebugString((char*)m_ShaderData->pErrors->GetBufferPointer());

			std::string s = (char*)m_ShaderData->pErrors->GetBufferPointer();
		}

	}*/
	

	void OEPixelShader::Create(const String FileName, const String EntryPoint)
	{
		WString Temp = WString(FileName.begin(), FileName.end());
		LPCWSTR File = LPCWSTR(Temp.c_str());
		LPCSTR Entry = EntryPoint.c_str();

		OEGraphicsAPI* pGraphics = g_GraphicsAPI().instancePtr();

		if (FAILED(D3DCompileFromFile(File, NULL, D3D_COMPILE_STANDARD_FILE_INCLUDE, Entry, PS_SM, D3DCOMPILE_DEBUG | D3DCOMPILE_ENABLE_STRICTNESS, 0, &m_ShaderData->myShader, &m_ShaderData->pErrors)))
		{
			OutputDebugString((char*)m_ShaderData->pErrors->GetBufferPointer());
			std::string s = (char*)m_ShaderData->pErrors->GetBufferPointer();
		}


		ID3D11Device* pDevice = reinterpret_cast<ID3D11Device*>(pGraphics->GetDevice());
		pDevice->CreatePixelShader(m_ShaderData->myShader->GetBufferPointer(), m_ShaderData->myShader->GetBufferSize(), nullptr, &m_ShaderData->myPixelShader);

		ID3D11DeviceContext* pDeviceContext = reinterpret_cast<ID3D11DeviceContext*>(pGraphics->GetDeviceContext());
		pDeviceContext->PSSetShader(m_ShaderData->myPixelShader, NULL, 0);
	}

	/*
	void C_PixelShader::Create(const GraphicsDevice* pDevice)
	{
		pDevice->pDevice->CreatePixelShader(m_ShaderData->myShader->GetBufferPointer(), m_ShaderData->myShader->GetBufferSize(), nullptr, &m_ShaderData->myPixelShader);
		//m_ShaderData->myShader->Release(); 

	}

	void C_PixelShader::Set(GraphicsDeviceContext* pDeviceContext)
	{
		pDeviceContext->pDeviceContext->PSSetShader(m_ShaderData->myPixelShader, NULL, 0);
	}
	*/
}