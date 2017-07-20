#include "OEResourcesManager.h"
//Libreria necesaria para abrir imagenes.
#include <Externals/stb_image.h>

namespace OE_SDK
{
	void OEResourceManager::loadTexture(const char* sSourcePath, int& rWidth, int& rHeight, int& rNumChannels)
	{
		uint8* LoadTexture = stbi_load(sSourcePath, &rWidth, &rHeight, NULL, rNumChannels);
	}



}