#pragma once

#ifdef LV_PLATFORM_WINDOWS
	#ifdef LV_BUILD_DLL
		#define	LWDVIZ_API __declspec(dllexport)
	#else
		#define	LVDVIZ_API __declspec(dllimport)
	#endif
#else
	#error LWDviz only supports Windows!
#endif

#define BIT(x) (1 << x)