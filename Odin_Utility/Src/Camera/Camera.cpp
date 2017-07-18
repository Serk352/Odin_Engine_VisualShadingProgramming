#include "Camera.h"
#include "PlatformMath.h"
#include "Vector4f.h"

namespace OE_SDK
{
	C_Camera::C_Camera()
	{

	}

	C_Camera::~C_Camera()
	{


	}


	C_Matrix4 C_Camera::CreateMAtrixLookTo(C_Vector3f EyePosition, C_Vector3f EyeDirection, C_Vector3f UpDirection)
	{
		if (!(EyePosition.X == 0.0f && EyePosition.Y == 0.0f && EyePosition.Z == 0.0f))
		{
			if (!(EyeDirection.X == 0.0f && EyeDirection.Y == 0.0f && EyeDirection.Z == 0.0f))
			{
				if (!(UpDirection.X == 0.0f && UpDirection.Y == 0.0f && UpDirection.Z == 0.0f))
				{
					//Dirección de vista
					EyeDirection.Normalize();
					C_Vector3f R2 = EyeDirection;

					//Vector para el vector perpendicular a la vista y a arriba
					C_Vector3f R0;// = UpDirection.operator^(R2);
					R0 = UpDirection^R2;

					//Se normaliza para tener solamente la dirección
					R0.Normalize();

					//Vector que apunta a hacia arriba
					C_Vector3f R1 = R2^R0;

					//se niega para volverla de mano izquierda
					/*C_Vector3f NegEyePosition =*/
					EyePosition.Negate();


					C_Vector3f D0 = R0.DotProduct(EyePosition);

					C_Vector3f D1 = R1.DotProduct(EyePosition);

					C_Vector3f D2 = R2.DotProduct(EyePosition);



					C_Matrix4 M;



					M.fMatrix[0][0] = D0.X;
					M.fMatrix[0][1] = D0.Y;
					M.fMatrix[0][2] = D0.Z;
					M.fMatrix[0][3] = 0;

					M.fMatrix[1][0] = D1.X;
					M.fMatrix[1][1] = D1.Y;
					M.fMatrix[1][2] = D1.Z;
					M.fMatrix[1][3] = 0;

					M.fMatrix[2][0] = D2.X;
					M.fMatrix[2][1] = D2.Y;
					M.fMatrix[2][2] = D2.Z;
					M.fMatrix[2][3] = 0;

					M.fMatrix[3][0] = 0;
					M.fMatrix[3][1] = 0;
					M.fMatrix[3][2] = 0;
					M.fMatrix[3][3] = 1.0f;


					M.Transposed();
					//M = M.Transposed(M);

					return M;
				}
			}
		}


		C_Matrix4 a;

		a.fMatrix[0][0] = 0.f;
		a.fMatrix[0][1] = 0.f;
		a.fMatrix[0][2] = 0.f;
		a.fMatrix[0][3] = 0.f;
		
		a.fMatrix[1][0] = 0.f;
		a.fMatrix[1][1] = 0.f;
		a.fMatrix[1][2] = 0.f;
		a.fMatrix[1][3] = 0.f;
		
		a.fMatrix[2][0] = 0.f;
		a.fMatrix[2][1] = 0.f;
		a.fMatrix[2][2] = 0.f;
		a.fMatrix[2][3] = 0.f;
		
		a.fMatrix[3][0] = 0.f;
		a.fMatrix[3][1] = 0.f;
		a.fMatrix[3][2] = 0.f;
		a.fMatrix[3][3] = 0.f;
						  
		

		return a;
		
	}

	C_Matrix4 C_Camera::CreateViewMatrix(C_Vector3f EyePosition, C_Vector3f FocusPosition, C_Vector3f UpDirection)
	{
		C_Vector3f EyeDirection = FocusPosition.operator-(EyePosition);
		EyeDirection = FocusPosition - EyePosition;

		return CreateMAtrixLookTo(EyePosition, EyeDirection, UpDirection);
	}



	void C_Camera::CreateViewMatrixMember(C_Vector3f Eye, C_Vector3f At, C_Vector3f Up)
	{

		C_Vector3f EyeDirection = At.operator-(Eye);

		m_ViewMatrix = CreateMAtrixLookTo(Eye, EyeDirection, Up);
	}


