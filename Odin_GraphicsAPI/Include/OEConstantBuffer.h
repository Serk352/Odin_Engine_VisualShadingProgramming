#pragma once


#include "OEPrerequisitesGraphics.h"
//#include "OEGraphicsBuffer.h"
#include "OEGraphicsDevice.h"
#include "OEGraphicsDeviceContext.h"
#include <DirectXMath.h>

namespace OE_SDK
{


	class ODIN_ENGINE_GRAPHICS_API_UTILITY_EXPORT C_ConstantBuffer
	{

		virtual	void Create(GraphicsDevice* prmDevice, int32 flags);
		virtual	void SetBuffer(GraphicsDeviceContext* prmDeviceContext, uint32 StarSlot = 0);

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