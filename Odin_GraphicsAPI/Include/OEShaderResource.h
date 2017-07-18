#pragma once
#include "OEPrerequisitesGraphics.h"
#include "OEGraphicsDevice.h"
#include "OEGraphicsDeviceContext.h"
#include "OETexture2D.h"


namespace OE_SDK
{


	class ODIN_ENGINE_GRAPHICS_API_UTILITY_EXPORT C_ShaderResource
	{	

	public:
		C_ShaderResource();
		virtual ~C_ShaderResource();

		void Create(C_Texture2D Resource, 
					int MipLevels, 
					int MDMipMap);

		void SetForPixelShader(unsigned int prmStartSlot, 
							   unsigned int prmNumViews);


		void SetForVertexShader(unsigned int prmStartSlot,
								unsigned int prmNumViews);


	protected:
		struct ResourceData;
		ResourceData* m_Resource;
	};
}