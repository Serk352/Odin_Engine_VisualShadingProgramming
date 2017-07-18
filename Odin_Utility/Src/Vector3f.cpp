 #include "Vector3f.h"
#include "MathUtil.h"

namespace OE_SDK
{
	
	/************************************************************************/
	/* Constructores                                                        */
	/************************************************************************/
	C_Vector3f::C_Vector3f()
	{
	}

	C_Vector3f::C_Vector3f(float fX, float fY, float fZ)
	{
		X = fX;
		Y = fY;
		Z = fZ;
	}

	C_Vector3f::~C_Vector3f()
	{

	}


	void C_Vector3f::Negate()
	{
		//C_Vector3f Temp;

		X = -X;
		Y = -Y;
		Z = -Z;


		//return Temp;
	}

	/************************************************************************/
	/* Operadores                                                           */
	/************************************************************************/
	//Producto Cruz
	C_Vector3f C_Vector3f::operator^(const C_Vector3f& RHV)
	{
		return C_Vector3f(((Y*RHV.Z) + (RHV.Y*Z)), -((X*RHV.Z) + (RHV.X*Z)), ((X*RHV.Y) + (RHV.X*Y)));
	}

	float C_Vector3f::operator|(const C_Vector3f& RHV)
	{
		float a;

		a = (X*RHV.X) + (Y*RHV.Y) + (Z*RHV.Z);

		return a;

	}

	C_Vector3f C_Vector3f::DotProduct(const C_Vector3f& Temp)
	{
		float a;
		C_Vector3f reslt;

		a = (X*Temp.X) + (Y*Temp.Y) + (Z*Temp.Z);

		reslt.X = a;
		reslt.Y = a;
		reslt.Z = a;

		return reslt;
	}

	C_Vector3f C_Vector3f::operator+(const C_Vector3f& RHV)
	{
		return C_Vector3f(X + RHV.X, Y + RHV.Y, Z + RHV.Z);
	}

	C_Vector3f C_Vector3f::operator-(const C_Vector3f& RHV)
	{
		return C_Vector3f(X - RHV.X, Y - RHV.Y, Z - RHV.Z);
	}

	//Producto Punto
	C_Vector3f C_Vector3f::operator*(float fEscalar)
	{
		return C_Vector3f(X*fEscalar, Y*fEscalar, Z*fEscalar);

	}





	/************************************************************************/
	/* Métodos                                                              */
	/************************************************************************/
	float C_Vector3f::Magnitude()
	{
		return Math::Sqrt(Math::Square(X) + Math::Square(Y) + Math::Square(Z));
	}

	float C_Vector3f::SquareMagnitude()
	{
		return Math::Square(X) + Math::Square(Y) + Math::Square(Z);
	}

	void C_Vector3f::Normalize(/*C_Vector3f a*/)
	{
		C_Vector3f Result;
		C_Vector3f operando;

		operando.X = X;
		operando.Y = Y;
		operando.Z = Z;

		float fInvMagnitude;

		fInvMagnitude = Math::InverseSqrt(operando.SquareMagnitude());

		Result.X = operando.X * fInvMagnitude;
		Result.Y = operando.Y * fInvMagnitude;
		Result.Z = operando.Z * fInvMagnitude;

		//return   Result;

		X = Result.X;
		Y = Result.Y;
		Z = Result.Z;
	}

	float C_Vector3f::DistanceBTWPoints(const C_Vector3f& RHV)
	{

		float a, b, c, e;
		float fResult;

		a = X - RHV.X;
		b = Y - RHV.Y;
		c = Z - RHV.Z;


		e = Math::Square(a) + Math::Square(b) + Math::Square(c);

		fResult = Math::Sqrt(e);

		return fResult;
	}


}