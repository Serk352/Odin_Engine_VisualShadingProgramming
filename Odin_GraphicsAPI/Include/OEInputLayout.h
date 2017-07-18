#pragma once
#include "OEPrerequisitesGraphics.h"

#if ODIN_ENGINE_PLATFORM == ODIN_ENGINE_PLATFORM_WIN32
#	include <d3d11.h>
#endif

namespace OE_SDK
{
	class C_VertexShader;

	class ODIN_ENGINE_GRAPHICS_API_UTILITY_EXPORT C_InputLayout
	{
	public:
		C_InputLayout();
		~C_InputLayout();

		//Métodos
		void create(C_VertexShader* prmVSShader);
		void AddInputElement(const char* prmSemanticName, uint32 prmSemanticIndex ,DXGI_FORMAT prmFormat, uint32 prmInputSlot, 
			                 uint32 prmAlignedByteOffset, D3D11_INPUT_CLASSIFICATION prmInputSlotClass, uint32 prmInstanceDataStepRate);
		void Set();
	
	protected:
		//Variables
		struct InputLayoutData;
		InputLayoutData* m_InputLayoutData;
	};
}