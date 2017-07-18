#include "AddFunction.h"


namespace OE_SDK
{
	//Cosntructor
	AddFunction::AddFunction()
	{

	}
	//Destroyer
	AddFunction::~AddFunction()
	{

	}


	//Function: This function allows
	//esta funcion recibe un numero de parametros y vector de variables, 
	bool AddFunction::AreValidValues(int prmNumOfParameters, Vector<sInputandOutput>& prmVariables)
	{
		//Comparo el número de variables con el 
		//tamaño del vector que contiene las variables que recibí
		if (prmNumOfParameters == prmVariables.size())
		{
			return true;
		}
		else
		{
			return false;
		}


	}

	//Aqui se checa que todos las variables que recibo sean del mismo tipo
	bool AddFunction::AreTheSameVariables(Vector<sInputandOutput>& prmVariables)
	{
		for (uint32 i = 0; i < prmVariables.size() - 1, ++i)
		{
			if (prmVariables[i]->m_Type != prmVariables[i + 1].m_Type)
			{
				return false;
			}
		}
		return true;

	}


	//TO DO: became this function should be a template for all the possibles variables 
	//tha we allow.

	void AddFunction::Functionality(Vector<sInputandOutput>& prmVariables)
	{
		if (AreTheSameVariables(prmVariables))
		{
			switch (prmVariables[0]->m_Type)
			{
			case INTEGER:
				if (prmVariables.size() == 2)
				{
					m_InfoNodo.m_Value = IntegerAdd(reinterpret_cast<int32>(prmVariables[0].m_value),
						reinterpret_cast<int32>(prmVariables[1].m_value))
				}
				if (prmVariables.size() == 3)
				{
					m_InfoNodo.m_Value = IntegerAdd(reinterpret_cast<int32>(prmVariables[0].m_value),
						reinterpret_cast<int32>(prmVariables[1].m_value),
						reinterpret_cast<int32>(prmVariables[2].m_value))
				}
				break;

			case FLOAT:
				if (AreValidValues(2, prmVariables))
				{
					m_InfoNodo.m_Value = FloatAdd(reinterpret_cast<float>(prmVariables[0].m_Value),
						reinterpret_cast<float>(prmVariables[1].m_Value));
				}
				if (AreValidValues(3, prmVariables))
				{
					m_InfoNodo.m_Value = FloatAdd(reinterpret_cast<float>(prmVariables[0].m_Value),
						reinterpret_cast<float>(prmVariables[1].m_Value),
						reinterpret_cast<float>(prmVariables[2].m_Value));
				}
				break;

			case VECTOR2i:
				if (AreValidValues(2, prmVariables))
				{
					m_InfoNodo.m_Value = Vectors2Add(reinterpret_cast<C_Vector2i>(prmVariables[0].m_Value),
						reinterpret_cast<C_Vector2i>(prmVariables[1].m_Value));
				}
				break;

			case VECTOR2f:
				if(AreValidValues(2, prmVariables))
				{
					m_InfoNodo.m_Value = Vectors2Add(reinterpret_cast<C_Vector2i>(prmVariables[0].m_Value),
						reinterpret_cast<C_Vector2f>(prmVariables[1].m_Value));
				}
				break;

			case VECTOR3:
				if (AreValidValues(2, prmVariables))
				{
					m_InfoNodo.m_Value = Vectors3Add(reinterpret_cast<C_Vector3f>(prmVariables[0].m_Value), 
													 reinterpret_cast<C_Vector3f>(prmVariables[1].m_Value))
				}
				break;

			case VECTOR4:
				if (AreValidValues(2, prmVariables))
				{
					m_InfoNodo.m_Value = Vectors3Add(reinterpret_cast<C_Vector4f>(prmVariables[0].m_Value),
						reinterpret_cast<C_Vector4f>(prmVariables[1].m_Value));

				}
				break;


			case MATRIX3x3:
				if (AreValidValues(2, prmVariables))
				{
					m_InfoNodo.m_Value = Matrix3x3Add(reinterpret_cast<C_Matrix3>(prmVariables[0].m_Value),
						)
				}
				break;

			case MATRIX4x4:

				break;

			case TEXTURE:

				break;

			}
		}
	}


	/////////////////////////////////////Integers/////////////////////////////////
	//Two Integers
	void* AddFunction::IntegerAdd(int32 a, int32 b)
	{
		int32 result = a + b;
		return reinterpret_cast<void*> (result);

	}
	//three Integers
	void* AddFunction::IntegerAdd(int32 a, int32 b, int32 c)
	{
		int32 result = a + b + c;
		return reinterpret_cast<void*> (result);

	}

	////////////////////////////////////Floatants/////////////////////////////////
	//Two Float
	void* AddFunction::FloatAdd(float a, float b)
	{
		float result = a + b;
		return reinterpret_cast<void*> (result);
	}
	//three Float
	void* AddFunction::FloatAdd(float a, float b, float c)
	{
		float result = a + b + c;
		return reinterpret_cast<void*> (result);
	}


	
	//////////////////////////////////////Vectors//////////////////////////////////
	//Vector2
	void* AddFunction::Vectors2Add(C_Vector2i a, C_Vector2i b)
	{
		C_Vector2i result = a + b;
		return reinterpret_cast<void*> (result);
	}
	void* AddFunction::Vectors2Add(C_Vector2f a, C_Vector2f b)
	{
		C_Vector2f result = a + b;
		return reinterpret_cast<void*> (result);
	}
	
	//Vector3
	void * AddFunction::Vectors3Add(C_Vector3f a, C_Vector3f b)
	{
		C_Vector3f result = a + b;
		return reinterpret_cast<void*> (result);
	}
	
	//Vector4
	void * AddFunction::Vectors4Add(C_Vector4f a, C_Vector4f b)
	{
		C_Vector4f result = a + b;
		return reinterpret_cast<void*> (result);
	}



	//////////////////////////////////////Matrix//////////////////////////////////
	//Matrix 3x3
	void* AddFunction::Matrix3x3Add(C_Matrix3 a, C_Matrix3 b)
	{
		C_Matrix3 result = a.add(b);
		return reinterpret_cast<void*> (result);
	}
	
	//Matrix 4x4
	void* AddFunction::Matrix4x4Add(C_Matrix4 a, C_Matrix4 b)
	{
		C_Matrix4 result = a.add(b);
		return reinterpret_cast<void*> (result);
	}

	
	//////////////////////////////////////Texture//////////////////////////////////


}