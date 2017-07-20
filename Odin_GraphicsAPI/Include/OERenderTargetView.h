#pragma once
#include "OEPrerequisitesGraphics.h"
#include "OEDevice.h"
#include "OETexture2D.h"
#include "OEDeviceContext.h"

namespace OE_SDK
{

	class ODIN_ENGINE_GRAPHICS_API_UTILITY_EXPORT OERenderTargetView
	{
	public:

		OERenderTargetView();
		~OERenderTargetView();


		
		void Create(const OETexture2D& prmTexture);
		
		void* GetObj();
		void** GetReference();

	protected:
		struct sRenderTargetData;
		sRenderTargetData* m_RenderTarget;
	};


}