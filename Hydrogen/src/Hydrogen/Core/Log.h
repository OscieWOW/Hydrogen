#pragma once

#include "Core.h"
#include <CoreTrace/CoreTrace.h>

namespace Hydrogen {
	class  Log {
		public:
			static void logInit();
			static CoreTrace::Logger newLogger(const std::string& name);

		public:
			static Hydrogen::Ref<CoreTrace::Sinks::UConsoleSink> consoleSink;

			static CoreTrace::Logger clientLogger;
			static CoreTrace::Logger hydrogenLogger;
	};
}

#define H_CORE_TRACE(...)  Hydrogen::Log::hydrogenLogger.trace(__VA_ARGS__)
#define H_CORE_MESSAGE(...)  Hydrogen::Log::hydrogenLogger.message(__VA_ARGS__)
#define H_CORE_WARN(...)  Hydrogen::Log::hydrogenLogger.warning(__VA_ARGS__)
#define H_CORE_FATAL(...)  Hydrogen::Log::hydrogenLogger.fatal(__VA_ARGS__)

#define H_TRACE(...)  Hydrogen::Log::clientLogger.trace(__VA_ARGS__)
#define H_MESSAGE(...)  Hydrogen::Log::clientLogger.message(__VA_ARGS__)
#define H_WARN(...)  Hydrogen::Log::clientLogger.warning(__VA_ARGS__)
#define H_FATAL(...)  Hydrogen::Log::clientLogger.fatal(__VA_ARGS__)
