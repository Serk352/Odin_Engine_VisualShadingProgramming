#pragma once
#include "OEPrerequisitesGraphics.h"
#include "OEVertexAnimation.h"
#include "OEIndexBuffer.h"
#include "OEAnimationVertexBuffer.h"
#include "OEDeviceContext.h"


namespace OE_SDK
{
	typedef C_IndexBufferTemplate<uint32> C_IndexBuffer32;


	class ODIN_ENGINE_GRAPHICS_API_UTILITY_EXPORT C_AnimationMesh
	{
	public:

		//
		void Init();
		//
		void Render(GraphicsDeviceContext* prmDeviceContext);
		//
		void Release();


		SIZE_T m_Size;


		C_AnimationVertexBuffer m_VertexAnimationBuffer;
		C_IndexBuffer32 m_IndexBuffer;

	};
}