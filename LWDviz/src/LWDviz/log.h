#pragma once

#include "LVcore.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"
#include <memory>

namespace lv {
	class LWDVIZ_API log
	{
	public:
		static void init();

		inline static std::shared_ptr<spdlog::logger>& getCoreLogger() { return s_coreLogger; }
		inline static std::shared_ptr<spdlog::logger>& getClientLogger() { return s_clientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_coreLogger;
		static std::shared_ptr<spdlog::logger> s_clientLogger;
	};
}

// core log macros
#define LV_CORE_TRACE(...) ::lv::log::getCoreLogger()->trace(__VA_ARGS__)
#define LV_CORE_INFO(...)  ::lv::log::getCoreLogger()->info(__VA_ARGS__)
#define LV_CORE_WARN(...)  ::lv::log::getCoreLogger()->warn(__VA_ARGS__)
#define LV_CORE_ERROR(...) ::lv::log::getCoreLogger()->error(__VA_ARGS__)
#define LV_CORE_FATAL(...) ::lv::log::getCoreLogger()->critical(__VA_ARGS__)

// client log macros
#define LV_TRACE(...) ::lv::log::getClientLogger()->trace(__VA_ARGS__)
#define LV_INFO(...)  ::lv::log::getClientLogger()->info(__VA_ARGS__)
#define LV_WARN(...)  ::lv::log::getClientLogger()->warn(__VA_ARGS__)
#define LV_ERROR(...) ::lv::log::getClientLogger()->error(__VA_ARGS__)
#define LV_FATAL(...) ::lv::log::getClientLogger()->critical(__VA_ARGS__)