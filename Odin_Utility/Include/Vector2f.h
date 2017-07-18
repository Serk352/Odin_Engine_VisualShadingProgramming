#pragma once
#include "PrerequisitesUtil.h"

namespace OE_SDK
{
	class ODIN_ENGINE_UTILITY_EXPORT C_Vector2f
	{
	public:

		float X;
		float Y;
	
		//Producto Punto
		C_Vector2f operator|(const C_Vector2f& RHV);	

		//Suma de Vectores
		C_Vector2f operator+(const C_Vector2f& RHV);

		//Resta de Vectores
		C_Vector2f operator-(const C_Vector2f& RHV);

		//Producto Escalar (Multiplicación)
		C_Vector2f operator*(float fEscalar);
		//Igualar a otro vector
		C_Vector2f operator=(const C_Vector2f& RHV);

		//
		float VProduct(const C_Vector2f& RHV);
		//
		float SquareMagnitude();
		//
		float VMagnitude();
		//
		C_Vector2f Normalize(C_Vector2f a);


		C_Vector2f();
		C_Vector2f(float fX, float fY);
		C_Vector2f(const C_Vector2f&);
		~C_Vector2f();

	};

}
