#pragma once
#include "OEPrerequisitesGraphics.h"
#include "OEVertexAnimation.h"
#include "Matrix4.h"
#include "Node.h"

namespace OE_SDK
{
	
	//Primero van los inputs luego los aoutputs en los metodos,
	//los inputs son referencias constantes y los outputs no son referencias constantes


	struct Bone
	{
	public:

		String m_MyName;
		C_Matrix4 m_OffsetMatrix;
		uint32 ID;
		uint32 m_NumWeights;
		uint32 m_NumChildrens;
		Vector<uint32> m_VextexIDs;
		Vector<float> m_Weights;

	};


	class ODIN_ENGINE_GRAPHICS_API_UTILITY_EXPORT OESkeleton
	{
	public:
		
		OESkeleton();
		~OESkeleton();

		int32 m_NumBones;
		
		Node<Bone> m_RootNode;

		

		void AddBone(Node<Bone>* pParent, Node<Bone>* pBone)
		{
			pBone->m_Father = pParent;
			pParent->m_Childrens.push_back(pBone);

			if (pBone->m_Childrens.size() != 0)
			{
				for (auto it = pBone->m_Childrens.begin(); it != pBone->m_Childrens.end(); ++it)
				{
					AddBone(pBone, *it);
				}
			}
		}


	//	Vector<Node<Bone>> m_Bones;
		

	};


}


