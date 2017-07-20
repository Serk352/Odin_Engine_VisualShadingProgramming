#include "OEModel.h"
//#include <assimp/Importer.hpp>
#include <Importer.hpp>
//#include <assimp/Scene.h>
#include <Scene.h>
//#include <assimp/postprocess.h>
#include <postprocess.h>
#include "OEVertex.h"
#include "OEGraphicsAPI.h"

//<> se llaman corchetes angulares
namespace OE_SDK
{
	OEModel::OEModel()
	{

	}
	OEModel::~OEModel()
	{

	}

	//Si voy acrear un nuevo objeto es un Device
	//Si vas a modificar un objeto existente es un DeviceContext

	void OEModel::Init()
	{

	}

	bool OEModel::LoadFromFile(const char * strFileName)
	{
		//ID3D11Device* pDevice = reinterpret_cast<ID3D11Device*>(prmDevice->GetObj());
		Assimp::Importer myImporter;
		const aiScene* myScene = myImporter.ReadFile(strFileName, aiProcess_CalcTangentSpace |
			aiProcess_JoinIdenticalVertices |
			aiProcess_MakeLeftHanded |
			aiProcess_Triangulate |
			aiProcess_GenSmoothNormals |
			aiProcess_SortByPType);

		String s = myImporter.GetErrorString();

		if (!myScene)
		{
			return false;
		}


		if (myScene->HasMeshes())
		{
			//Este ciclo se utiiza para navegar entre los meshes de la escena
			for (uint32 i = 0; i < myScene->mNumMeshes; i++)
			{
				//Guardo el mesh que esta en el espacio actual del arreglo de meshes de la escena, y lo guardo en un mesh temporal
				aiMesh* pMesh = myScene->mMeshes[i];
				//Ahora el mesh temporal lo inserto en mi vector de meshes
				m_Meshes.push_back(new OEGraphicsMesh());
				//igualo un mesh temporal al mesh de mi vector de meshes del espacio actul
				OEGraphicsMesh& TempMesh = *m_Meshes[i];
				

				//Utilizo un Vertíce Temporal
				Vertex TempV;

				//Este ciclo se utiliza para navegar entre los vertíces del mesh
				for (uint32 j = 0; j < pMesh->mNumVertices; j++)
				{
					//Para alinear la memoria, generar memoria para ser llenado por objetos del tipo Vertex
					memset(&TempV, 0, sizeof(Vertex));

					//Se checa si el vertíce tiene posiciones
					if (pMesh->HasPositions())
					{
						//se Guarda la posición de  los vertices en el temporal, eje por eje (x,y,z)
						TempV.Position.X = pMesh->mVertices[j].x;
						TempV.Position.Y = pMesh->mVertices[j].y;
						TempV.Position.Z = pMesh->mVertices[j].z;
					}

					//Se checa si el vertíce tiene normales
					if (pMesh->HasNormals())
					{
						//se Guarda la posición de  las normales en el temporal, eje por eje (x,y,z)
						TempV.Normal.X = pMesh->mNormals[j].x;
						TempV.Normal.Y = pMesh->mNormals[j].y;
						TempV.Normal.Z = pMesh->mNormals[j].z;
					}

					//Se checa si el vertíce tiene Tangentes y bitangentes
					if (pMesh->HasTangentsAndBitangents())
					{
						//se Guarda la tangente de los vertices en el temporal, eje por eje (x,y,z)
						TempV.Tangent.X = pMesh->mTangents[j].x;
						TempV.Tangent.Y = pMesh->mTangents[j].y;
						TempV.Tangent.Z = pMesh->mTangents[j].z;

						//se Guarda la bitangente de los vertices en el temporal, eje por eje (x,y,z)
						TempV.BiTangents.X = pMesh->mBitangents[j].x;
						TempV.BiTangents.Y = pMesh->mBitangents[j].y;
						TempV.BiTangents.Z = pMesh->mBitangents[j].z;

					}

					//Se checa si el vertíce tiene posiciones
					if (pMesh->HasTextureCoords(0))
					{

						//se Guarda la coordenada de la textura en el temporal, eje por eje (x,y), solo dos ejes por que es un objeto bidimensional
						TempV.TextCoord.X = pMesh->mTextureCoords[0][j].x;
						TempV.TextCoord.Y = pMesh->mTextureCoords[0][j].y;
					}

					//Se checa si el vertíce tiene Color, canal por canal (r(red = rojo), g(green = verde), b(blue = azul), a(alpha = alfa) )
					if (pMesh->HasVertexColors(0))
					{
						//se Guarda el color de los vertices en el temporal, canal por canal (x = r, y = g, z = b, w = a)
						//TempV.color.

						//TempV.color.chanels.A =
						//TempV.ColorChanel[0] = pMesh->mColors[0][j].r;
						//TempV.ColorChanel[1] = pMesh->mColors[0][j].g;
						//TempV.ColorChanel[2] = pMesh->mColors[0][j].b;
						//TempV.ColorChanel[3] = pMesh->mColors[0][j].a;
						
						TempV.color.chanels.R = static_cast<uint8>(pMesh->mColors[0][j].r); 
						TempV.color.chanels.G = static_cast<uint8>(pMesh->mColors[0][j].g);
						TempV.color.chanels.B = static_cast<uint8>(pMesh->mColors[0][j].b);
						TempV.color.chanels.A = static_cast<uint8>(pMesh->mColors[0][j].a);
					}

					//Se checa si el vertíce tiene caras
					
					m_Meshes[i]->m_VertexBuffer.InsertVertex(TempV);

				}

				//m_Meshes[i].m_VertexBuffer.Create(pDevice, 0);


				if (pMesh->HasFaces())
				{
					for (uint32 j = 0; j < pMesh->mNumFaces; j++)
					{
						aiFace myFace;
						myFace = pMesh->mFaces[j];



						for (uint32 k = 0; k < myFace.mNumIndices; k++)
						{	
							/************************************************************************/
							/*                                                                      */
							/************************************************************************/

							TempMesh.m_IndexBuffer.InsertIndex((uint32)myFace.mIndices[k]);
						}

					}
				}

			}
		}


		for (uint32 i = 0; i < m_Meshes.size(); i++)
		{
	//		C_GraphicsAPI temp;

			//temp.GetDevice();

			//TODO: Crear
			
			m_Meshes[i]->m_VertexBuffer.Create(0);
			m_Meshes[i]->m_IndexBuffer.Create(0);

		}

		return true;
	}



	void OEModel::Render()
	{


		for (uint32 i = 0; i < m_Meshes.size(); i++)
		{
			m_Meshes[i]->Render();
		}

	}

	void OEModel::Release()
	{
	}

}