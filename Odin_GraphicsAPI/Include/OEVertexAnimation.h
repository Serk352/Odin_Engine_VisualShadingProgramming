#pragma once
#include "OEPrerequisitesGraphics.h"
#include "Vector3f.h"
#include "Vector4f.h"
#include "Vector2f.h"

namespace OE_SDK
{


	class ColorVertex
	{
	public:

		ColorVertex() {};
		~ColorVertex() {};

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


	struct ODIN_ENGINE_GRAPHICS_API_UTILITY_EXPORT VertexAnim
	{
		C_Vector3f  Position;
		ColorVertex Color;
		float BoneWeights[4] = { -1.0f,-1.0f,-1.0f,1.0f };
		int32 BoneIDs[4];
		C_Vector3f  Normal;
		C_Vector2f  TextCoord;
		C_Vector3f  BiTangents;
		C_Vector3f  Tangent;
		
	};
}

