#pragma once
#include "PrerequisitesUtil.h"
#include "PlatformMath.h"
#include "Vector4f.h"

namespace OE_SDK
{

	MS_ALIGN(64) class ODIN_ENGINE_UTILITY_EXPORT C_Matrix4
	{
	public:

		//float fMatrix[4][4];


		union 
		{
			C_Vector4f m_row[4];
			float fMatrix[4][4];
			float m_Linear[16];

			struct 
			{
				float m00, m01, m02, m03,
					m10, m11, m12, m13,
					m20, m21, m22, m23,
					m30, m31, m32, m33;
			}m_Elements;

		};



		void add(const C_Matrix4& fMa);//, const C_Matrix4& fMb);
		void rest(const C_Matrix4& fMa);//, const C_Matrix4& fMb);
		C_Matrix4 mult(const C_Matrix4& fMa); //C_Matrix4& fMb);
		
		void Transposed();//const C_Matrix4& fMa);
		//C_Matrix4 Transposed(const C_Matrix4& fMa);


		void operator=(const C_Matrix4& a);


		C_Matrix4();
		//C_Matrix4(C_Matrix4 a);
		C_Matrix4(float a, float b, float c, float d, float e, float f, float g, float h, float i, float j, float k, float l, float m, float n, float o, float p);
		C_Matrix4(C_Vector4f* a, C_Vector4f* b, C_Vector4f* c, C_Vector4f* d);
		C_Matrix4(const C_Matrix4& a);
		~C_Matrix4();

	}GCC_ALIGN(64);
}
