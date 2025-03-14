#pragma once

#include "Logger.h"
#include "../Core/Core.h"
#include "Sink.h"

namespace Logger {
	class H_API ConsoleSink:public OutputSink {
		public:
			void output(std::string message, Logger::Severity severity) override {
				switch(severity) {
					case Logger::Severity::TRACE: {
						std::cout << message << std::endl;
						break;
					}
					case Logger::Severity::MESSAGE: {
						std::cout << "\033[32m";
						std::cout << message << std::endl;
						std::cout << "\033[0m";
						break;
					}
					case Logger::Severity::WARNING:{
						std::cout << "\033[33m";
						std::cout << message << std::endl;
						std::cout << "\033[0m";
						break;
					}
					case Logger::Severity::FATAL:{
						std::cout << "\033[91m";
						std::cout << message << std::endl;
						std::cout << "\033[0m";
						break;
					}
				}
			}
	};
}