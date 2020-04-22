#pragma once

#ifdef LV_PLATFORM_WINDOWS
	#ifdef LV_BUILD_DLL
		#define	LVDVIZ_API __declspec(dllexport)
	#else
		#define	LVDVIZ_API __declspec(dllimport)
	#endif
#else
	#error LWDviz only supports Windows!
#endif