#pragma once

#ifdef MNT_PLATFORM_WINDOWS

extern MinityEngine::Core* MinityEngine::CreateCore();

int main(int argc, char** argv)
{
	auto app = MinityEngine::CreateCore();
	app->Run();
	delete app;
}

#endif