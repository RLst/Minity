#pragma once

#include "Base.h"

namespace MinityEngine
{

class /*MINTY_API*/ Core
{
public:
	Core();
	virtual ~Core();

	int Run();
};

//To be defined in client
Core* CreateCore();

}	//MinityEngine
