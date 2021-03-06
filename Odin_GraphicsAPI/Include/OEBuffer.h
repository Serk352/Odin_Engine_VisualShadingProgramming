#pragma once
#include "OEPrerequisitesGraphics.h"
#include "OEDevice.h"
#include "OEDeviceContext.h"
#include "OEFormats.h"


namespace OE_SDK
{
	class ODIN_ENGINE_GRAPHICS_API_UTILITY_EXPORT OEBuffer
	{
	public:

		OEBuffer();
		~OEBuffer();

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