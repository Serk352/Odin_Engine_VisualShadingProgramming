#pragma once
#include "PrerequisitesUtil.h"

namespace OE_SDK
{
	template<typename T>
	struct Node
	{
		
		Node<T>* m_Father;
		T m_Data;
		List< Node<T>* > m_Childrens;

	};
}