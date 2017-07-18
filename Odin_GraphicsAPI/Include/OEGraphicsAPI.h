#pragma once

#include "OEPrerequisitesGraphics.h"
#include <OEModule.h>
#include "OERenderTargetView.h"
#include <OESTDHeader.h>
#include "OEDepthStencil.h"

namespace OE_SDK
{



	class ODIN_ENGINE_GRAPHICS_API_UTILITY_EXPORT C_GraphicsAPI : public Module<C_GraphicsAPI>
	{
	public:

		C_GraphicsAPI();
		~C_GraphicsAPI();

		
		//C_Camera myCam;

		void Init(void* scrHandle, uint32 width, uint32 height, bool fullscreen);
		void CleanUp();

		//////////////////////////////////////////////////////////////////////////
		void* GetDevice();
		void** GetDeviceReference();

		//////////////////////////////////////////////////////////////////////////
		void* GetDeviceContext();
		void** GetDeviceContextReference();

		//Swap Chain
		void* GetSwapChainObject();
		void** GetSwapChainReference();
		void PresentSwapChain();

		//RenderTarget View
		void* GetRenderTargetViewObject();
		void** GetRenderTargetViewReference();
		void SetRenderTargets(const Vector<C_RenderTargetView*>& prmRendertargetsViews, const C_DepthStencil& prmDepthStencil);

		//ShaderResource View
		void* GetShaderResourceViewnObject();
		void** GetShaderResourceViewReference();

		//DepthStencil View
		void* GetDepthStencilViewObject();
		void** GetDepthStencilViewReference();
		void ClearDepthStencil();

		//Viewports
		void* GetViewPortObject();
		void** GetViewPortReference();

		//Window Size
		uint32 m_Width;
		uint32 m_Height;

	protected:
		//Graphic Library Object Container
		struct ApiData;
		ApiData* m_APIData;

	//private:
				
	};

	ODIN_ENGINE_GRAPHICS_API_UTILITY_EXPORT C_GraphicsAPI& g_GraphicsAPI();
}

