#include "OEAnimationModel.h"
//#include <assimp/Importer.hpp>
//#include <assimp/Scene.h>
//#include <assimp/postprocess.h>


#include <Importer.hpp>
#include <Scene.h>
#include <postprocess.h>

#include "OEVertex.h"
#include "OEVertexAnimation.h"
#include "OEGraphicsAPI.h"
#include "OEAnimationVertexBuffer.h"
#include "OEAnimation.h"
#include "OESkeleton.h"
//#include "assimp/"

namespace OE_SDK
{
	OEAnimationModel::OEAnimationModel()
	{

	}
	OEAnimationModel::~OEAnimationModel()
	{

	}

	void OEAnimationModel::Init()
	{

	}

	void AddBone(Node<Bone>* pParent, aiNode* pParentAssimp, OESkeleton* MySkeletal)
	{
		MySkeletal->m_RootNode.m_Father = NULL;
			
		if (MySkeletal->m_RootNode.m_Childrens.size() == 0)
		{
			MySkeletal->m_RootNode.m_Childrens.push_back(pParent);
		}

		if (pParentAssimp->mNumChildren != 0)
		{
			//pParentAssimp->mChildren

			for (uint32 i = 0; i < pParentAssimp->mNumChildren; i++)
			{
				Node<Bone> a;
				a.m_Father = pParent;

				AddBone(&a, pParentAssimp->mChildren[i],MySkeletal);
			}
		}
	}


