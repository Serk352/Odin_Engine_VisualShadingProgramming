#pragma once			
#include "C_Node.h"


namespace OE_SDK
{
	class ODIN_ENGINE_VSP_API_UTILITY_EXPORT C_NodeUtileries : public C_Node
	{
	public:
		C_NodeUtileries() {};
		virtual ~C_NodeUtileries();

		//virtual void GetValue(int prmNumOfParameters, sInputandOutput prmVariables[]) = 0;
		//Necesito saber el numero de parametros para saber si el tamaño del vector concuerda con esta
		virtual bool AreValidValues(int prmNumOfParameters, Vector<sInputandOutput>& prmVariables) = 0;
		//Esta función es la que hace la función principal del nodo
		virtual void Functionality(Vector<sInputandOutput>& prmVariables) = 0;
		//Esta función general la salida (interfaz) del nodo actual
		virtual Vector<sInputandOutput>& SetAndSendOutput() = 0;


		//public: cualquier puedo verlos
		//protecte: mis hijos pueden verlas
		//private: solo yo (clase) se de su existencia
	protected:
		//Se usan variables unsigned para los contadores, ya que estos jamas pueden ser negativos
		//al no necesitar un espacio para guardar el signo, esto nos permite almacenar valores más 
		//grandes en la variable.
		uint32 m_numParameters;

	};
}