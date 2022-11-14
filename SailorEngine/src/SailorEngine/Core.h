#pragma once

#ifdef SL_PLATFORM_WINDOWS
	#ifdef SL_BUILD_DLL
		#define SAILOR_ENGINE_API __declspec(dllexport)
	#else
		#define SAILOR_ENGINE_API __declspec(dllimport)
	#endif
#else
	#error SailorEngine only supports Windows!
#endif

