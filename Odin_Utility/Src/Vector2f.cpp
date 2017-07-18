#include "Vector2f.h"
#include "MathUtil.h"

namespace OE_SDK
{


	/************************************************************************/
	/* Constructores                                                        */
	/************************************************************************/
	C_Vector2f::C_Vector2f()
	{
		X = 0;
		Y = 0;

	}

	C_Vector2f::C_Vector2f(float fX, float fY)
	{
		X = fX;
		Y = fY;

	}

	C_Vector2f::C_Vector2f(const C_Vector2f& a)
	{
		this->X = a.X;
		this->Y = a.Y;
	}

	/************************************************************************/
	/* Destructores                                                         */
	/************************************************************************/
	C_Vector2f::~C_Vector2f()
	{
		
	}


	/************************************************************************/
	/* Operadores                                                           */
	/************************************************************************/
	C_Vector2f C_Vector2f::operator|(const C_Vector2f& RHV)
	{
		return C_Vector2f(X * RHV.X, Y * RHV.Y);
	}

	C_Vector2f C_Vector2f::operator+(const C_Vector2f& RHV)
	{
		return C_Vector2f(X + RHV.X, Y + RHV.Y);
	}

	C_Vector2f C_Vector2f::operator-(const C_Vector2f& RHV)
	{
		return C_Vector2f(X - RHV.X, Y - RHV.Y);
	}

	C_Vector2f C_Vector2f::operator*(float fEscalar)
	{
		return C_Vector2f(X*fEscalar, Y*fEscalar);
	}

	C_Vector2f C_Vector2f::operator=(const C_Vector2f& RHV)
	{
		return C_Vector2f(RHV);
	}

/************************************************************************/
/* Miembros				                                                */
/************************************************************************/

	float C_Vector2f::VProduct(const C_Vector2f& RHV)
	{
		float a, b, Result;

		a = X*RHV.Y;
		b = Y*RHV.X;
		Result = a - b;

		return Result;
	}

	float C_Vector2f::VMagnitude()
	{


		return Math::Sqrt(Math::Square(X) + Math::Square(Y));
	}

	float C_Vector2f::SquareMagnitude()
	{
		return Math::Square(X) + Math::Square(Y);
	}

	C_Vector2f	C_Vector2f::Normalize(C_Vector2f a)
	{

		//TODO: Corregir, está normalizandose a si mismo
		C_Vector2f Result;

		float fInvMagnitude = Math::InverseSqrt(a.SquareMagnitude());

		Result.X = a.X * fInvMagnitude;
		Result.Y = a.Y * fInvMagnitude;
	
		return   Result;
	}

}