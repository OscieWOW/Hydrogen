#pragma once

#include "Logger.h"
#include "../Core/Core.h"
#include "Sink.h"

namespace Logger {
	class  FileSink:public OutputSink {
		public:
			FILE* outputFile;
		public:	
			FileSink(std::string filePath) {
				outputFile = fopen(filePath.c_str(),"w");
				if( outputFile == nullptr) {
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
						std::string text = "<TRACE>"+message+"\n";
						fputs(text.c_str(), outputFile);
						break;
					}
					case Logger::Severity::MESSAGE:
					{
						std::string text = "<MESSAGE>"+message+"\n";
						fputs(text.c_str(), outputFile);
						break;
					}
					case Logger::Severity::WARNING:
					{
						std::string text = "<WARNING>"+message+"\n";
						fputs(text.c_str(), outputFile);
						break;
					}
					case Logger::Severity::FATAL:
					{
						std::string text = "<FATAL>"+message+"\n";
						fputs(text.c_str(), outputFile);
						break;
					}
				}
			}

	};
}
