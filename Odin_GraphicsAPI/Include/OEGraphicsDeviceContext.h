#pragma once
#include "OEPrerequisitesGraphics.h"


namespace OE_SDK
{
	class ODIN_ENGINE_GRAPHICS_API_UTILITY_EXPORT GraphicsDeviceContext
	{
	public:
		GraphicsDeviceContext();
		~GraphicsDeviceContext();
		
		void* GetObj();
		void** GetReference();

	protected:
		struct DeviceContextData;
		DeviceContextData* m_DeviceContext;

	};

}