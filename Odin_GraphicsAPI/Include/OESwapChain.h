#pragma once

#include "OEPrerequisitesGraphics.h"

namespace OE_SDK
{
	class ODIN_ENGINE_GRAPHICS_API_UTILITY_EXPORT C_SwapChain
	{
	public:
		 C_SwapChain();
		~C_SwapChain();

		void Create(void* scrHandle, uint32 width, uint32 height);
		void* GetBuffer();

		void* GetObj();
		void** GetReference();

		void Present();

	private:
		struct SwapChainData;
		SwapChainData* m_SwapChain;
	};

}