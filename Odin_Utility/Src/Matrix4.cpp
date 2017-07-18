#include "Matrix4.h"

namespace OE_SDK
{

	C_Matrix4::C_Matrix4()
	{
	}


	C_Matrix4::C_Matrix4(float a, float b, float c, float d, float e, float f, float g, float h, float i, float j, float k, float l, float m, float n, float o, float p)
	{
		fMatrix[0][0] = a;
		fMatrix[0][1] = b;
		fMatrix[0][2] = c;
		fMatrix[0][3] = d;

		fMatrix[1][0] = e;
		fMatrix[1][1] = f;
		fMatrix[1][2] = g;
		fMatrix[1][3] = h;

		fMatrix[2][0] = i;
		fMatrix[2][1] = j;
		fMatrix[2][2] = k;
		fMatrix[2][3] = l;

		fMatrix[3][0] = m;
		fMatrix[3][1] = n;
		fMatrix[3][2] = o;
		fMatrix[3][3] = p;
	}

	C_Matrix4::C_Matrix4(C_Vector4f* a, C_Vector4f* b, C_Vector4f* c, C_Vector4f* d)
	{
		fMatrix[0][0] = a->X_Axis;
		fMatrix[0][1] = a->Y_Axis;
		fMatrix[0][2] = a->Z_Axis;
		fMatrix[0][3] = a->W_Axis;
						 
		fMatrix[1][0] = b->X_Axis;
		fMatrix[1][1] = b->Y_Axis;
		fMatrix[1][2] = b->Z_Axis;
		fMatrix[1][3] = b->W_Axis;
						 
		fMatrix[2][0] = c->X_Axis;
		fMatrix[2][1] = c->Y_Axis;
		fMatrix[2][2] = c->Z_Axis;
		fMatrix[2][3] = c->W_Axis;
						 
		fMatrix[3][0] = d->X_Axis;
		fMatrix[3][1] = d->Y_Axis;
		fMatrix[3][2] = d->Z_Axis;
		fMatrix[3][3] = d->W_Axis;
	}



	//Si una funcion es constante no puede mover el contenido de la clase

	C_Matrix4::C_Matrix4(const C_Matrix4& a)
	{
		fMatrix[0][0] = a.fMatrix[0][0];
		fMatrix[0][1] = a.fMatrix[0][1];
		fMatrix[0][2] = a.fMatrix[0][2];
		fMatrix[0][3] = a.fMatrix[0][3];

		fMatrix[1][0] = a.fMatrix[1][0];
		fMatrix[1][1] = a.fMatrix[1][1];
		fMatrix[1][2] = a.fMatrix[1][2];
		fMatrix[1][3] = a.fMatrix[1][3];

		fMatrix[2][0] = a.fMatrix[2][0];
		fMatrix[2][1] = a.fMatrix[2][1];
		fMatrix[2][2] = a.fMatrix[2][2];
		fMatrix[2][3] = a.fMatrix[2][3];

		fMatrix[3][0] = a.fMatrix[3][0];
		fMatrix[3][1] = a.fMatrix[3][1];
		fMatrix[3][2] = a.fMatrix[3][2];
		fMatrix[3][3] = a.fMatrix[3][3];
	}




	C_Matrix4::~C_Matrix4()
	{
	}


