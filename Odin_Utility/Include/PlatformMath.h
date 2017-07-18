#pragma once
#include "PrerequisitesUtil.h"

namespace OE_SDK
{
	class ODIN_ENGINE_UTILITY_EXPORT PlatformMath
	{
	public:
		static const float		PI;
		static const float		EULER;
		static const float		Inverse_PI;
		static const float		PIHalf;
		static const float		PI2;

		static const uint8		MIN_UINT8;
		static const uint16		MIN_UINT16;
		static const uint32		MIN_UINT32;
		static const int8		MIN_INT8;
		static const int16		MIN_INT16;
		static const int32		MIN_INT32;
		static const float		MIN_FLOAT;

		static const uint8		MAX_UINT8;
		static const uint16		MAX_UINT16;
		static const uint32		MAX_UINT32;
		static const int8		MAX_INT8;
		static const int16		MAX_INT16;
		static const int32		MAX_INT32;
		static const float		MAX_FLOAT;

		static const float		INFINITY_POS;
		static const float		INFINITY_NEG;

		static const float		DELTA;
		static const float		EPSILON;

		static const float		LOGN;
		static const float		LOGB10;

		static const float		Large_Number;
		static const float		Small_Number;
		static const float		Kinda_Large_Number;
		static const float		Kinda_Small_Number;

		static const float		DEGTORAD;
		static const float		RADTODEG;

		/************************************************************************/
		/* Funciones básicas													*/
		/************************************************************************/
		template<typename T>
		static FORCEINLINE T Square(T value)
		{
			return value*value;
		}
		
		template<typename T>
		static FORCEINLINE T Sqrt(T prm_Value)
		{
			return (T)std::sqrt(prm_Value);
		}

		template<typename T>
		static FORCEINLINE T InverseSqrt(T prm_F)
		{
			return (1.0f / Sqrt(prm_F));
		}

		static FORCEINLINE float Exponential(float prm_Value)
		{
			return (float)std::exp(prm_Value);
		}

		static FORCEINLINE float LogN(float prm_Value)
		{
			return (float)std::log(prm_Value);
		}


		/************************************************************************/
		/* Funciones trigonométricas                                            */
		/************************************************************************/
		

		//Esta funcion define si los valores son iguales con una diferencia menor o igual al epsilon que recibe
		static FORCEINLINE bool ScalarNearEqual(float prm_Value1, float prm_Value2, float epsilon)
		{
			float Delta = prm_Value1 - prm_Value2;

			if (Delta > 0)
			{
				return (Delta <= epsilon);
			}

			else if (Delta < 0)
			{
				return (Delta >= (-epsilon));
			}

			return 0;
		}


		static FORCEINLINE void ScalarSinCos(float* pSin, float* pCos, float RadianValue)
		{
			//float quotient = 1.0/3.141516 *RadianValue;


			float quotient = 1.0f / 3.141516f *RadianValue;

			if (RadianValue >= 0.0f)
			{
				//quotient = (float)((int)(quotient + 0.5f));
				quotient = (float)((int)(quotient + 0.5f));
			}
			else
			{
				//quotient = (float)((int)(quotient - 0.5f));
				quotient = (float)((int)(quotient - 0.5f));
			}

			//float y = RadianValue - ((2.0* 3.141516) - 0.5f);

			float y = RadianValue - ((2.0f* 3.141516f) - 0.5f);


			//float sign;

			float sign;


			if (y > (3.141516 / 2.0))
			{
				y = 3.141516f - y;
				sign = -1.0f;
			}
			else if (y < (-(3.141516f / 2.0f)))
			{
				y = -(3.141516f) - y;
				sign = -1.0f;
			}
			else
			{
				sign = +1.0f;
			}

//			float y2 = y*y;

			float y2 = y*y;


			*pSin = (((((-2.388959e-08f * y2 + 2.7525562e-06f)* y2 - 0.00019840874f) * y2 + 0.0083333310f) * y2 - 0.16666667f) * y2 + 1.0f) * y;
			
			//float p = ((((-2.6051615e-07f * y2 + 2.4760495e-05f) * y2 - 0.0013888378f) * y2 + 0.041666638f) * y2 - 0.5f) * y2 + 1.0f;
		
			float p = ((((-2.6051615e-07f * y2 + 2.4760495e-05f) * y2 - 0.0013888378f) * y2 + 0.041666638f) * y2 - 0.5f) * y2 + 1.0f;
			*pCos = sign*p;

		}




		static FORCEINLINE float	Sin(float prm_Value)
		{
			return (float)std::sinf(prm_Value);
		}
		static FORCEINLINE float	Cos(float prm_Value)
		{
			return (float)std::cos(prm_Value);
		}
		static FORCEINLINE float	Tan(float prm_Value)
		{
			return (float)std::tan(prm_Value);
		}

		static FORCEINLINE float	ASin(float prm_Value)
		{
			return (float)std::asin(prm_Value);
		}
		static FORCEINLINE float	ACos(float prm_Value)
		{
			return (float)std::acos(prm_Value);
		}
		static FORCEINLINE float	ATan(float prm_Value)
		{
			return (float)std::atan(prm_Value);
		}


		template<class T>
		static FORCEINLINE T Absolute(const T prm_Value)
		{
			return (prm_Value >= (T)0) ? prm_Value : -prm_Value;
		}

		static FORCEINLINE int32	Trunc(float prm_Value)
		{
			return (int32)prm_Value;
		}

		static FORCEINLINE int32	Round(float prm_Value)
		{
			return Floor(prm_Value + 0.5f);
		}
		static FORCEINLINE int32	Ceil(float prm_Value)
		{
			return Trunc((float)std::ceil(prm_Value));
		}
		static FORCEINLINE int32	Floor(float prm_Value)
		{
			return Trunc((float)std::floor(prm_Value));
		}




		template<class T>
		static FORCEINLINE	T		Min(const T& prm_A, const T& prm_B)
		{
			return (prm_A < prm_B ? prm_A : prm_B);
		}

		template<class T>
		static FORCEINLINE T		Max(const T& prm_A, const T& prm_B)
		{
			return (prm_A > prm_B ? prm_A : prm_B);
		}

		static FORCEINLINE float	Module(float prm_X, float prm_Y)
		{
			return (float)std::fmod(prm_X, prm_Y);
		}

		/*
		Faltan:
		Clamp
		Clamp3
		Min3
		Max3

		*/

	};
}