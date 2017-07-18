#pragma once
#include "PrerequisitesUtil.h"
#include "Vector3f.h"


namespace OE_SDK
{

	class ODIN_ENGINE_UTILITY_EXPORT C_Matrix3
	{
	public:

		

		union 
		{
			C_Vector3f m_row[3];
			float fMatrix[3][3];
			float m_Linear[9];
			
			struct 
			{
				float m00, m01, m02,
					  m10, m11, m12,
					  m20, m21, m22;

			}m_Elements;


		};

		
		void  add(const C_Matrix3& fMa);
		void rest(const C_Matrix3& fMa);
		C_Matrix3 mult(const C_Matrix3& fMa);
		C_Matrix3 transposed(const C_Matrix3& fMa);
		C_Matrix3 MultVector(const C_Matrix3& fMa, const C_Vector3f& v3);


		//operadores
		
		C_Matrix3 operator=(const C_Matrix3& prmV);

		C_Matrix3();
		C_Matrix3(const C_Matrix3& a);
		~C_Matrix3();

	};

}