	//Cargar una animación desde un archivo
	bool OEAnimationModel::LoadFromFile(const char * strFileName, OEGraphicsDevice* prmDevice)
	{
		Assimp::Importer myImporter = Assimp::Importer();

		const aiScene* myScene = myImporter.ReadFile(strFileName, aiProcess_CalcTangentSpace |
			aiProcess_JoinIdenticalVertices |
			aiProcess_MakeLeftHanded |
			aiProcess_Triangulate |
			aiProcess_GenSmoothNormals |
			aiProcess_SortByPType);

		if (!myScene)
		{
			return false;
		}


		if (myScene->HasAnimations())
		{
		
			OEAnimation tempAnimation;

			aiAnimation* myAnim;

				for (uint32 i = 0; i < myScene->mNumAnimations; i++)
				{
					myAnim = myScene->mAnimations[i];

					
					for (uint32 j = 0; j < myAnim->mChannels[0]->mNumPositionKeys; j++)
					{
						tempAnimation.MyKeyFrames[j].m_Position.X = myAnim->mChannels[0]->mPositionKeys[j].mValue.x;
						tempAnimation.MyKeyFrames[j].m_Position.Y = myAnim->mChannels[0]->mPositionKeys[j].mValue.y;
						tempAnimation.MyKeyFrames[j].m_Position.Z = myAnim->mChannels[0]->mPositionKeys[j].mValue.z;
						
						tempAnimation.MyKeyFrames[j].m_Rotation.m_x = myAnim->mChannels[0]->mRotationKeys[j].mValue.x;
						tempAnimation.MyKeyFrames[j].m_Rotation.m_y = myAnim->mChannels[0]->mRotationKeys[j].mValue.y;
						tempAnimation.MyKeyFrames[j].m_Rotation.m_z = myAnim->mChannels[0]->mRotationKeys[j].mValue.z;
						tempAnimation.MyKeyFrames[j].m_Rotation.m_w = myAnim->mChannels[0]->mRotationKeys[j].mValue.w;

						tempAnimation.MyKeyFrames[j].m_Scale.X = myAnim->mChannels[0]->mScalingKeys[j].mValue.x;
						tempAnimation.MyKeyFrames[j].m_Scale.Y = myAnim->mChannels[0]->mScalingKeys[j].mValue.y;
						tempAnimation.MyKeyFrames[j].m_Scale.Z = myAnim->mChannels[0]->mScalingKeys[j].mValue.z;
						
						tempAnimation.MyKeyFrames[j].m_Time = float(myAnim->mChannels[0]->mPositionKeys[j].mTime);

					}

					tempAnimation.Duration = myAnim->mDuration;
					tempAnimation.m_TicksPerSecond = myAnim->mTicksPerSecond;
					
				}
		}

		

		if (myScene->HasMeshes())
		{
			Vector<aiBone*> myBoneVector;
			//Este ciclo se utiiza para navegar entre los meshes de la escena

			for (uint32 i = 0; i < myScene->mNumMeshes; i++)
			{
				//Guardo el mesh que esta en el espacio actual del arreglo de meshes de la escena, y lo guardo en un mesh temporal
				aiMesh* pMesh = myScene->mMeshes[i];
				//Ahora el mesh temporal lo inserto en mi vector de meshes
				m_Meshes.push_back(new OEAnimationMesh());
				//igualo un mesh temporal al mesh de mi vector de meshes del espacio actul
				OEAnimationMesh& TempMesh = *m_Meshes[i];
	
				
			//	aiAnimation* myAnim = myScene->mAnimations[i];


				//Utilizo un Vertíce Temporal
				VertexAnim TempV;
				OESkeleton tempSkeleton;

				//Este ciclo se utiliza para navegar entre los vertíces del mesh
				for (uint32 j = 0; j < pMesh->mNumVertices; j++)
				{
					//Para alinear la memoria, generar memoria para ser llenado por objetos del tipo Vertex
					memset(&TempV, 0, sizeof(Vertex));

					//Cargar los huesos
					if (pMesh->HasBones())
					{
		//				tempSkeleton.mNumBones=pMesh->mNumBones;

						

						Bone TempBone;// = *myScene->mRootNode;


						//tempSkeleton.AddBone(&tempSkeleton.m_RootNode, &TempBone )
								

						for (uint32 k = 0; k < pMesh->mNumBones; k++)
						{
							TempBone.m_MyName = pMesh->mBones[k]->mName.C_Str();
							TempBone.m_OffsetMatrix.m_Elements.m00 = pMesh->mBones[k]->mOffsetMatrix.a1;
							TempBone.m_OffsetMatrix.m_Elements.m01 = pMesh->mBones[k]->mOffsetMatrix.a2;
							TempBone.m_OffsetMatrix.m_Elements.m02 = pMesh->mBones[k]->mOffsetMatrix.a3;
							TempBone.m_OffsetMatrix.m_Elements.m03 = pMesh->mBones[k]->mOffsetMatrix.a4;
																				   
							TempBone.m_OffsetMatrix.m_Elements.m10 = pMesh->mBones[k]->mOffsetMatrix.b1;
							TempBone.m_OffsetMatrix.m_Elements.m11 = pMesh->mBones[k]->mOffsetMatrix.b2;
							TempBone.m_OffsetMatrix.m_Elements.m12 = pMesh->mBones[k]->mOffsetMatrix.b3;
							TempBone.m_OffsetMatrix.m_Elements.m13 = pMesh->mBones[k]->mOffsetMatrix.b4;
																				   
							TempBone.m_OffsetMatrix.m_Elements.m20 = pMesh->mBones[k]->mOffsetMatrix.c1;
							TempBone.m_OffsetMatrix.m_Elements.m21 = pMesh->mBones[k]->mOffsetMatrix.c2;
							TempBone.m_OffsetMatrix.m_Elements.m22 = pMesh->mBones[k]->mOffsetMatrix.c3;
							TempBone.m_OffsetMatrix.m_Elements.m23 = pMesh->mBones[k]->mOffsetMatrix.c4;
																				   
							TempBone.m_OffsetMatrix.m_Elements.m30 = pMesh->mBones[k]->mOffsetMatrix.d1;
							TempBone.m_OffsetMatrix.m_Elements.m31 = pMesh->mBones[k]->mOffsetMatrix.d2;
							TempBone.m_OffsetMatrix.m_Elements.m32 = pMesh->mBones[k]->mOffsetMatrix.d3;
							TempBone.m_OffsetMatrix.m_Elements.m33 = pMesh->mBones[k]->mOffsetMatrix.d4;

							TempBone.m_NumWeights = pMesh->mBones[k]->mNumWeights;


							for (uint32 h = 0; h < pMesh->mBones[k]->mNumWeights; h++)
							{
								uint32 VertexID = pMesh->mBones[k]->mWeights[h].mVertexId;
								float Weight = pMesh->mBones[k]->mWeights[h].mWeight;

								TempBone.m_VextexIDs.push_back(VertexID);
								TempBone.m_Weights.push_back(Weight);
							}

					
						}
					}


					//Se checa si el vertíce tiene posiciones
					if (pMesh->HasPositions())
					{
						//se Guarda la posición de  los vertices en el temporal, eje por eje (x,y,z)
						//TempV.Position.X = pMesh->
						TempV.Position.X = pMesh-> mVertices[j].x;
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

					//if(pMesh->)

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

						TempV.Color.chanels.R = uint8(pMesh->mColors[0][j].r);
						TempV.Color.chanels.G = uint8(pMesh->mColors[0][j].g);
						TempV.Color.chanels.B = uint8(pMesh->mColors[0][j].b);
						TempV.Color.chanels.A = uint8(pMesh->mColors[0][j].a);
					}

					//Se checa si el vertíce tiene caras

		//			m_Meshes[i].m_VertexAnimationBuffer.
					m_Meshes[i]->m_VertexAnimationBuffer.InsertVertex(TempV);

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


				

				if (pMesh->HasBones())
				{
					for (uint32 j = 0; j < pMesh->mNumBones; j++)
					{
						aiBone* myBone;
						myBone = pMesh->mBones[j];
						bool IsOnList = false;

						
						for (uint32 k = 0; k < myBoneVector.size(); k++)
						{
							if (myBone == myBoneVector[k])
							{
								IsOnList = true;
							}
						}

						if (!IsOnList)
						{

							myBoneVector.push_back(myBone);

							for (uint32 l = 0; l < myBone->mNumWeights; l++)
							{
								//////////////////////////////////////////
								TempV = m_Meshes[i]->m_VertexAnimationBuffer.GetVertexAnim(myBone->mWeights[l].mVertexId);

								for(uint32 m = 0; m < 4; ++m)
								{
									if (TempV.BoneIDs[m] < 0)
									{
										TempV.BoneIDs[m] =static_cast<int32> (myBoneVector.size());
										TempV.BoneWeights[m] = myBone->mWeights[l].mWeight;

										break;
									}

								}
							}


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

			m_Meshes[i]->m_VertexAnimationBuffer.Create(prmDevice, NULL);// m_VertexBuffer.Create(pDevice, NULL);
			m_Meshes[i]->m_IndexBuffer.Create(NULL);

		}

		return true;
	}

	void OEAnimationModel::Render(OEGraphicsDeviceContext* prmDeviceContext)
	{

		for (uint32 i = 0; i < m_Meshes.size(); i++)
		{
			m_Meshes[i]->Render(prmDeviceContext);
		}

	}

	void OEAnimationModel::Release()
	{
	}



}
