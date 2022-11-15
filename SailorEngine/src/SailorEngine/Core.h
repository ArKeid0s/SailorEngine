#pragma once

#ifdef SE_PLATFORM_WINDOWS
	#ifdef SE_BUILD_DLL
		#define SAILOR_ENGINE_API __declspec(dllexport)
	#else
		#define SAILOR_ENGINE_API __declspec(dllimport)
	#endif
#else
	#error SailorEngine only supports Windows!
#endif

#define BIT(x) (1 << x)