#pragma once
#include "OEPrerequisitesGraphics.h"

namespace OE_SDK
{

	class ODIN_ENGINE_GRAPHICS_API_UTILITY_EXPORT OEGraphicsDevice
	{
	public:

		OEGraphicsDevice();
		~OEGraphicsDevice();


		void* GetObj();
		void** GetReference();

	protected:
		struct DeviceData;
		DeviceData* m_Device;
	};
}