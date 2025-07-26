#pragma once

#include "Core.h"
#include "../Logger/Logger.h"

namespace Hydrogen {
	class  Log {
		public:
			static void logInit();
			static Logger::OutputStream newLogger(const std::string& name);

		public:
			static Hydrogen::Ref<Logger::ConsoleSink> consoleSink;

			static Logger::OutputStream clientLogger;
			static Logger::OutputStream hydrogenLogger;
	};
}

#define H_CORE_TRACE(...)  Hydrogen::Log::hydrogenLogger.logTrace(__VA_ARGS__)
#define H_CORE_MESSAGE(...)  Hydrogen::Log::hydrogenLogger.logMessage(__VA_ARGS__)
#define H_CORE_WARN(...)  Hydrogen::Log::hydrogenLogger.logWarning(__VA_ARGS__)
#define H_CORE_FATAL(...)  Hydrogen::Log::hydrogenLogger.logFatal(__VA_ARGS__)

#define H_TRACE(...)  Hydrogen::Log::clientLogger.logTrace(__VA_ARGS__)
#define H_MESSAGE(...)  Hydrogen::Log::clientLogger.logMessage(__VA_ARGS__)
#define H_WARN(...)  Hydrogen::Log::clientLogger.logWarning(__VA_ARGS__)
#define H_FATAL(...)  Hydrogen::Log::clientLogger.logFatal(__VA_ARGS__)
