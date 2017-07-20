#pragma once
#include "OEPrerequisitesGraphics.h"
#include "OEVertex.h"
#include "OEIndexBuffer.h"
#include "OEVertexBuffer.h"
//#include "OEAnimationVertexBuffer.h"
#include "OEDeviceContext.h"

/*
#if ODIN_ENGINE_PLATFORM == ODIN_ENGINE_PLATFORM_WIN32
#	include <d3d11.h>
#endif
*/

namespace OE_SDK
{
	typedef OEIndexBufferTemplate<uint32> C_IndexBuffer32;
		
	class ODIN_ENGINE_GRAPHICS_API_UTILITY_EXPORT OEGraphicsMesh
	{
	public:

		//
		void Init();
		//
		void Render();
		//		
		void Release();

		//uint32 StartIndexLocation=0;
		//int32 BaseCertexLocation;

		SIZE_T m_Size;

		OEVertexBuffer m_VertexBuffer;
		//C_VertexAnimationBuffer m_VertexAnimationBuffer;
		C_IndexBuffer32 m_IndexBuffer; 



	};

}

