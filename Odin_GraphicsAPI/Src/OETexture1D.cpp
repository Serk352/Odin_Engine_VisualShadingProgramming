#include "OETexture1D.h"
#include "OEFileManager.h"

namespace OE_SDK
{
	C_Texture1D::C_Texture1D()
	{
	}
	C_Texture1D::~C_Texture1D()
	{
	}

	void C_Texture1D::LoadFromFile(const char* FileName)
	{
		SIZE_T FileSize;
		char* TextureInfo;
		C_File myFile;


		myFile.ReadAndSave(FileName, TextureInfo, FileSize);

		//	m_TextureData->myTexture1D = TextureInfo;

	}
	void C_Texture1D::CreateEmpty()
	{
		m_TextureData->myTexture1D;
	}
	void C_Texture1D::Release()
	{}


}