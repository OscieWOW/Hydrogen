#include "log.h"

	Hydrogen::Ref<Logger::ConsoleSink> Hydrogen::Log::consoleSink = Hydrogen::CreateRef<Logger::ConsoleSink>();

	Logger::OutputStream Hydrogen::Log::clientLogger = Logger::OutputStream("CLIENT", consoleSink);
	Logger::OutputStream Hydrogen::Log::hydrogenLogger = Logger::OutputStream("HYDROGEN", consoleSink);

namespace Hydrogen {
	void Log::logInit() {
		clientLogger.setLogFormat("[%N %T] %M");

		hydrogenLogger.setLogFormat("[%N %T] %M");
	}
}