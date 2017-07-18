#pragma once
//#include "OEGraphicsBuffer.h"
#include "OEGraphicsDevice.h"
#include "OEGraphicsDeviceContext.h"
#include "OEVertexAnimation.h"


namespace OE_SDK
{

	class ODIN_ENGINE_GRAPHICS_API_UTILITY_EXPORT C_VertexAnimationBuffer //: public C_GraphicsBuffer
	{

	public:
		C_VertexAnimationBuffer() {};
		virtual ~C_VertexAnimationBuffer() {};


		virtual	void Create(GraphicsDevice* prmDevice, int32 flags);
							   
		virtual	void SetBuffer(GraphicsDeviceContext* prmDeviceContext, uint32 StarSlot = 0);

		void InsertVertex(VertexAnim prmVertex);
		void InsertVertexVector(const Vector<VertexAnim>& prmVertex);
		VertexAnim GetVertexAnim(uint32 ID);


	private:
		struct BufferData;
		BufferData* m_Buffer;
		Vector<VertexAnim> m_VertexAnimVector;

	};
}