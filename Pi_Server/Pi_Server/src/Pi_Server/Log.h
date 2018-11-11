#pragma once

#include <memory>

#include "Core.h"
#include "spdlog\spdlog.h"




namespace PIS {

	class PIS_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		 static std::shared_ptr<spdlog::logger> s_CoreLogger;
		 static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}


//Core log macros
#define PIS_ERROR(...)   ::PIS::Log::GetCoreLogger()->error(__VA_ARGS__)
#define PIS_WARN(...)    ::PIS::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define PIS_INFO(...)    ::PIS::Log::GetCoreLogger()->info(__VA_ARGS__)
#define PIS_TRACE(...)   ::PIS::Log::GetCoreLogger()->trace(__VA_ARGS__)
//#define PIS_FATAL(...)   ::PIS::Log::GetCoreLogger()->fatal(__VA_ARGS__)


//Client
#define APP_ERROR(...)   ::PIS::Log::GetClientLogger()->error(__VA_ARGS__)
#define APP_WARN(...)    ::PIS::Log::GetClientLogger()->warn(__VA_ARGS__)
#define APP_INFO(...)    ::PIS::Log::GetClientLogger()->info(__VA_ARGS__)
#define APP_TRACE(...)   ::PIS::Log::GetClientLogger()->trace(__VA_ARGS__)
//#define APP_FATAL(...)   ::PIS::Log::GetClientLogger()->fatal(__VA_ARGS__)