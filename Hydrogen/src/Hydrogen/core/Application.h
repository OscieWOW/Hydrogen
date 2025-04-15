#pragma once

#include "Core.h"

#include "../Events/Event.h"
#include "../Events/GameEvent.h"
#include "../Events/WindowEvent.h"
#include "../Events/AppEvent.h"
#include "LayerStack.h"
#include "../Renderer/Window.h"

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

			bool onAppUpdate(AppUpdate& e);
			bool onAppRender(AppRender& e);

			bool onWindowClose(WindowClose& e);
			bool onWindowResize(WindowResize& e);
			bool onWindowFocus(WindowFocus& e);
			bool onWindowLostFocus(WindowLostFocus& e);


			void run();
			void onEvent(Event& e);


		public:
			appSpecs specs;
			bool running = true;

		protected:
			LayerStack m_layerStack;
			Scope<RenderAPI::Window> m_window;
	};
	Application* createApp();
}