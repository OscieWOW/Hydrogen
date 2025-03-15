#pragma once

#include "Logger.h"
#include "../Core/Core.h"
#include "Sink.h"

namespace Logger {
	class H_API FileSink:public OutputSink {
		public:
			std::ofstream outputFile;
		public:	
			FileSink(std::string filePath) {
				outputFile = std::ofstream(filePath);
				outputFile.clear();
			}
			~FileSink() {
				outputFile.close();
			}
			void output(std::string message, Logger::Severity severity) override {
				switch(severity) {
					case Logger::Severity::TRACE:
					{
						outputFile << "<TRACE>" << message << std::endl;
						break;
					}
					case Logger::Severity::MESSAGE:
					{
						outputFile << "<MESSAGE>" << message << std::endl;
						break;
					}
					case Logger::Severity::WARNING:
					{
						outputFile << "<WARNING>" << message << std::endl;
						break;
					}
					case Logger::Severity::FATAL:
					{
						outputFile << "<FATAL>" << message << std::endl;
						break;
					}
				}
			}

	};
}