#pragma once

#include "../Core/Core.h"

namespace Hydrogen {
	class H_API Engine {
		public:
			Engine() = default;
			virtual void onUpdate(std::chrono::nanoseconds deltaT) = 0;

		protected:
	};
}
