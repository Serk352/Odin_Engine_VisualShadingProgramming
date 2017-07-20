#pragma once
#include "OEPrerequisitesGraphics.h"
#include "OEDevice.h"
#include "OEDeviceContext.h"
#include "OETexture2D.h"


namespace OE_SDK
{


	class ODIN_ENGINE_GRAPHICS_API_UTILITY_EXPORT OEShaderResource
	{	

	public:
		OEShaderResource();
		virtual ~OEShaderResource();

		void Create(OETexture2D Resource, 
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