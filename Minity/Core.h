//Tony Le
//21 Mar 2019

#pragma once
#include "TimeExt.h"

#include "glm/ext.hpp"

using glm::vec4;

struct GLFWwindow;

//// Prototype
#include <vector>

////
namespace Minity {

	enum eFlags
	{
		PKR_FAIL = 0,
		PKR_SUCCESS = 1,

		PKR_FALSE = 0,
		PKR_TRUE = 1,
	};

	class Input;
	class Time;
	class Random;
	class Colour;
	class Math;		//Might not need?
	class Graphics;

	class Object;
	class GameObject;
	class Component;
	class World;

	typedef class Core		//TODO rename this to Engine later
	{
		//very [P]rivate [M]ember variables used by core methods
		unsigned int	pm_frames;
		double			pm_fpsInterval;
		bool			pm_isTerminating = false;

		unsigned int	pm_maxLines, pm_maxTris, pm_max2DLines, pm_max2DTris;

	private:
		std::vector<GameObject*> gameObjects;
		std::vector<World*> worlds;

		//Window
		const char*		m_appTitle;
		unsigned int	m_scrnWidth, m_scrnHeight;
		vec4			m_bgCol;
		bool			m_isFullscreen;

		unsigned int	m_fps;

		GLFWwindow *	m_window;

		//These hide core administrative logic that needs to run
		int				CoreInit();
		void			CoreUpdate();
		void			CoreDraw();
		bool			CoreEnd();

	protected:
		void			clearScreen() const;

	public:
		Core();
		virtual ~Core();		//??? Why virtual?

		//Not copyable or [implicitly] not moveable
		Core(const Core&) = delete;
		Core& operator=(const Core&) = delete;

		//User must run these to configure the engine
		void			WindowConfig(const char* appTitle, unsigned intscreenWidth, unsigned int screenHeight, vec4 backgroundColor, bool isFullscreen);
		void			GizmoConfig(unsigned int maxLines, unsigned int maxTris, unsigned int max2DLines, unsigned int max2DTris);

		//Utility
		unsigned int	getFPS() const;
		//void			showFPS() const;
		//void			hideFPS() const;
		unsigned int	getScreenWidth() const;
		unsigned int	getScreenHeight() const;

		//Runs the entire engine
		int				Run();

		//User
		virtual bool	Start() = 0;	//For now is abstract/interface and must be derived
		virtual void	Update() {}
		virtual void	Draw() {}
		virtual bool	End() { return true; }

	} Core;

}