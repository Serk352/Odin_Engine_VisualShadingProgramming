#pragma once
#include "OEPrerequisitesGraphics.h"



namespace OE_SDK
{

	class ODIN_ENGINE_GRAPHICS_API_UTILITY_EXPORT C_DepthStencil
	{
	public:
		C_DepthStencil();
		~C_DepthStencil();


		void Create(uint32 width, uint32 height);
		void Set();
		void Clear();

		void* GetObj();
		void** GetReference();
		

	protected:
		struct DepthStencilData;
		DepthStencilData* m_DepthStencil;

	};

}