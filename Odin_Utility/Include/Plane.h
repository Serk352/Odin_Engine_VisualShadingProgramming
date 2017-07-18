#pragma once
#include "PrerequisitesUtil.h"
#include "Vector3f.h"

namespace OE_SDK 
{

	class ODIN_ENGINE_UTILITY_EXPORT C_Plane : public C_Vector3f
	{

	public:
		C_Plane();
		//To Do:
		//Convertir los parametros de objetos a referencias, cuando se tengan las constantes
		C_Plane(C_Vector3f P0, C_Vector3f P1, C_Vector3f P2);
		~C_Plane();

		void ComputeFromPoints(C_Vector3f P0, C_Vector3f P1, C_Vector3f P2);

		float W;
	};


}//aplicacio