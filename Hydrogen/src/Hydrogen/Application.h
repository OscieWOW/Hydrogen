#pragma once

#include <string>
#include <iostream>

#include "core.h"

namespace Hydrogen {
	class H_API Application {
		public:
			Application(const std::string& name);
			~Application();

			std::string getName();
		private:
			std::unique_ptr<std::string> m_name;
	};
}