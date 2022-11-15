#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace SailorEngine
{
	class SAILOR_ENGINE_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
};

// Core log macros
#define SE_LOG_CORE_TRACE(...) ::SailorEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SE_LOG_CORE_INFO(...) ::SailorEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SE_LOG_CORE_WARN(...) ::SailorEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SE_LOG_CORE_ERROR(...) ::SailorEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SE_LOG_CORE_CRITICAL(...) ::SailorEngine::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define SE_LOG_TRACE(...) ::SailorEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SE_LOG_INFO(...) ::SailorEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define SE_LOG_WARN(...) ::SailorEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SE_LOG_ERROR(...) ::SailorEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define SE_LOG_CRITICAL(...) ::SailorEngine::Log::GetClientLogger()->critical(__VA_ARGS__)
