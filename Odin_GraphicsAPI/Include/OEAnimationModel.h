#pragma once

#include "OEMesh.h"
#include "OEAnimationMesh.h"
#include "OEDeviceContext.h"

namespace OE_SDK
{

	class ODIN_ENGINE_GRAPHICS_API_UTILITY_EXPORT C_AnimationModel
	{
	public:
		C_AnimationModel();
		~C_AnimationModel();


		void Init();
		bool LoadFromFile(const char* strFileName, GraphicsDevice* prmDevice);
		void Render(GraphicsDeviceContext* prmDeviceContext);
		void Release();

		Vector<C_AnimationMesh*> m_Meshes;


	};

}