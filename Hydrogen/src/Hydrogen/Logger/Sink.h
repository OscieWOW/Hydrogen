#pragma once

#include "Logger.h"
#include "../Core/Core.h"

namespace Logger {
	class H_API OutputSink {
		public:
			virtual void output(std::string message, Logger::Severity severity) = 0;
	};
}