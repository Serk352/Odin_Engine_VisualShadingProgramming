#include "Matrix3.h"



namespace OE_SDK
{

	/************************************************************************/
	/* Destructor                                                           */
	/************************************************************************/
	C_Matrix3::C_Matrix3()
	{
	}

	C_Matrix3::C_Matrix3(const C_Matrix3& a)
	{
		this->m_row[0] = a.m_row[0];
		this->m_row[1] = a.m_row[1];
		this->m_row[2] = a.m_row[2];
	}

	/************************************************************************/
	/* Destructor                                                           */
	/************************************************************************/
	C_Matrix3::~C_Matrix3()
	{
	}

	/************************************************************************/
	/* Métodos                                                              */
	/************************************************************************/
	void C_Matrix3::add(const C_Matrix3& fMa)
	{

		for (int i = 0; i < 3; i++)
		{

			for (int j = 0; i < 3; i++)
			{
				fMatrix[i][j] = fMatrix[i][j] + fMa.fMatrix[i][j];
			}

		}

	}
	void C_Matrix3::rest(const C_Matrix3& fMa)
	{
	

		for (int i = 0; i < 3; i++)
		{

			for (int j = 0; i < 3; i++)
			{
				fMatrix[i][j] = fMatrix[i][j] - fMa.fMatrix[i][j];
			}

		}


	}
	C_Matrix3 C_Matrix3::mult(const C_Matrix3& fMa)
	{
		
		C_Matrix3 Result;
		


		Result.fMatrix[0][0] = (fMatrix[0][0] * fMa.fMatrix[0][0]) + (fMatrix[0][1]+ fMa.fMatrix[1][0]) + (fMatrix[0][2] * fMa.fMatrix[2][0]);
		Result.fMatrix[0][1] = (fMatrix[0][0] * fMa.fMatrix[0][1]) + (fMatrix[0][1] * fMa.fMatrix[1][1]) + (fMatrix[0][2] * fMa.fMatrix[2][1]);
		Result.fMatrix[0][2] = (fMatrix[0][0] * fMa.fMatrix[0][2]) + (fMatrix[0][1] * fMa.fMatrix[1][2]) + (fMatrix[0][2] * fMa.fMatrix[2][2]);


		Result.fMatrix[1][0] = (fMatrix[1][0] * fMa.fMatrix[0][0]) + (fMatrix[1][1] + fMa.fMatrix[1][0]) + (fMatrix[1][2] * fMa.fMatrix[2][0]);
		Result.fMatrix[1][1] = (fMatrix[1][0] * fMa.fMatrix[0][1]) + (fMatrix[1][1] * fMa.fMatrix[1][1]) + (fMatrix[1][2] * fMa.fMatrix[2][1]);
		Result.fMatrix[1][2] = (fMatrix[1][0] * fMa.fMatrix[0][2]) + (fMatrix[1][1] * fMa.fMatrix[1][2]) + (fMatrix[1][2] * fMa.fMatrix[2][2]);


		Result.fMatrix[2][0] = (fMatrix[2][0] * fMa.fMatrix[0][0]) + (fMatrix[2][1] + fMa.fMatrix[1][0]) + (fMatrix[2][2] * fMa.fMatrix[2][0]);
		Result.fMatrix[2][1] = (fMatrix[2][0] * fMa.fMatrix[0][1]) + (fMatrix[2][1] * fMa.fMatrix[1][1]) + (fMatrix[2][2] * fMa.fMatrix[2][1]);
		Result.fMatrix[2][2] = (fMatrix[2][0] * fMa.fMatrix[0][2]) + (fMatrix[2][1] * fMa.fMatrix[1][2]) + (fMatrix[2][2] * fMa.fMatrix[2][2]);

	
		return Result;
	}

	C_Matrix3 C_Matrix3::transposed(const C_Matrix3& fMa)
	{

		C_Matrix3 Result;

		/*
		00		01		02				00		10		20
		(1)		(2)		(3)				(1)		(4)		(7)

		10		11		12		=		01		11		21
		(4)		(5)		(6)				(2)		(5)		(8)

		20		21		22				02		12		22
		(7)		(8)		(9)				(3)		(6)		(9)
		*/


		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				Result.fMatrix[j][i] = fMa.fMatrix[i][j];
			}
		}


		return Result;
	}
	C_Matrix3 C_Matrix3::MultVector(const C_Matrix3& fMa, const C_Vector3f& v3)
	{

		/*
												00				01			02
		00		01		02			00	      (00*00)		(01*10)		(02*20)

												10				11			12
		10		11		12		*	10   =    (10*00)		(11*10)		(12*20)

												20				21			22
		20		21		22			20	      (20*00)		(21*10)		(22*20)

		*/

		C_Matrix3 Result;


		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (j == 0)
				{
					Result.fMatrix[i][j] = fMa.fMatrix[i][j] * v3.X;
				}
				else if (j == 1)
				{
					Result.fMatrix[i][j] = fMa.fMatrix[i][j] * v3.Y;

				}
				else
				{
					Result.fMatrix[i][j] = fMa.fMatrix[i][j] * v3.Z;

				}

			}
		}


		return Result;

	}


	/************************************************************************/
	/* Operadores                                                           */
	/************************************************************************/

	C_Matrix3 C_Matrix3::operator=(const C_Matrix3& prmV)
	{
		return C_Matrix3(prmV);
	}
}