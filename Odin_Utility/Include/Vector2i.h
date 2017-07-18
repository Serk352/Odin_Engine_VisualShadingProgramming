#pragma once
#include "PrerequisitesUtil.h"

namespace OE_SDK
{
	class ODIN_ENGINE_UTILITY_EXPORT C_Vector2i
	{
	public:
		
		int32 X;
		int32 Y;

		//Producto Punto
	//	C_Vector2i operator|(const C_Vector2i& RHV);
		//C_Vector2i PointProduct(C_Vector2i vfA, C_Vector2i vfB);

		//Suma de Vectores
// 		//C_Vector2i operator+(const C_Vector2i& RHV);
// 
// 		//Resta de Vectores
// 		C_Vector2i operator-(const C_Vector2i& RHV);
// 
// 		//Producto Escalar (Multiplicación)
// 		C_Vector2i operator*(int fEscalar);


		C_Vector2i operator|(const C_Vector2i& RHV);
											
		//Suma de Vectores					
		C_Vector2i operator+(const C_Vector2i& RHV);
											
		//Resta de Vectores					
		C_Vector2i operator-(const C_Vector2i& RHV);

		//Producto Escalar (Multiplicación)
		C_Vector2i operator*(int32 fEscalar);

		//Igualar a los valores de otro vector
		C_Vector2i operator=(const C_Vector2i& a);

		int32 VProduct(C_Vector2i vfA, C_Vector2i vfB);
		int32 Vmagnitude();
		C_Vector2i Normalize(C_Vector2i a);

		C_Vector2i();
		C_Vector2i(int32 iX, int32 iY);
		C_Vector2i(const C_Vector2i& a);
		~C_Vector2i();


	};
}