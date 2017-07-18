#include "Vector4f.h"


namespace OE_SDK
{

	/************************************************************************/
	/* Cosntructores                                                        */
	/************************************************************************/
	C_Vector4f::C_Vector4f()
	{
	}

	C_Vector4f::C_Vector4f(float fX, float fY, float fZ, float fW)
	{
		X_Axis = fX;
		Y_Axis = fY;
		Z_Axis = fZ;
		W_Axis = fW;
	}

	C_Vector4f::C_Vector4f(const C_Vector4f& a)
	{
		this->X_Axis = a.X_Axis;
		this->Y_Axis = a.Y_Axis;
		this->Z_Axis = a.Z_Axis;
		this->W_Axis = a.W_Axis;
	}

	/************************************************************************/
	/* Destructor                                                           */
	/************************************************************************/
	C_Vector4f::~C_Vector4f()
	{
	}

	/*OdinEngine::C_Vector4f OdinEngine::C_Vector4f::CrossProduct(const C_Vector4f&  vfA, const C_Vector4f&  vfB)
	{
		return C_Vector4f();
	}*/




	float C_Vector4f::operator|(const C_Vector4f& prmV)
	{
		float Result;

		Result = (X_Axis * prmV.X_Axis) + (Y_Axis * prmV.Y_Axis) + (Z_Axis * prmV.Z_Axis) + (W_Axis * prmV.W_Axis);

		return Result;
	}




	C_Vector4f C_Vector4f::operator+(const C_Vector4f& prmV)
	{
		return	C_Vector4f((X_Axis + prmV.X_Axis), (Y_Axis + prmV.Y_Axis), (Z_Axis + prmV.Z_Axis), (W_Axis + prmV.W_Axis));

	}


	C_Vector4f C_Vector4f::operator-(const C_Vector4f& prmV)
	{
		return	C_Vector4f((X_Axis - prmV.X_Axis), (Y_Axis - prmV.Y_Axis), (Z_Axis - prmV.Z_Axis), (W_Axis - prmV.W_Axis));

	}

	
	C_Vector4f C_Vector4f::operator/(const C_Vector4f& prmV)
	{
		return C_Vector4f(X_Axis / prmV.X_Axis, Y_Axis / prmV.Y_Axis, Z_Axis / prmV.Z_Axis, W_Axis / prmV.W_Axis);
	}

	//Debe escalar el vector

	C_Vector4f C_Vector4f::operator*(float prmEscalar)
	{
		return C_Vector4f(X_Axis*prmEscalar, Y_Axis*prmEscalar, Z_Axis*prmEscalar, W_Axis*prmEscalar);
	}

	//Iguala a otro vector
	C_Vector4f& C_Vector4f::operator=(const C_Vector4f& prmV)
	{
		this->X_Axis = prmV.X_Axis;
		this->Y_Axis = prmV.Y_Axis;
		this->Z_Axis = prmV.Z_Axis;
		this->W_Axis = prmV.W_Axis;
		return *this;
	}

	

	float C_Vector4f::vMagnitude()
	{
		float a;
		float b;
		float c;
		float d;

		float Result;
		float fMagnitude;

		a = X_Axis *X_Axis;
		b = Y_Axis *Y_Axis;
		c = Z_Axis *Z_Axis;
		d = W_Axis *W_Axis;

	//	Result = 
		Result = a + b + c + d;
	
		
		fMagnitude = std::sqrtf(Result);
		
		return fMagnitude;

	}





	C_Vector4f C_Vector4f::Normalize( C_Vector4f& a)
	{
		C_Vector4f Result;

		//a.VDivision(Result);

		float fMagnitude = a.vMagnitude();

		Result.X_Axis = a.X_Axis / fMagnitude;
		Result.Y_Axis = a.Y_Axis / fMagnitude;
		Result.Z_Axis = a.Z_Axis / fMagnitude;
		Result.W_Axis = a.W_Axis / fMagnitude;

		return   Result;

	}


				  												

			  												
	
			  												



}