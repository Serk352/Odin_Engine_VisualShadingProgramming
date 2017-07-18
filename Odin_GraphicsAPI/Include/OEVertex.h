#pragma once
#include "OEPrerequisitesGraphics.h"
#include "Vector2f.h"
#include "Vector3f.h"
#include "Vector4f.h"


namespace OE_SDK
{

	class Color
	{
	public:
			
		Color()	{};
		~Color() {};
		
		union
		{
			struct 
			{
				uint8 R;
				uint8 G;
				uint8 B;
				uint8 A;
			} chanels;
			int32 color;
			//uint8 arraychanels[4];
		};
	};


	struct ODIN_ENGINE_GRAPHICS_API_UTILITY_EXPORT Vertex
	{
		//Position : vector 3
		//Color:	 vector 4
		//Normal:    vector 3
		//TextCoord: vector 2f
		//BiTangents vector 3
		//Tangent	 vector 3

		C_Vector3f Position;
		Color	color;
		//float ColorChanel[4];
		//	C_Vector4f Color;
		C_Vector3f Normal;
		C_Vector2f TextCoord;
		C_Vector3f BiTangents;
		C_Vector3f Tangent;
	};

}