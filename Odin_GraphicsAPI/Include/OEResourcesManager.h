#pragma once
#include "OEPrerequisitesGraphics.h"
#include "OETexture2D.h"
#include "OEModel.h"
#include "OEPixelShader.h"
#include "OEVertexShader.h"

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
		void loadTexture(const char* sSourcePath, 
						 int& rWidth, 
						 int& rHeight, 
						 int& rNumChannels);
		//Cargar un model
		void loadModel  (const char* sSourcePath);
		//Cargar un shader
		void LoadShader (const char* sSourcePath);

		void RequestTexture();
		void RequestModel();
		void RequestShader();

	protected: 
		Vector<*> m_LoadedResources;
	};

}