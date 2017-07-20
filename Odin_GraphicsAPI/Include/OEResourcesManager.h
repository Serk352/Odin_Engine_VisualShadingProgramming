#pragma once
#include "OEPrerequisitesGraphics.h"
#include "OETexture2D.h"

namespace OE_SDK
{
	//Esta clase estar� encarga de cargar y administrar el uso de recursos
	//dentro del sistema de gr�ficos.
	/*
	El mecanismo de manager funcionar� cargando los archivos usando el nombre
	de los archivos y, aquellos que hagan un call de ese objeto solo recibir�n
	un puntero o referencia a la memoria donde est� alojado el objeto.
	*/

	class ODIN_ENGINE_GRAPHICS_API_UTILITY_EXPORT OEResourceManager
	{
	public:

		//Cargar una textura
		void loadTexture(String SourcePath, int& m_Width, int& m_Height);
		//Cargar un model
		void loadModel  (String SourcePath);
		//Cargar un shader
		void LoadShader (String SourcePath);

	};

}