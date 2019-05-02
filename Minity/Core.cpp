////Tony Le
////21 Mar 2019
//
//#include "Core.h"
//#include "TimeExt.h"
//#include "Input.h"
//
//#include "Gizmos.h"
//#include "gl_core_4_4.h"
//#include "GLFW/glfw3.h"
//
//#ifdef _DEBUG
//#include <iostream>
//#endif
//
//namespace pkr {
//
//	Core::Core() :
//		m_window(nullptr),
//		pm_isTerminating(false)
//	{}
//	Core::~Core() {}
//
//	void Core::WindowConfig(const char * appTitle, unsigned int screenWidth, unsigned int screenHeight, vec4 backgroundColor, bool isFullscreen)
//	{
//		m_appTitle = appTitle;
//		m_scrnWidth = screenWidth;
//		m_scrnHeight = screenHeight;
//		m_bgCol = backgroundColor;
//		m_isFullscreen = isFullscreen;
//	}
//
//	void Core::GizmoConfig(unsigned int maxLines, unsigned int maxTris, unsigned int max2DLines, unsigned int max2DTris)
//	{
//		pm_maxLines = maxLines;
//		pm_maxTris = maxTris;
//		pm_max2DLines = max2DLines;
//		pm_max2DTris = max2DTris;
//	}
//
//
//	int Core::Run()
//	{
//		//INITIALISE
//		auto initReturnCode = CoreInit();
//		if (initReturnCode != PKR_SUCCESS)
//			return initReturnCode;
//
//		//GAME LOOP
//		while (!pm_isTerminating)
//		{
//			//UPDATE
//			CoreUpdate();
//
//			//DRAW
//			CoreDraw();
//
//			//Check if app is terminating
//			if (glfwWindowShouldClose(m_window) == GLFW_TRUE ||		//User closes window
//				glfwGetKey(m_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)	//User presses ESC
//				pm_isTerminating = true;
//		}
//
//		//SHUTDOWN
//		if (!CoreEnd()) return -5;
//
//		//Successful run
//		return 0;
//	}
//
//	int Core::CoreInit()
//	{
//		////Pre
//		//OPENGL setup
//		pm_frames = 0;
//		pm_fpsInterval = 0;
//		//Initialise GLFW
//		if (!glfwInit())
//			return -1;
//		//Create window
//		m_window = glfwCreateWindow(m_scrnWidth, m_scrnHeight, m_appTitle, (m_isFullscreen ? glfwGetPrimaryMonitor() : nullptr), nullptr);
//		if (!m_window)
//		{
//			glfwTerminate();
//			return -2;
//		}
//		glfwMakeContextCurrent(m_window);
//		//Fix up openGL extentions
//		if (ogl_LoadFunctions() == ogl_LOAD_FAILED)
//		{
//			glfwDestroyWindow(m_window);
//			glfwTerminate();
//			return -3;
//		}
//#ifdef _DEBUG
//		//Display version
//		auto major = ogl_GetMajorVersion();
//		auto minor = ogl_GetMinorVersion();
//		printf("GL version: %i.%i", major, minor);
//#endif // _DEBUG
//
//		//Gizmos
//		aie::Gizmos::create(pm_maxLines, pm_maxTris, pm_max2DLines, pm_max2DTris);
//
//		//Start input manager
//		Input::create();
//
//		///////////////
//		//// User ////
//		if (!Start()) return -4;
//		////////////
//		///////////
//
//		////Post
//
//		return PKR_SUCCESS;
//	}
//
//	void Core::CoreUpdate()
//	{
//		////Pre
//		//Update time module
//		Time::updateTime();
//		Time::updateDeltaTime();
//		pm_fpsInterval += Time::deltaTime();
//		if (pm_fpsInterval >= 1.0f)
//		{
//			m_fps = pm_frames;
//			pm_frames = 0;
//			pm_fpsInterval -= 1.0f;
//		}
//		//Skip updates and draw if window is minimized
//		if (glfwGetWindowAttrib(m_window, GLFW_ICONIFIED) != 0)
//			return;
//
//		//Clear input status
//		//Input::clearStatus();
//		Input::getInstance()->clearStatus();
//
//		//Update window events ie. Input etc
//		glfwPollEvents();
//
//		///////////////
//		//// User ////
//		Update();
//		////////////
//		///////////
//
//		////Post
//	}
//
//	void Core::CoreDraw()
//	{
//		////Pre
//		clearScreen();
//
//		///////////////
//		//// User ////
//		Draw();
//		////////////
//		///////////
//
//		////Post			
//		//Bring backbuffer front to draw
//		glfwSwapBuffers(m_window);
//	}
//
//	bool Core::CoreEnd()
//	{
//		////Pre
//
//		///////////////
//		//// User ////
//		if (!End()) return false;
//		////////////
//		///////////
//
//		////Post			
//		aie::Gizmos::destroy();
//		//Shutdown GLFW
//		glfwDestroyWindow(m_window);
//		glfwTerminate();
//
//		return true;
//	}
//
//	void Core::clearScreen() const
//	{
//		glClearColor(m_bgCol.r, m_bgCol.g, m_bgCol.b, m_bgCol.a);
//		glEnable(GL_DEPTH_TEST);
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//		aie::Gizmos::clear();
//	}
//
//	unsigned int Core::getFPS() const
//	{
//		return m_fps;
//	}
//
//	unsigned int Core::getScreenWidth() const
//	{
//		int w = 0, h = 0;
//		glfwGetWindowSize(m_window, &w, &h);
//		return w;
//	}
//
//	unsigned int Core::getScreenHeight() const
//	{
//		int w = 0, h = 0;
//		glfwGetWindowSize(m_window, &w, &h);
//		return h;
//	}
//
//}
