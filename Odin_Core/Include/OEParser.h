#pragma once
#include "OEPrerequisitesCore.h"

namespace OE_SDK
{
	
	class ODIN_ENGINE_COREUTILITY_EXPORT C_OdinParser
	{
	public:
		C_OdinParser();
		~C_OdinParser();

		template <class T>

		T Parser(String OriginalStr, char Token, int32 index)
		{
			 		String ReturnStr = OriginalStr;
			 
			 		char* Space = " ";
			 
			 		if (index <= 0)
			 		{
			 			return NULL;
			 		}
			 
			 		do
			 		{
			 			ReturnStr = strstr(OriginalStr.c_str(), &Token);
			 			strncpy(&OriginalStr[OriginalStr.size() - ReturnStr.size()], Space, 1);
			 			index--;
			 
			 		} while (index > 0);
			 
			return OriginalStr;

		}


	};
}