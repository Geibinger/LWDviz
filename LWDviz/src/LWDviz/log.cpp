#include "lwpch.h"

#include "log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace lw {
	std::shared_ptr<spdlog::logger> log::s_coreLogger;
	std::shared_ptr<spdlog::logger> log::s_clientLogger;

	void log::init() {
		spdlog::set_pattern("%^[%T] %n: %v%$");
		s_coreLogger = spdlog::stdout_color_mt("LWDVIZ");
		s_coreLogger->set_level(spdlog::level::trace);

		s_clientLogger = spdlog::stdout_color_mt("APP");
		s_clientLogger->set_level(spdlog::level::trace);
	}
}