	void  C_Matrix4::add(const C_Matrix4& fMa)
	{
		

		for (int i = 0; i < 4; i++)
		{

			for (int j = 0; i < 4; i++)
			{
				fMatrix[i][j] = fMatrix[i][j] + fMa.fMatrix[i][j];
			}

		}


	}
	void C_Matrix4::rest(const C_Matrix4& fMa)
	{
		

		for (int i = 0; i < 4; i++)
		{

			for (int j = 0; i < 4; i++)
			{
				fMatrix[i][j] = fMatrix[i][j] - fMa.fMatrix[i][j];
			}

		}

		
	}
	C_Matrix4 C_Matrix4::mult(const C_Matrix4& fMa)
	{

		C_Matrix4 Result;

		Result.fMatrix[0][0] = (fMatrix[0][0] * fMa.fMatrix[0][0]) + (fMatrix[0][1] + fMa.fMatrix[1][0]) + (fMatrix[0][2] * fMa.fMatrix[2][0]);
		Result.fMatrix[0][1] = (fMatrix[0][0] * fMa.fMatrix[0][1]) + (fMatrix[0][1] * fMa.fMatrix[1][1]) + (fMatrix[0][2] * fMa.fMatrix[2][1]);
		Result.fMatrix[0][2] = (fMatrix[0][0] * fMa.fMatrix[0][2]) + (fMatrix[0][1] * fMa.fMatrix[1][2]) + (fMatrix[0][2] * fMa.fMatrix[2][2]);
		Result.fMatrix[0][3] = (fMatrix[0][0] * fMa.fMatrix[0][3]) + (fMatrix[0][1] * fMa.fMatrix[1][3]) + (fMatrix[0][2] * fMa.fMatrix[2][3]);


		Result.fMatrix[1][0] = (fMatrix[1][0] * fMa.fMatrix[0][0]) + (fMatrix[1][1] + fMa.fMatrix[1][0]) + (fMatrix[1][2] * fMa.fMatrix[2][0]);
		Result.fMatrix[1][1] = (fMatrix[1][0] * fMa.fMatrix[0][1]) + (fMatrix[1][1] * fMa.fMatrix[1][1]) + (fMatrix[1][2] * fMa.fMatrix[2][1]);
		Result.fMatrix[1][2] = (fMatrix[1][0] * fMa.fMatrix[0][2]) + (fMatrix[1][1] * fMa.fMatrix[1][2]) + (fMatrix[1][2] * fMa.fMatrix[2][2]);
		Result.fMatrix[1][3] = (fMatrix[1][0] * fMa.fMatrix[0][3]) + (fMatrix[1][1] * fMa.fMatrix[1][3]) + (fMatrix[1][2] * fMa.fMatrix[2][3]);


		Result.fMatrix[2][0] = (fMatrix[2][0] * fMa.fMatrix[0][0]) + (fMatrix[2][1] + fMa.fMatrix[1][0]) + (fMatrix[2][2] * fMa.fMatrix[2][0]);
		Result.fMatrix[2][1] = (fMatrix[2][0] * fMa.fMatrix[0][1]) + (fMatrix[2][1] * fMa.fMatrix[1][1]) + (fMatrix[2][2] * fMa.fMatrix[2][1]);
		Result.fMatrix[2][2] = (fMatrix[2][0] * fMa.fMatrix[0][2]) + (fMatrix[2][1] * fMa.fMatrix[1][2]) + (fMatrix[2][2] * fMa.fMatrix[2][2]);
		Result.fMatrix[2][3] = (fMatrix[2][0] * fMa.fMatrix[0][3]) + (fMatrix[2][1] * fMa.fMatrix[1][3]) + (fMatrix[2][2] * fMa.fMatrix[2][3]);


		return Result;

	}



	void C_Matrix4::Transposed()
	{
		C_Matrix4 Temp;


		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				Temp.fMatrix[i][j] = fMatrix[i][j];
			}
		}
		



		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				fMatrix[j][i] = Temp.fMatrix[i][j];
			}
		}
	}



	void C_Matrix4::operator=(const C_Matrix4& a)
	{

		fMatrix[0][0] = a.fMatrix[0][0];
		fMatrix[0][1] = a.fMatrix[0][1];
		fMatrix[0][2] = a.fMatrix[0][2];
		fMatrix[0][3] = a.fMatrix[0][3];

		fMatrix[1][0] = a.fMatrix[1][0];
		fMatrix[1][1] = a.fMatrix[1][1];
		fMatrix[1][2] = a.fMatrix[1][2];
		fMatrix[1][3] = a.fMatrix[1][3];

		fMatrix[2][0] = a.fMatrix[2][0];
		fMatrix[2][1] = a.fMatrix[2][1];
		fMatrix[2][2] = a.fMatrix[2][2];
		fMatrix[2][3] = a.fMatrix[2][3];

		fMatrix[3][0] = a.fMatrix[3][0];
		fMatrix[3][1] = a.fMatrix[3][1];
		fMatrix[3][2] = a.fMatrix[3][2];
		fMatrix[3][3] = a.fMatrix[3][3];
	}


/*
	C_Matrix4 C_Matrix4::Transposed(const C_Matrix4& fMa)
	{
		C_Matrix4 Result;

		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				Result.fMatrix[j][i] = fMa.fMatrix[i][j];
			}
		}


		return Result;
	}*/

}