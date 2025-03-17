#pragma once

#include "LoggerEnums.h"
#include "Sink.h"
#include "ConsoleSink.h"
#include  "FileSink.h"

namespace Logger {
	class H_API OutputStream {
		public:
			OutputStream(std::string name,Hydrogen::Ref<OutputSink> outputSink);
			~OutputStream();

			void setLogFormat(std::string format);
			std::string formatMessage(std::string message);

			void logTrace(std::string message);
			void logMessage(std::string message);
			void logWarning(std::string message);
			void logFatal(std::string message);

		private:
			std::vector<Logger::formatToken> formatTokens;
			std::string outputName;
			Hydrogen::Ref<Logger::OutputSink> outputSink;

	};
}