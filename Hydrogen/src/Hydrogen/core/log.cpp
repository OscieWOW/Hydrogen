#include "Log.h"

	Hydrogen::Ref<Logger::ConsoleSink> Hydrogen::Log::consoleSink = Hydrogen::createRef<Logger::ConsoleSink>();

	Logger::OutputStream Hydrogen::Log::clientLogger = Logger::OutputStream("CLIENT", consoleSink);
	Logger::OutputStream Hydrogen::Log::hydrogenLogger = Logger::OutputStream("HYDROGEN", consoleSink);

namespace Hydrogen {
	void Log::logInit() {
		clientLogger.setLogFormat("[%N %T] %M");
		hydrogenLogger.setLogFormat("[%N %T] %M");
	}
	Logger::OutputStream Log::newLogger(const std::string& name) {
		Logger::OutputStream tempLogger = Logger::OutputStream(name,consoleSink);
		tempLogger.setLogFormat("[%N %T] %M");
		return std::move(tempLogger);
	}
}