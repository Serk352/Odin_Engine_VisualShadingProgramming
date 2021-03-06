#pragma once
#include "OEPrerequisitesGraphics.h"
#include "OETexture2D.h"
#include <Matrix4.h>
#include "OEPixelShader.h"
#include "OEVertexShader.h"
#include "OEResources.h"

namespace OE_SDK
{

	class ODIN_ENGINE_GRAPHICS_API_UTILITY_EXPORT OEGraphicsMaterial : public OEResource
	{
	public:
		OEGraphicsMaterial();
		~OEGraphicsMaterial();


		/*Un material es un conjunto de texturas con los shaders 
		necesarios para hacer el render*/

		OETexture2D m_Normal;
		OETexture2D m_Albedo; 
		
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
		OEVertexShader VShader;
		OEPixelShader PShader;
	};

}
