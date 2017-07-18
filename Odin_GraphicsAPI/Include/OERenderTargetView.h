#pragma once
#include "OEPrerequisitesGraphics.h"
#include "OEDevice.h"
#include "OETexture2D.h"
#include "OEDeviceContext.h"

namespace OE_SDK
{

	class C_RenderTargetView
	{
	public:

		C_RenderTargetView();
		~C_RenderTargetView();


		
		void Create(const C_Texture2D& prmTexture);
		
		void* GetObj();
		void** GetReference();

	protected:
		struct sRenderTargetData;
		sRenderTargetData* m_RenderTarget;
	};


}