#pragma once

#include "PrerequisitesUtil.h"

namespace OE_SDK
{
	class ODIN_ENGINE_UTILITY_EXPORT C_Vector3f
	{
	public:

		float X;
		float Y;
		float Z;




		//Producto Cruz
		C_Vector3f operator^(const C_Vector3f& RHV);
		
		//Producto Punto
		float operator|(const C_Vector3f& RHV);
		
		//Suma de Vectores
		C_Vector3f operator+(const C_Vector3f& RHV);
		//Resta de Vectores				
		C_Vector3f operator-(const C_Vector3f& RHV);

		C_Vector3f& operator=(const C_Vector3f& RHV)
		{
			X = RHV.X;
			Y = RHV.Y;
			Z = RHV.Z;

			return *this;
		}


		//C_Vector3f VectorSelect(C_Vector3f V1, C_Vector3f V2, C_Vector3f Control);

		//Producto punto con replicacion en cada vector

		C_Vector3f DotProduct(const C_Vector3f& Temp);

		//falta división

		//Multiplicación
		C_Vector3f operator*(float fEscalar);


		//
		float Magnitude();
		//
		float SquareMagnitude();
		//
		//C_Vector3f Normalize(/*C_Vector3f a*/);
		
		void Normalize();
		//
		float DistanceBTWPoints(const C_Vector3f& RHV);


		//
		void Negate();


		C_Vector3f();
		C_Vector3f(float fX, float fY, float fZ);
		//Constructor de copia
		//C_Vector3f(const C_Vector3f& ref)
		~C_Vector3f();


	};

}