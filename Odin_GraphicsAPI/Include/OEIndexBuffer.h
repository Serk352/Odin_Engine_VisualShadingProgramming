#pragma once
//#include "OEGraphicsBuffer.h"
#include "OEGraphicsDevice.h"
#include "OEGraphicsDeviceContext.h"


///////////////////////////////////////////////////////////////////////////////////////////////////
//Si un template se va a definir en el cpp deben generarse los tipos que						 //
//pueden usarlo si no hay que hacerlo en el .h													 //
///////////////////////////////////////////////////////////////////////////////////////////////////
namespace OE_SDK
{
	template<typename T>
	class ODIN_ENGINE_GRAPHICS_API_UTILITY_EXPORT C_IndexBufferTemplate //: public C_GraphicsBuffer
	{
	public:
		C_IndexBufferTemplate();
		virtual ~C_IndexBufferTemplate();

		virtual	void Create(int32 flags);

		virtual	void SetBuffer(uint32 StarSlot=0);

		void InsertIndex(T prmIndex);
		void InsertIndexVector(const Vector<T>& prmIndex);

		SIZE_T GetIndexCount();

		

	private:
		struct BufferData;
		BufferData* m_Buffer;
		Vector<T> m_IndexVector;
	};

	typedef C_IndexBufferTemplate<uint16> C_IndexBuffer16;
	typedef C_IndexBufferTemplate<uint32> C_IndexBuffer32;

}