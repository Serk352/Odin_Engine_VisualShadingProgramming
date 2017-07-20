#include "OEShaders.h"

namespace OE_SDK
{
	 	OEGraphicsShaders::OEGraphicsShaders()
	 	{
			m_ShaderData = new (ShaderData);

			m_ShaderData->myShader = nullptr;
			m_ShaderData->pErrors = nullptr;
	 	}
	 
	 	OEGraphicsShaders::~OEGraphicsShaders()
	 	{
	 		Release();
	 	}


	void OEGraphicsShaders::Release()
	{
		SAFE_RELEASE(m_ShaderData->myShader);
		SAFE_RELEASE(m_ShaderData->pErrors);
		SAFE_DELETE(m_ShaderData);
	}
}