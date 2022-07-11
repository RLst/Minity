#include "MinityEngine.h"

//------------- Inside MinityEngine.h ----------------
//#include "MinityEngine/CoreModules/Input.h"
//#include "MinityEngine/CoreModules/Time.h"
//#include "MinityEngine/CoreModules/Random.h"
//#include "MinityEngine/CoreModules/Math.h"
//#include "MinityEngine/CoreModules/Random.h"
//#include "MinityEngine/CoreModules/Random.h"
//
//using namespace MinityEngine;
//--------------------------------------

void PlayerInput::Update()
{

}

void PlayerInput::SetSprint()
{
	if (Input::GetKey(sprintButton))
	{
		isSprinting = true;
	}
	else
	{
		isSprinting = false;
	}
}