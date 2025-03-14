#pragma once

#include "Core.h"
#include "../Logger/Logger.h"

extern Hydrogen::Application* Hydrogen::createApp();

int main() {
	Logger::ConsoleSink* consoleSink = new Logger::ConsoleSink();
	Logger::OutputStream hydrogenLogger = Logger::OutputStream("APP",consoleSink);
	hydrogenLogger.setLogFormat("[%N %T] %M");


	hydrogenLogger.logFatal("Fatal example");
	hydrogenLogger.logWarning("Warning example");
	hydrogenLogger.logMessage("Message example");
	hydrogenLogger.logTrace("Trace example");

	Hydrogen::Application* app = Hydrogen::createApp();
	app->run();
	delete app;
	delete consoleSink;
	return 0;
}
