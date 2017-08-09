#include "OETexture1D.h"
#include "OEFileManager.h"

namespace OE_SDK
{
	OETexture1D::OETexture1D()
	{
	}
	OETexture1D::~OETexture1D()
	{
	}

	void OETexture1D::LoadFromFile(const char* FileName)
	{
		SIZE_T FileSize;
		char* TextureInfo;
		C_File myFile;


		myFile.ReadAndSave(FileName, TextureInfo, FileSize);

		//	m_TextureData->myTexture1D = TextureInfo;

	}
	void OETexture1D::CreateEmpty()
	{
		//m_TextureData->myTexture1D;
	}
	void OETexture1D::Release()
	{}


}