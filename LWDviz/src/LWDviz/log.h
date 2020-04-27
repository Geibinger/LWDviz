#pragma once
#include "LWcore.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace lw {
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
#define LW_CORE_TRACE(...) ::lw::log::getCoreLogger()->trace(__VA_ARGS__)
#define LW_CORE_INFO(...)  ::lw::log::getCoreLogger()->info(__VA_ARGS__)
#define LW_CORE_WARN(...)  ::lw::log::getCoreLogger()->warn(__VA_ARGS__)
#define LW_CORE_ERROR(...) ::lw::log::getCoreLogger()->error(__VA_ARGS__)
#define LW_CORE_FATAL(...) ::lw::log::getCoreLogger()->critical(__VA_ARGS__)

// client log macros
#define LW_TRACE(...) ::lw::log::getClientLogger()->trace(__VA_ARGS__)
#define LW_INFO(...)  ::lw::log::getClientLogger()->info(__VA_ARGS__)
#define LW_WARN(...)  ::lw::log::getClientLogger()->warn(__VA_ARGS__)
#define LW_ERROR(...) ::lw::log::getClientLogger()->error(__VA_ARGS__)
#define LW_FATAL(...) ::lw::log::getClientLogger()->critical(__VA_ARGS__)