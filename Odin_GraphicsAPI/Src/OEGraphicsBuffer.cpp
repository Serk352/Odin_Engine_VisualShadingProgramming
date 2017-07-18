#include "OEGraphicsBuffer.h"
#include <d3d11.h>

namespace OE_SDK
{
	C_GraphicsBuffer::C_GraphicsBuffer()
	{
		m_BufferData = new(BufferData);

		
	}

	C_GraphicsBuffer::~C_GraphicsBuffer()
	{
		Release();
	}

	void C_GraphicsBuffer::Release()
	{
		SAFE_RELEASE(m_BufferData->m_Buffer);
	}
}
