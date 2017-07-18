#pragma once
//#include "OEGBuffer.h"
#include "OEDevice.h"
#include "OEDeviceContext.h"
#include "OEVertexAnimation.h"


namespace OE_SDK
{

	class ODIN_ENGINE_GRAPHICS_API_UTILITY_EXPORT C_AnimationVertexBuffer //: public C_GraphicsBuffer
	{

	public:
		C_AnimationVertexBuffer() {};
		virtual ~C_AnimationVertexBuffer() {};


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