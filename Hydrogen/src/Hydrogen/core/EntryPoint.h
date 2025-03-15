#pragma once

#include "Core.h"
#include "../Logger/Logger.h"

extern Hydrogen::Application* Hydrogen::createApp();

int main() {

	//Console log example
	Logger::ConsoleSink* consoleSink = new Logger::ConsoleSink();
	Logger::OutputStream hydrogenLogger = Logger::OutputStream("APP",consoleSink);
	hydrogenLogger.setLogFormat("[%N %T] %M");

	hydrogenLogger.logFatal("Fatal example");
	hydrogenLogger.logWarning("Warning example");
	hydrogenLogger.logMessage("Message example");
	hydrogenLogger.logTrace("Trace example");


	Logger::FileSink* fileSink = new Logger::FileSink("errorLog.txt");
	Logger::OutputStream errorLogger = Logger::OutputStream("ERROR",fileSink);
	errorLogger.setLogFormat("[%D %T] %M");

	errorLogger.logFatal("Fatal example");
	errorLogger.logWarning("Warning example");
	errorLogger.logMessage("Message example");
	errorLogger.logTrace("Trace example");


	Hydrogen::Application* app = Hydrogen::createApp();
	app->run();
	delete app;
	delete consoleSink;
	delete fileSink;
	return 0;
}
