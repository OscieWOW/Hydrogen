#pragma once

#include "Core.h"


namespace Hydrogen {

	struct H_API appSpecs {
		const std::string* appName;

		appSpecs(const std::string* name):appName(name) {

		}
	};

	class H_API Application {
		public:
			Application(const appSpecs specs);
			~Application();

			virtual void run() = 0;

		public:
			appSpecs specs;

		private:
	};
	Application* createApp();
}