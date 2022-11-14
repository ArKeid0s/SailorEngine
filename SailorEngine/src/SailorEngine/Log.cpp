#include "Log.h"

#include "spdlog/sinks/stdout_color_sinks.h"

namespace SailorEngine
{
	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	void Log::Init()
	{
		// Set pattern for all loggers to be [timestamp] [logger name] [message]
		spdlog::set_pattern("%^[%T] %n: %v%$");
		
		// Create core logger
		s_CoreLogger = spdlog::stdout_color_mt("[SAILOR_ENGINE]");
		s_CoreLogger->set_level(spdlog::level::trace);
		
		// Create client logger
		s_ClientLogger = spdlog::stdout_color_mt("[APP]");
		s_ClientLogger->set_level(spdlog::level::trace);
	}
}
