#include "Log.h"

Hydrogen::Ref<CoreTrace::Sinks::UConsoleSink> Hydrogen::Log::consoleSink = Hydrogen::createRef<CoreTrace::Sinks::UConsoleSink>("SINK");

CoreTrace::Logger Hydrogen::Log::clientLogger = CoreTrace::Logger("CLIENT");
CoreTrace::Logger Hydrogen::Log::hydrogenLogger = CoreTrace::Logger("HYDROGEN");

namespace Hydrogen {
	void Log::logInit() {
		clientLogger.init(consoleSink);
		hydrogenLogger.init(consoleSink);
	}
	CoreTrace::Logger Log::newLogger(const std::string& name) {
		CoreTrace::Logger tempLogger = CoreTrace::Logger(name);
		tempLogger.init(consoleSink);
		return std::move(tempLogger);
	}
}
