#pragma once
#include "OEPrerequisitesGraphics.h"
#include "OEGraphicsDevice.h"
#include "OEGraphicsDeviceContext.h"
#include "OEFormats.h"


namespace OE_SDK
{
	class ODIN_ENGINE_GRAPHICS_API_UTILITY_EXPORT C_Buffer
	{
	public:

		C_Buffer();
		~C_Buffer();

		void Create(void* prmData, SIZE_T ByteSize);

		void SetData(const void* pData, uint32 ByteSize);

		void SetForPixelSahder(unsigned int StartSlot);

		void SetForVertexShader(unsigned int StartSlot);

		void* GetObj();
		void** GetReference();
	protected:

		struct BufferData;
		BufferData* m_Buffer;
	};





}