#pragma once

#include "Core.h"
#include "../Events/Event.h"
#include "../Events/GameEvent.h"
#include "../Events/WindowEvent.h"


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

			bool onWindowResize(WindowResize& e);
			bool onWindowClose(WindowClose& e);

			bool onGameUpdate(GameUpdate& e);
			bool onGameEvent(GameEvent& e);

			virtual void run() = 0;
			void onEvent(Event& e);


		public:
			appSpecs specs;

		private:
	};
	Application* createApp();
}