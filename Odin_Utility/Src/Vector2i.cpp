
#include "Vector2i.h"

namespace OE_SDK
{

/************************************************************************/
/* Constructores                                                        */
/************************************************************************/
	C_Vector2i::C_Vector2i()
	{
		X = 0;
		Y = 0;
	}

	C_Vector2i::C_Vector2i(int32 fX, int32 fY)
	{
		X = fX;
		Y = fY;

	}

	C_Vector2i::C_Vector2i(const C_Vector2i& a)
	{
		this->X = a.X;
		this->Y = a.Y;
	}

	/************************************************************************/
	/* Destructor                                                           */
	/************************************************************************/
	C_Vector2i::~C_Vector2i()
	{

	}


/************************************************************************/
/*Operadores                                                            */
/************************************************************************/
	
	//Producto Punto
	C_Vector2i C_Vector2i::operator|(const C_Vector2i& RHV)
	{
		return C_Vector2i(X * RHV.X, Y * RHV.Y);
	}

	
	//Suma de Vectores					
	C_Vector2i C_Vector2i::operator+(const C_Vector2i& RHV)
	{
		return C_Vector2i(X + RHV.X, Y + RHV.Y);
	}



	//Resta de Vectores					
	C_Vector2i C_Vector2i::operator-(const C_Vector2i& RHV)
	{
		return C_Vector2i(X - RHV.X, Y - RHV.Y);
	}

 
	//Producto Escalar (Multiplicación)
	C_Vector2i C_Vector2i::operator*(int32 fEscalar)
	{
		return C_Vector2i(X*fEscalar, Y*fEscalar);
	}


	//Igualar a los valores de otro vector
	C_Vector2i C_Vector2i::operator=(const C_Vector2i& a)
	{
		return C_Vector2i(a);
	}



	/************************************************************************/
	/* Métodos                                                              */
	/************************************************************************/

	int32 C_Vector2i::VProduct(C_Vector2i vfA, C_Vector2i vfB)
	{

		//Esta función devuelve el valor del tercer eje de vectores de dos ejes
		int32 fResult;
		int32 a, b;

		//Para esto se utiliza una matríz de 3x3
		/*
		|x		|y		|z
		a*b	=	|a.x	|b.x	|0  = (a.x *b.y) - (a.y - b.x)
		|a.y	|b.y	|0
		*/

		a = vfA.X*vfB.Y;
		b = vfA.Y*vfB.X;

		fResult = a - b;

		return fResult;

	}

	/*float OdinEngine::C_Vector2i::ScalarProduct(C_Vector2i vfA, C_Vector2i vfB, float fAng)
	{}
	*/

	int32  C_Vector2i::Vmagnitude()
	{
		int32 a, b, c;

		int32 iMagnitude;

		a = X*X;
		b = Y*Y;

		c = a + b;

		iMagnitude = (int32)std::sqrt(c);


		return iMagnitude;
	}
	/*
	void OdinEngine::C_Vector2i::VMagnitude()
	{
		/*
		int32 a;
		int32 b;
		int32 c;

		a = (X_Axis)*(X_Axis);
		b = (Y_Axis)*(Y_Axis);


		c = a + b;

		iMagnitude
		iMagnitude = std


		int32 a, b, c;

		a= X_Axis*X_Axis
	}*/

	C_Vector2i C_Vector2i::Normalize(C_Vector2i a)
	{

		C_Vector2i vResult;
		int32 iMagnitude = a.Vmagnitude();

		vResult.X = a.X / iMagnitude;
		vResult.Y = a.Y / iMagnitude;

		return vResult;

	}

}