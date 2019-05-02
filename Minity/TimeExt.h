#pragma once

namespace Minity {
	class Time
	{
		//Static Time module akin to UnityEngine.Time

		friend class App;	//This specified class has full access to this
		friend class Core;
		friend class Camera;
	private:

		static double	m_t;
		static double	m_dt;
		static double	m_fdt;

		//Engine accesses these functions to 
		static void		updateTime();
		static void		updateDeltaTime();

	public:
		static double	time();				//The current app time
		static double	deltaTime();		//Time between last frame and this frame
		static double	fixedDeltaTime();	//Physics module time step
	};
}