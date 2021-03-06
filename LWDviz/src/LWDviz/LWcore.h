#pragma once

#include <memory>

#ifdef LW_PLATFORM_WINDOWS
	#ifdef LW_DYNAMIC_LINK
		#ifdef LW_BUILD_DLL
			#define	LWVIZ_API __declspec(dllexport)
		#else
			#define	LWVIZ_API __declspec(dllimport)
		#endif
	#endif
#else
	#define LWVIZ_API
	#error LWDviz only supports Windows!
#endif

#ifdef LW_DEBUG
	#define LW_ENABLE_ASSERTS
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

namespace lw {

	template<typename T>
	using scope = std::unique_ptr<T>;

	template<typename T>
	using ref = std::shared_ptr<T>;
}