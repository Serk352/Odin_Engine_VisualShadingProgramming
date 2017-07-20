#pragma once
//#include "OEGBuffer.h"
#include "OEDevice.h"
#include "OEDeviceContext.h"


///////////////////////////////////////////////////////////////////////////////////////////////////
//Si un template se va a definir en el cpp deben generarse los tipos que						 //
//pueden usarlo si no hay que hacerlo en el .h													 //
///////////////////////////////////////////////////////////////////////////////////////////////////
namespace OE_SDK
{
	template<typename T>
	class ODIN_ENGINE_GRAPHICS_API_UTILITY_EXPORT OEIndexBufferTemplate //: public C_GraphicsBuffer
	{
	public:
		OEIndexBufferTemplate();
		virtual ~OEIndexBufferTemplate();

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

	typedef OEIndexBufferTemplate<uint16> C_IndexBuffer16;
	typedef OEIndexBufferTemplate<uint32> C_IndexBuffer32;

}