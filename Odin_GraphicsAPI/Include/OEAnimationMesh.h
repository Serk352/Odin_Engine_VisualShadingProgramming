#pragma once
#include "OEPrerequisitesGraphics.h"
#include "OEVertexAnimation.h"
#include "OEIndexBuffer.h"
#include "OEAnimationVertexBuffer.h"
#include "OEDeviceContext.h"


namespace OE_SDK
{
	typedef OEIndexBufferTemplate<uint32> C_IndexBuffer32;


	class ODIN_ENGINE_GRAPHICS_API_UTILITY_EXPORT OEAnimationMesh
	{
	public:

		//
		void Init();
		//
		void Render(OEGraphicsDeviceContext* prmDeviceContext);
		//
		void Release();


		SIZE_T m_Size;


		OEAnimationVertexBuffer m_VertexAnimationBuffer;
		C_IndexBuffer32 m_IndexBuffer;

	};
}