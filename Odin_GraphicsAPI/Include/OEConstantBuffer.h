#pragma once


#include "OEPrerequisitesGraphics.h"
//#include "OEGBuffer.h"
#include "OEDevice.h"
#include "OEDeviceContext.h"
#include <DirectXMath.h>

namespace OE_SDK
{


	class ODIN_ENGINE_GRAPHICS_API_UTILITY_EXPORT OEConstantBuffer
	{

		virtual	void Create(OEGraphicsDevice* prmDevice, int32 flags);
		virtual	void SetBuffer(OEGraphicsDeviceContext* prmDeviceContext, uint32 StarSlot = 0);

		struct Vista
		{
			DirectX::XMMATRIX Projection;
		};

		struct Projeccion
		{

		};


		struct Mundo
		{

		};

	};

}