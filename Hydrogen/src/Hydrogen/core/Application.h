#pragma once

#include "Core.h"

#include "../Events/Event.h"
#include "../Events/GameEvent.h"
#include "../Events/WindowEvent.h"
#include "../Events/AppEvent.h"
#include "LayerStack.h"


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

			bool onWindowClose(WindowClose& e);
			bool onWindowResize(WindowResize& e);
			bool onWindowFocus(WindowFocus& e);
			bool onWindowLostFocus(WindowLostFocus& e);
			bool onWindowMoved(WindowMoved& e);

			bool onAppUpdate(AppUpdate& e);
			bool onAppRender(AppRender& e);

			void run();
			void onEvent(Event& e);


		public:
			appSpecs specs;
			bool running = true;

		protected:
			LayerStack m_layerStack;
	};
	Application* createApp();
}