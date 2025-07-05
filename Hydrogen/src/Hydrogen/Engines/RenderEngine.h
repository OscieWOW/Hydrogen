#pragma once

#include "Engine.h"
#include "../Renderer/RenderAPI.h"

namespace RenderAPI {
	class H_API RenderEngine: public Hydrogen::Engine {
		public:
			RenderEngine() {
				m_renderer = Renderer::createRenderer();
			};

			void onUpdate(std::chrono::nanoseconds deltaT) override {}
			void onRender(Hydrogen::Ref<Context> context) {
				m_renderer->setCurrentContext(context);
				m_renderer->render();
			}
			void init(Hydrogen::Scope<Shader> shader) {
				m_renderer->init(std::move(shader));
				setClearColour(Colour(0, 239, 6));
				m_renderer->compileShaders();
			}
			void setClearColour(Colour colour) {
				m_renderer->setClearColour(std::move(colour));
			}

			Hydrogen::Ref<Window> createWindow(WindowData data, std::function<void(Hydrogen::Event&)> onEvent) {
				auto window = RenderAPI::Window::createWindow(std::move(data));
				window->setEventCallback(onEvent);
				return std::move(window);
			}

		protected:
			Hydrogen::Scope<RenderAPI::Shader> m_shader;
			Hydrogen::Ref<RenderAPI::Renderer> m_renderer;
	};
}
