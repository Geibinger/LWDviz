#pragma once

#ifdef LW_PLATFORM_WINDOWS
	#ifdef LW_BUILD_DLL
		#define	LWDVIZ_API __declspec(dllexport)
	#else
		#define	LWDVIZ_API __declspec(dllimport)
	#endif
#else
	#error LWDviz only supports Windows!
#endif

#ifdef LW_ENABLE_ASSERTS
	#define LW_ASSERT(x, ...) { if(!x) { LW_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define LW_CORE_ASSERT(x, ...) { if(!x) { LW_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define LW_ASSERT(x, ...)
	#define LW_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define LW_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)