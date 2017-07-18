#include "Quaternions.h"


namespace OE_SDK
{

	C_Quaternion::C_Quaternion()
	{
	}


	C_Quaternion::~C_Quaternion()
	{
	}


	C_Quaternion C_Quaternion::Slerp(C_Quaternion q1, C_Quaternion q2, float t)
	{
		C_Quaternion Q;

		float cosOmega = q1.m_w*q2.m_w + q1.m_x*q2.m_x + q1.m_y*q2.m_y + q1.m_z*q2.m_z;

		if (cosOmega < 0.0f) {
			q2.m_w = -q2.m_w;
			q2.m_x = -q2.m_x;
			q2.m_y = -q2.m_y;
			q2.m_z = -q2.m_z;
			cosOmega = -cosOmega;
		}

		float k0, k1;
		if (cosOmega > 0.9999f) {
			k0 = 1.0f - t;
			k1 = t;
		}
		else {

			float sinOmega = sqrt(1.0f - cosOmega*cosOmega);
			float omega = atan2(sinOmega, cosOmega);
			float oneOverSinOmega = 1.0f / sinOmega;
			k0 = sin((1.0f - t) * omega) * oneOverSinOmega;
			k1 = sin(t * omega) * oneOverSinOmega;
		}
		Q.m_w = q1.m_w*k0 + q2.m_w*k1;
		Q.m_x = q1.m_x*k0 + q2.m_x*k1;
		Q.m_y = q1.m_y*k0 + q2.m_y*k1;
		Q.m_z = q1.m_z*k0 + q2.m_z*k1;
		return Q;
	}

	C_Matrix4 C_Quaternion::GetAsMatrix4()
	{
		C_Matrix4 M;
		float xx = m_x*m_x, 
			  yy = m_y*m_y, 
			  zz = m_z*m_z;
		
		float x = m_x, 
			  y = m_y, 
			  z = m_z,  
			  w = m_w;

		M.m_row[0] = { 1 - (2 * yy) - (2 * zz),	(2 * x*y) + (2 * z*w),	(2 * x*z) - (2 * w*y), 0.0f };
		M.m_row[1] = { (2 * x*y) - (2 * z*w),	1 - (2 * xx) - (2 * zz),	(2 * y*z) + (2 * w*x), 0.0f };
		M.m_row[2] = { (2 * x*z) + (2 * w*y),	(2 * y*z) - (2 * w*x),	1 - (2 * xx) - (2 * yy), 0.0f };
		M.m_row[3] = {                  0.0f,                    0.0f,                     0.0f, 0.0f };

		return M;

	}


	C_Matrix3 C_Quaternion::GetAsMatrix3()
	{

		C_Matrix3 M;
		float xx = m_x*m_x, yy = m_y*m_y, zz = m_z*m_z;
		float x = m_x, y = m_y, z = m_z, w = m_w;

		M.m_row[0] = { 1 - (2 * yy) - (2 * zz),	(2 * x*y) + (2 * z*w),	(2 * x*z) - (2 * w*y) };
		M.m_row[1] = { (2 * x*y) - (2 * z*w),	1 - (2 * xx) - (2 * zz),	(2 * y*z) + (2 * w*x) };
		M.m_row[2] = { (2 * x*z) + (2 * w*y),	(2 * y*z) - (2 * w*x),	1 - (2 * xx) - (2 * yy) };

		return M;


	}

}

