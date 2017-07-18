#pragma once
#include "PrerequisitesVSP.h"


namespace OE_SDK
{
		  
	class ODIN_ENGINE_VSP_API_UTILITY_EXPORT C_Node
	{
		public:

			C_Node() {};
			~C_Node() {};
			

			enum eVariables
			{
				INTEGER,
				FLOAT,
				VECTOR2i,
				VECTOR2f,
				VECTOR3,
				VECTOR4,
				MATRIX3x3,
				MATRIX4x4,
				TEXTURE
			};
			

			struct sInputandOutput
			{
				eVariables m_Type;
				String m_Name;
				void* m_Value;
			};

			//Las posiciones cartesianas de cada nodo en el espacio de trabajo (pantalla) 
			//int m_PosX;
			//int m_PosY;

			//virtual void GetValue(int prmNumOfParameters, sInputandOutput prmVariables[]) = 0;
			//Necesito saber el numero de parametros para saber si el tamaño del vector concuerda con esta
			virtual bool GetValues(int prmNumOfParameters, Vector<sInputandOutput>& prmVariables) = 0;
			//Esta función es la que hace la función principal del nodo
			virtual void Functionality() = 0;
			//Esta función general la salida (interfaz) del nodo actual
			virtual Vector<sInputandOutput>& SetAndSendOutput() = 0;
		
		protected:
		//Aqui guardo lo que es y contiene este nodo
		Vector<sInputandOutput> m_InfoNodo;

	};
}