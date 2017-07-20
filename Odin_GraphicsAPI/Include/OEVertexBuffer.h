#pragma once
#include "OEVertex.h"

namespace OE_SDK
{
	//template<typename T>
	class ODIN_ENGINE_GRAPHICS_API_UTILITY_EXPORT OEVertexBuffer //: public C_GraphicsBuffer
	{
	public:
		OEVertexBuffer();
		~OEVertexBuffer();

		
		virtual	void Create(int32 flags);
		
		virtual	void SetBuffer(uint32 StarSlot = 0);
		 
		void InsertVertex(Vertex prmVertex);
		void InsertVertexVector(const Vector<Vertex>& prmVertex);

	private:
		struct BufferData;
		BufferData* m_buffer;
		Vector<Vertex> m_VertexVector;
	};



}
