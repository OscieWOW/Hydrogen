#pragma once

#include "../Core/Core.h"
#include "Sink.h"
#include "ConsoleSink.h"

namespace Logger {
	class H_API OutputStream {
		public:
			OutputStream(std::string name,OutputSink* outputSink);
			~OutputStream();

			void logTrace(std::string message);
			void logMessage(std::string message);
			void logWarning(std::string message);
			void logFatal(std::string message);

		private:
			std::string outputName;
			OutputSink* outputSink;

	};
}