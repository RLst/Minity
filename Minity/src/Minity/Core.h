#pragma once

#include "Base.h"

namespace Minity
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
}
