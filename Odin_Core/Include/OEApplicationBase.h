#pragma once

#include "OEPrerequisitesCore.h"
#include "OEGraphicsAPI.h"
#include "OEVertexShader.h"
#include "OEPixelShader.h"
#include "OEInputLayout.h"
#include "OEModel.h"
#include "OEInput.h"

namespace OE_SDK
{
	class ODIN_ENGINE_COREUTILITY_EXPORT  C_ApplicationBase
	{
	public:
		C_ApplicationBase();
		virtual ~C_ApplicationBase();

		int Run(int width, int Height);

		virtual void OnInit() {};
		virtual void Update(float fDeltaTime);
		virtual void Render();
		virtual void OnDestroy() {};
		virtual void InitResources(int width, int Height);

		//C_GraphicsAPI m_GraphicsAPI;
		OEModel myModel;


	public:
		void Init(int width, int Height);
		void Destroy();
	

		bool primera = false;

	protected:

		OEInput* m_Input; 
		uint32 m_MouseX;
		uint32 m_MouseY;

		float EyeX;
		float EyeY;
		float EyeZ;
		int a;


/*		uint32 m_AumentX;
		uint32 m_AumentY;
		*/
		//Mouse Button Controls
		bool LBMStillPressed;
		bool RBMStillPressed;
		//Key controls
		bool K1StillPressed;
		bool K2StillPressed;
		bool KWStillPressed;
		bool KSStillPressed;
		bool KAStillPressed;
		bool KDStillPressed;

		bool KKStillPressed;
		bool KJStillPressed;
		//////////////////////////////////////////////////////////////////////////
		bool KOStillPressed;
		bool KLStillPressed;
		//////////////////////////////////////////////////////////////////////////
		bool KZStillPressed;
		bool KXStillPressed;


		bool m_WasScaled;
		float m_ScaleFactorX;
		float m_ScaleFactorY;
		float m_ScaleFactorZ;

		float m_RotateFactorX;
		float m_RotateFactorY;
		float m_RotateFactorZ;

		float m_TranslateFactorX; 
		float m_TranslateFactorY;
		float m_TranslateFactorZ;

		C_Vector3f Eye;
		C_Vector3f At;
		C_Vector3f Up;
		

	};
}
