#pragma once

#include "../Core/Core.h"
#include "LoggerEnums.h"
#include "Sink.h"
#include "ConsoleSink.h"

namespace Logger {
	class H_API OutputStream {
		public:
			OutputStream(std::string name,OutputSink* outputSink);
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
			OutputSink* outputSink;

	};
}