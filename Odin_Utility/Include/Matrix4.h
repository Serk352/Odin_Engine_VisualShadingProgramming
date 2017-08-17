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

		static C_Matrix4 CreateRotateXMatrix(float Angle)
		{

			float a11 = PlatformMath::Cos(Angle);
			float a12 = -(PlatformMath::Sin(Angle));
			float a21 = PlatformMath::Sin(Angle);
			float a22 = a11;

			C_Vector4f a = C_Vector4f(1, 0,   0,   0);
			C_Vector4f b = C_Vector4f(0, a11,  a21, 0);
			C_Vector4f c = C_Vector4f(0, a12, a22, 0);
			C_Vector4f d = C_Vector4f(0, 0, 0,   1);

			return C_Matrix4(&a,&b,&c,&d);
		}


		static C_Matrix4 CreateRotateYMatrix(float Angle)
		{

			float a00 = PlatformMath::Cos(Angle);
			float a02 = PlatformMath::Sin(Angle);
			float a20 = -(PlatformMath::Sin(Angle));
			float a22 = a00;

			C_Vector4f a = C_Vector4f(a00, 0, a02, 0);
			C_Vector4f b = C_Vector4f(0, 1, 0, 0);
			C_Vector4f c = C_Vector4f(a20, 0, a22, 0);
			C_Vector4f d = C_Vector4f(0, 0, 0, 1);
			
			return C_Matrix4(&a, &b, &c, &d);

		}

		static C_Matrix4 CreateRotateZMatrix(float Angle)
		{
			float a00 = PlatformMath::Cos(Angle);
			float a01 = -(PlatformMath::Sin(Angle));
			float a10 = PlatformMath::Sin(Angle);
			float a11 = a00;

			C_Vector4f a = C_Vector4f(a00, a10, 0, 0);
			C_Vector4f b = C_Vector4f(a01, a11, 0, 0);
			C_Vector4f c = C_Vector4f(0,	 0, 1, 0);
			C_Vector4f d = C_Vector4f(0,	 0, 0, 1);

			return C_Matrix4(&a, &b, &c, &d);
		}

		static C_Matrix4 CreateScaleMatrix(float ScalarX, float ScalarY, float ScalarZ)
		{

			C_Vector4f a = C_Vector4f(ScalarX, 0, 0, 0);
			C_Vector4f b = C_Vector4f(0, ScalarY, 0, 0);
			C_Vector4f c = C_Vector4f(0, 0, ScalarZ, 0);
			C_Vector4f d = C_Vector4f(0, 0, 0, 1);

			return C_Matrix4(&a, &b, &c, &d);
		}

		static C_Matrix4 CreateTranslateMatrix(float X, float Y, float Z)
		{
			C_Vector4f a = C_Vector4f(1, 0, 0, X);
			C_Vector4f b = C_Vector4f(0, 1, 0, Y);
			C_Vector4f c = C_Vector4f(0, 0, 1, Z);
			C_Vector4f d = C_Vector4f(0, 0, 0, 1);


			return C_Matrix4(&a, &b, &c, &d);	
		}

		C_Matrix4();
		//C_Matrix4(C_Matrix4 a);
		C_Matrix4(float a, float b, float c, float d, float e, float f, float g, float h, float i, float j, float k, float l, float m, float n, float o, float p);
		C_Matrix4(C_Vector4f* a, C_Vector4f* b, C_Vector4f* c, C_Vector4f* d);
		C_Matrix4(const C_Matrix4& a);
		~C_Matrix4();

	}GCC_ALIGN(64);
}
