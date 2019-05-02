#include <vector>

class GLFWwindow;
#include "World.cpp"

namespace Minity
{
	class Core
	{
	private:
		bool m_isTerminating;
		
		GLFWwindow*	m_window;

		//Declare world stuff
		World* currentWorld;
		std::vector<World*> worlds;

		//Declare objects
		std::vector<GameObject*> gameObjects;


	public:
		void AddWorld();
		void GetWorld();
		void RemoveWorld();

		
		void Run()
		{
			CoreInit();
			while (!m_isTerminating)
			{
				CoreUpdate();
			}
			CoreEnd();
		}

	private:
		void CoreInit()
		{
			currentWorld->Init();
			//Run startup functions on current World...
			//Which should run startup functions on each GameObject
			//Which should run startup functions on each GO's Component
		}

		void CoreUpdate()
		{
			//Calculate dt etc
			PreUpdate();

			currentWorld->Update();
			//Run update functions on World...
			//Which shoudl run update functions on each GameObject
			//Which should run update functions on each GO's Component

			//Gl window stuff ie. polling etc
			PostUpdate();
		}

		void CoreEnd()
		{
			currentWorld->End();
			//Run end functions on World...
			//Which should run end functions on each GameObject
			//Which should run end functions on each GO's Component
		}

		void PreUpdate() {}
		void PostUpdate() {}
	};
} // Minity