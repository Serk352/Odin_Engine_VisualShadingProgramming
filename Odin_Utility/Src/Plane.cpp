#include "Plane.h"

namespace OE_SDK
{

	C_Plane::C_Plane()
	{
	}


	C_Plane::C_Plane(C_Vector3f P0, C_Vector3f P1, C_Vector3f P2)
	{
		ComputeFromPoints(P0, P1, P2);

	}

	C_Plane::~C_Plane()
	{
	}



	/*void C_Plane::GetNormal()
	{
		C_Vector3f K1;
		C_Vector3f K2;

		K1 = K1.VSubtraction(m_Point1,m_Point0);
		K2 = K2.VSubtraction(m_Point2, m_Point0);


		C_Vector3f a = a.CrossProduct(K1, K2);

		//Normal del plano
		m_fNormal = a.Normalize(a); 


		//Distancia hacia el origen
		float d = -(a.PointProduct(a, m_Point0));


	}
	*/

	void C_Plane::ComputeFromPoints(C_Vector3f P0, C_Vector3f P1, C_Vector3f P2)
	{
		C_Plane Plane;

		C_Vector3f K1;
		C_Vector3f K2;

		K1 = P1-P0;
		K2 = P2-P0;

		C_Vector3f a = K1^K2;

		//Normal del plano
		a.Normalize();
		C_Vector3f planeNormal = a;
		X = planeNormal.X;
		Y = planeNormal.Y;
		Z = planeNormal.Z;
		W = a | P0;
	}

}