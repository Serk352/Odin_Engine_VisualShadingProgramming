#pragma once
#include "OEPrerequisitesGraphics.h"
#include "OETexture2D.h"
#include <Matrix4.h>
#include "OEPixelShader.h"
#include "OEVertexShader.h"


namespace OE_SDK
{

	class ODIN_ENGINE_GRAPHICS_API_UTILITY_EXPORT C_GraphicsMaterial
	{
	public:
		C_GraphicsMaterial();
		~C_GraphicsMaterial();


		C_Texture2D m_Normal;
		C_Texture2D m_Albedo; 

		C_Matrix4 m_World;
		C_Matrix4 m_View;

		//Ruta de las texturas 
		String m_SNormalPath;
		String m_SAlbedoPath;
		
		//Ruta de los shaders
		String m_SPixelShaderPath;
		String m_SVertexShaderPath;
		
		void Init();
		void Update();
 
	protected:
		//aqui van los shaders

		C_VertexShader
	};

}
