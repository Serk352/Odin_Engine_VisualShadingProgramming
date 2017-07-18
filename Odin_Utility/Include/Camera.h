#pragma once
#include "PrerequisitesUtil.h"
#include "Matrix4.h"
#include "Vector3f.h"

namespace OE_SDK
{

	class ODIN_ENGINE_UTILITY_EXPORT C_Camera
	{
	public:

		void Paning();
		void Look();

		//C_Matrix4 m_Vista;
		C_Matrix4 m_ProjectionMatrix;
		C_Matrix4 m_ViewMatrix;
			


		C_Matrix4 CreateMAtrixLookTo(C_Vector3f EyePosition, C_Vector3f EyeDirection, C_Vector3f UpDirection);
		C_Matrix4 CreateViewMatrix(C_Vector3f EyePosition, C_Vector3f FocusPosition, C_Vector3f UpDirection);
		void CreateViewMatrixMember(C_Vector3f Eye, C_Vector3f At, C_Vector3f Up);
		void CreateProjectionMatrix(float FieldofViewY, float AspectRatio, float NearZ, float FarZ);
		C_Matrix4 PerpsProjectedSpace(float FovY, float AspectRatio, float ZNear, float ZFar);
		C_Matrix4 LookAtMatrix(C_Vector3f eye, C_Vector3f up, C_Vector3f target);

		C_Camera();
		//C_Camera(float );
		~C_Camera();



	};

}