#include "Logger.h"

namespace Logger {
	Logger::OutputStream::OutputStream(std::string name,OutputSink* outputSink):outputSink(outputSink),outputName(name) {

	}
	Logger::OutputStream::~OutputStream() {

	}

	void OutputStream::logTrace(std::string message) {
		std::cout << message << std::endl;
		std::stringstream output;
		output << "[" << outputName << " " << __TIME__ << "] " << message;
		outputSink->output(output.str());
	}
	void OutputStream::logMessage(std::string message) {

	}
	void OutputStream::logWarning(std::string message) {

	}
	void OutputStream::logFatal(std::string message) {

	}
}