#pragma once

#include "../Core/Core.h"

namespace Logger {
	class H_API OutputSink {
		public:	
			inline virtual void output(std::string message) {}
	};
}