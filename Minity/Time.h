//Copyright © 2019 Tony Le

//17 April 2019

#pragma once

namespace MinityEngine {
namespace CoreModule {

class Time
{
	//The interface to get
	friend class Core;
private:
	static unsigned int frameCount;

	static double mTime;
	static double mDeltaTime;
	static double mFixedDeltaTime;

	static void setTime(double aTime);
	static void setDeltaTime(double aDeltaTime);
	static void setFixedDeltaTime(double aFixedDeltaTime);

public:
	static double time();			//The time at the beginning of this frame (read only). This is the time in seconds since the last level has been loaded
	static double deltaTime();			//The completion time in seconds since the last frame (read only)
	static double fixedDeltaTime();		//The interval in seconds at which physics and other fixed frame rate updates are performed
};

unsigned int Time::frameCount = 0;
double Time::mTime = 0;
double Time::mDeltaTime = 0;
double Time::mFixedDeltaTime = 0;

}	//CoreModule
}	//MinityEngine
