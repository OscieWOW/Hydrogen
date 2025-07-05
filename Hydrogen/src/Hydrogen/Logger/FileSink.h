#pragma once

#include "Logger.h"
#include "../Core/Core.h"
#include "Sink.h"

namespace Logger {
	class H_API FileSink:public OutputSink {
		public:
			FILE* outputFile;
			errno_t error;
		public:	
			FileSink(std::string filePath) {
				error = fopen_s(&outputFile,filePath.c_str(),"w");
				if(error != 0 || outputFile == nullptr) {
					std::cout << "ERROR OPENING FILE" << filePath << std::endl;
				}
			}
			~FileSink() {
				fclose(outputFile);
			}
			void output(std::string message, Logger::Severity severity) override {
				switch(severity) {
					case Logger::Severity::TRACE:
					{
						fprintf(outputFile,("<TRACE>"+message+"\n").c_str());
						break;
					}
					case Logger::Severity::MESSAGE:
					{
						fprintf(outputFile,("<MESSAGE>"+message+"\n").c_str());
						break;
					}
					case Logger::Severity::WARNING:
					{
						fprintf(outputFile,("<WARNING>"+message).c_str());
						break;
					}
					case Logger::Severity::FATAL:
					{
						fprintf(outputFile,("<FATAL>"+message).c_str());
						break;
					}
				}
			}

	};
}