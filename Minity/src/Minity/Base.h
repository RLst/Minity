#pragma once

#ifdef MNT_PLATFORM_WINDOWS
	#ifdef MNT_BUILD_DLL
		#define MINITY_API __declspec(dllexport)
	#else
		#define MINTY_API __declspec(dllimport)
	#endif
#else
	#error Minity only supports Windows!
#endif