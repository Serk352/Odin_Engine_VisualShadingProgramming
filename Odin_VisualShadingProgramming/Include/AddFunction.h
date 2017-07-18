#pragma once
#include "C_FunctionNode.h"


namespace OE_SDK
{
	class ODIN_ENGINE_VSP_API_UTILITY_EXPORT AddFunction : public C_FunctionNode  final
	{
		//public: cualquier puedo verlos
		//protecte: mis hijos pueden verlas
		//private: solo yo (clase) se de su existencia
	public:
		AddFunction();
		 ~AddFunction();
		//virtual void GetValue(int prmNumOfParameters, sInputandOutput prmVariables[]) = 0;
		//Necesito saber el numero de parametros para saber si el tamaño del vector concuerda con esta
		bool AreValidValues(int prmNumOfParameters, Vector<sInputandOutput>& prmVariables);

		//Esta función es la que hace la función principal del nodo
		void Functionality(Vector<sInputandOutput>& prmVariables);
		
		bool AreTheSameVariables(Vector<sInputandOutput>& prmVariables);

		//Esta función general la salida (interfaz) del nodo actual
		Vector<sInputandOutput>& SetAndSendOutput();


		//public: cualquier puedo verlos
		//protecte: mis hijos pueden verlas
		//private: solo yo (clase) se de su existencia
	private:

		//Esta clase servira como interfaz para hacer la llamada de las funciones
		//especificas de las operaciones de las variables recibidas

		template<typename T>
		static T AddFunction::Add(const T& a, const T& b) 
		{
			T result = a + b;
			return result;
		}

		/////////////////////////////////////Integers/////////////////////////////////
		//Two Integers
		void* IntegerAdd(int32 a, int32 b);
		//three Integers
		void* IntegerAdd(int32 a, int32 b, int32 c);

		////////////////////////////////////Floatants/////////////////////////////////
		//Two Float
		void* FloatAdd(float a, float b);
		//three Float
		void* FloatAdd(float a, float b, float c);


		//////////////////////////////////////Vectors//////////////////////////////////
		//Vector2
		void* Vectors2Add(C_Vector2i a, C_Vector2i b);
		void* Vectors2Add(C_Vector2f a, C_Vector2f b);
		//Vector3
		void * Vectors3Add(C_Vector3f a, C_Vector3f b);
		//Vector4
		void * Vectors4Add(C_Vector4f a, C_Vector4f b);
			
		//////////////////////////////////////Matrix//////////////////////////////////
		//Matrix 3x3
		void* Matrix3x3Add(C_Matrix3 a, C_Matrix3 b);
		//Matrix 4x4
		void* Matrix4x4Add(C_Matrix4 a, C_Matrix4 b);
		
		//////////////////////////////////////Texture//////////////////////////////////

	};


}