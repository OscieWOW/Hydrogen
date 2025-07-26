#pragma once

#include "../Core/Core.h"

namespace Hydrogen {
	class  Engine {
		public:
			Engine() = default;
			virtual void onUpdate(std::chrono::nanoseconds deltaT) = 0;

		protected:
	};
}
