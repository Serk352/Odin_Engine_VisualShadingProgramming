#pragma once
#include "OEPrerequisitesGraphics.h"
#include "Vector3f.h"
#include "Vector4f.h"
#include "Quaternions.h"

namespace OE_SDK
{




	class ODIN_ENGINE_GRAPHICS_API_UTILITY_EXPORT C_Animation
	{

	public:

		C_Animation() {};
		~C_Animation() {};


	protected:
		struct KeyFrame
		{

			C_Vector3f   m_Scale;
			C_Vector3f   m_Position;
			C_Quaternion m_Rotation;
			float        m_Time;

		};

	public:
		//string mName;
		double Duration;
		double m_TicksPerSecond;
		//unsigned int numChannels;
		Vector<KeyFrame> MyKeyFrames;

		//Canal de animación







	};





}


