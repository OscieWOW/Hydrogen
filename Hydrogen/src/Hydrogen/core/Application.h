#pragma once

#include <string>
#include <iostream>

#include "core.h"

namespace Hydrogen {

	struct H_API appSpecs {
		const std::string* name;

		appSpecs(const std::string* name):name(name) {

		}
	};

	class H_API Application {
		public:
		Application(const appSpecs specs);
		~Application();

		public:
		appSpecs specs;

		private:
	};
}