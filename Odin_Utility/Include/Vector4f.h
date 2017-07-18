#pragma once
#include "PrerequisitesUtil.h"


namespace OE_SDK
{

	class ODIN_ENGINE_UTILITY_EXPORT C_Vector4f
	{
	public:
		float X_Axis;
		float Y_Axis;
		float Z_Axis;
		float W_Axis;

		//float PointProduct(const C_Vector4f&  vfA);
		float operator|(const C_Vector4f& prmV);

		//C_Vector4f VAddition(const C_Vector4f&  vfA);		
		//Suma de vectores
		C_Vector4f operator+(const C_Vector4f& prmV);
		
		//Resta de vectores
		C_Vector4f operator-(const C_Vector4f& prmV);

		//Igualar a otro Vector 4
		C_Vector4f& operator=(const C_Vector4f& prmV);
//		C_Vector4f VSubtraction(const C_Vector4f&  vfA);



		//falta división
		// V1/V2  = X1/x2, Y1/Y2, Z1*Z2, W1/W2
	//	C_Vector4f VDivision(const C_Vector4f&  vfA);
			// V1/S  = V1* (1.0 / S)
		C_Vector4f operator/(const C_Vector4f& prmV);


		C_Vector4f operator*( float prmEscalar);
		//float VProduct(C_Vector4f vfA, C_Vector4f vfB);

		float vMagnitude();

		C_Vector4f Normalize( C_Vector4f&  a);


		C_Vector4f();
		C_Vector4f(float fX, float fY, float fZ, float fW);
		C_Vector4f(const C_Vector4f& a);
		~C_Vector4f();

	};

}