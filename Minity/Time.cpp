#include "Time.h"

namespace MinityEngine {
namespace CoreModule {

void Time::setTime(double aTime)
{
	mTime = aTime;
}

void Time::setDeltaTime(double aDeltaTime)
{
	mDeltaTime = aDeltaTime;
}

void Time::setFixedDeltaTime(double aFixedDeltaTime)
{
	mFixedDeltaTime = aFixedDeltaTime;
}

double Time::time()
{
	return mTime;
}

double Time::deltaTime()
{
	return mDeltaTime;
}

double Time::fixedDeltaTime()
{
	return mFixedDeltaTime;
}


}
}

