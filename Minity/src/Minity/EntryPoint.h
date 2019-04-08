#pragma once

#ifdef MNT_PLATFORM_WINDOWS

extern Minity::Core* Minity::CreateCore();

int main(int argc, char** argv)
{
	auto app = Minity::CreateCore();
	app->Run();
	delete app;
}

#endif