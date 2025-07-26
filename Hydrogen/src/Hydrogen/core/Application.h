#pragma once

#include "Core.h"

#include "../Events/Event.h"
#include "../Events/GameEvent.h"
#include "../Events/WindowEvent.h"
#include "../Events/AppEvent.h"
#include "../Events/KeyEvent.h"
#include "LayerStack.h"
#include "../Renderer/Window.h"
#include "../Engines/RenderEngine.h"
#include "../Renderer/Shader.h"
#include "KeyCodes.h"

namespace Hydrogen {
	struct appSpecs {
		const std::string appName;
		RenderAPI::Renderers renderEngineType;

		appSpecs(const std::string name, RenderAPI::Renderers renderEngineType):appName(name), renderEngineType(renderEngineType) {

		}
	};

	class Application {
		public:
			Application(const appSpecs specs);
			~Application();

			virtual bool initRenderEngine();
			virtual bool createWindow();

			bool onAppUpdate(AppUpdate& e);
			bool onAppRender(AppRender& e);

			bool onWindowClose(WindowClose& e);


			void run();
			void onEvent(Event& e);

		public:
			appSpecs specs;
			bool running = true;

		protected:
			LayerStack m_layerStack;
			Ref<RenderAPI::Window> m_window;
			Ref<RenderAPI::RenderEngine> m_renderEngine;
			std::vector<Hydrogen::Ref<RenderAPI::Context>> m_contexts;
	};
	Application* createApp();
}