	void C_Camera::CreateProjectionMatrix(float FieldofViewY, float AspectRatio, float NearZ, float FarZ)
	{
		//if (!PlatformMath::ScalarNearEqual(FieldofViewY, 0.0f, 0.00001f * 2.0f))
		//{
			//if (!PlatformMath::ScalarNearEqual(AspectRatio, 0.0f, 0.00001f))
			//{
				//if (!PlatformMath::ScalarNearEqual(FarZ, NearZ, 0.00001f))
				//{

		float SinFieldOfView;
		float CosFieldOfView;

		PlatformMath::ScalarSinCos(&SinFieldOfView, &CosFieldOfView, 0.5f * FieldofViewY);

		float Height = CosFieldOfView / SinFieldOfView;
		float Width = Height / AspectRatio;
		float fRange = FarZ / (FarZ - NearZ);


		C_Matrix4 Temp;

		Temp.fMatrix[0][0] = Width;
		Temp.fMatrix[0][1] = 0.0f;
		Temp.fMatrix[0][2] = 0.0f;
		Temp.fMatrix[0][3] = 0.0f;

		Temp.fMatrix[1][0] = 0.0f;
		Temp.fMatrix[1][1] = Height;
		Temp.fMatrix[1][2] = 0.0f;
		Temp.fMatrix[1][3] = 0.0f;

		Temp.fMatrix[2][0] = 0.0f;
		Temp.fMatrix[2][1] = 0.0f;
		Temp.fMatrix[2][2] = fRange;
		Temp.fMatrix[2][3] = 0.0f;

		Temp.fMatrix[3][0] = 0.0f;
		Temp.fMatrix[3][1] = 0.0f;
		Temp.fMatrix[3][2] = -fRange * NearZ;
		Temp.fMatrix[3][3] = 0.0f;

		Temp.Transposed();
		m_ProjectionMatrix = Temp;

		//}
	//}
//}

//}







	}



	C_Matrix4 C_Camera::PerpsProjectedSpace(float FovY, float AspectRatio, float ZNear, float ZFar)
	{

		C_Matrix4 Temp(
			0,0,0,0,
			0,0,0,0,
			0,0,0,0,
			0,0,0,0);
		
		float fRange = ZFar / (ZFar - ZNear);
		float SinFov = Math::Sin(FovY*0.5f);
		//float SinFov = Math::Sin((FovY>>1));
		float CosFov = Math::Cos(FovY*0.5f);
		//float CosFov = Math::Cos((FovY>>1));
		float Height = CosFov / SinFov;

		Temp.fMatrix[1][1] = CosFov / SinFov;
		Temp.fMatrix[0][0] = Height / AspectRatio;
		Temp.fMatrix[2][2] = fRange;
		Temp.fMatrix[2][3] = 1.0f;
		Temp.fMatrix[3][2] = -(fRange)*ZNear;

		// CosFov / SinFov,0,0,0
		// 0,Height / AspectHByW,0,0
		// 0,0,fRange,1.0f
		// 0,0,-fRange * NearZ,0.0f

		return Temp;
	}




	C_Matrix4 C_Camera::LookAtMatrix(C_Vector3f eye, C_Vector3f up, C_Vector3f target)
	{
		///Get the zAxis of the camera by constructing the vector from the eye to the target
		C_Vector3f  zAxisCamera = target - eye;
		zAxisCamera.Normalize();
		///Get the right vector of the camera by doing a cross product of the up vector and the zAxis
		C_Vector3f xAxisCamera = up ^ zAxisCamera;
		xAxisCamera.Normalize();
		///Get the yAAxis by doing a cross product of the xAxis and the xAxis
		C_Vector3f  yAxisCamera = zAxisCamera ^ xAxisCamera;
		//?????????
		//yAxisCamera.Normalize();


		C_Matrix4 LookAt = {
			&C_Vector4f(xAxisCamera.X, yAxisCamera.X, zAxisCamera.X, 0),
			&C_Vector4f(xAxisCamera.Y, yAxisCamera.Y, zAxisCamera.Y, 0),
			&C_Vector4f(xAxisCamera.Z, yAxisCamera.Z, zAxisCamera.Z, 0),
			&C_Vector4f(-(xAxisCamera | eye), -(yAxisCamera | eye), -(zAxisCamera | eye), 1)
		};

		return LookAt;
	}



}