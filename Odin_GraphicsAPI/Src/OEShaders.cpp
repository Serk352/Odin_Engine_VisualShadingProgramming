#include "OEShaders.h"

namespace OE_SDK
{
	 	C_GraphicsShaders::C_GraphicsShaders()
	 	{
			m_ShaderData = new (ShaderData);

			m_ShaderData->myShader = nullptr;
			m_ShaderData->pErrors = nullptr;
	 	}
	 
	 	C_GraphicsShaders::~C_GraphicsShaders()
	 	{
	 		Release();
	 	}


	void C_GraphicsShaders::Release()
	{
		SAFE_RELEASE(m_ShaderData->myShader);
		SAFE_RELEASE(m_ShaderData->pErrors);
		SAFE_DELETE(m_ShaderData);
	}
}