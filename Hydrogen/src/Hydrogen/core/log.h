#pragma once

#include "Core.h"
#include "../Logger/Logger.h"

namespace Hydrogen {
	class H_API Log {
		public:
			static void logInit();

		public:
			static Hydrogen::Ref<Logger::ConsoleSink> consoleSink;

			static Logger::OutputStream clientLogger;
			static Logger::OutputStream hydrogenLogger;
	};
}

#define H_CORE_TRACE(msg)  Hydrogen::Log::hydrogenLogger.logTrace(msg)
#define H_CORE_MESSAGE(msg)  Hydrogen::Log::hydrogenLogger.logMessage(msg)
#define H_CORE_WARN(msg)  Hydrogen::Log::hydrogenLogger.logWarning(msg)
#define H_CORE_FATAL(msg)  Hydrogen::Log::hydrogenLogger.logFatal(msg)

#define H_TRACE(msg)  Hydrogen::Log::clientLogger.logTrace(msg)
#define H_MESSAGE(msg)  Hydrogen::Log::clientLogger.logMessage(msg)
#define H_WARN(msg)  Hydrogen::Log::clientLogger.logWarning(msg)
#define H_FATAL(msg)  Hydrogen::Log::clientLogger.logFatal(msg)