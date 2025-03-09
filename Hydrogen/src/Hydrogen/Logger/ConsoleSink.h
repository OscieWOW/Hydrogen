#pragma once

#include "../Core/Core.h"
#include "Sink.h"

namespace Logger {
	class H_API ConsoleSink:public OutputSink {
		public:
			inline void output(std::string message) override {
				std::cout << message << std::endl;
			}
	};
}
