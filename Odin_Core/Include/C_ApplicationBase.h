#pragma once

#include "PrerequisitesCore.h"
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
	

	protected:

		OEInput* m_Input; 
		uint32 m_MouseX;
		uint32 m_MouseY;



	};
}
