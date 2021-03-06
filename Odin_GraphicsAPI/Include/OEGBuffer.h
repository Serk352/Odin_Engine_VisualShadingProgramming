#pragma once
#include "OEPrerequisitesGraphics.h"
#include "OEDevice.h"
#include "OEDeviceContext.h"

#if ODIN_ENGINE_PLATFORM == ODIN_ENGINE_PLATFORM_WIN32
#	include <d3d11.h>
#endif
#include "OEVertex.h"

namespace OE_SDK
{
	struct BufferData
	{
#if ODIN_ENGINE_PLATFORM == ODIN_ENGINE_PLATFORM_WIN32
		BufferData() :
			m_Buffer(nullptr)
		{

		}

		ID3D11Buffer* m_Buffer;
#endif
	};


	class ODIN_ENGINE_GRAPHICS_API_UTILITY_EXPORT C_GraphicsBuffer
	{
	public:
		C_GraphicsBuffer();
		virtual	~C_GraphicsBuffer();

		BufferData* m_BufferData;
	
		virtual	void Create(const OEGraphicsDevice* pDevice, int32 flags)=0;
		virtual	void SetBuffer(const OEGraphicsDeviceContext* pDeviceContext, uint32 StarSlot=0)=0;
		virtual	void Release();
	};

}
