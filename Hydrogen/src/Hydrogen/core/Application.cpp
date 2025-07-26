#include "Application.h"

namespace Hydrogen {
	Application::Application(const appSpecs specs):specs(specs) {
		RenderAPI::renderAPI = specs.renderEngineType;
		m_renderEngine = createRef<RenderAPI::RenderEngine>();
	}
	Application::~Application() {
	}

	bool Application::initRenderEngine() {
		Hydrogen::Scope<RenderAPI::Shader> shader = RenderAPI::Shader::createShader();
		
		shader->addShaderCode(RenderAPI::ShaderType::VERTEX, R"(#version 330 core
			layout(location = 0) in vec3 aPos;

			out vec3 colour;

			void main() {
				colour = aPos;
				gl_Position = vec4(aPos, 1.0);
			}
		)");
		shader->addShaderCode(RenderAPI::ShaderType::FRAGMENT, R"(
			#version 330 core
			out vec4 FragColor;

			in vec3 colour;

			void main() {
				FragColor = vec4(colour, 1.0f);
			} 
		)");
		
		m_renderEngine->init(std::move(shader));
		
		return true;
	}
	bool Application::createWindow() {
		RenderAPI::WindowData windowData = RenderAPI::WindowData(specs.appName, 800, 600);
		m_window = m_renderEngine->createWindow(std::move(windowData), BIND_EVENT_FUNCTION(onEvent));
		m_contexts.push_back(createRef<RenderAPI::Context>(0, 0, m_window->m_data.width, m_window->m_data.height, m_window, RenderAPI::Camera(0, 0)));
		return true;
	}



	void Application::run() {
		m_renderEngine->addDrawMesh(Hydrogen::createScope<RenderAPI::Mesh>(RenderAPI::Mesh([]()->std::vector<RenderAPI::Vertex> {
			std::vector<RenderAPI::Vertex> vertecies = {
				RenderAPI::Vertex(glm::vec3(1.0f,1.0f,0.0f), glm::vec3(0.0f,1.0f,0.0f), glm::vec2(0.0f, 1.0f)),
				RenderAPI::Vertex(glm::vec3(-1.0f,-1.0f,0.0f), glm::vec3(0.0f,1.0f,0.0f), glm::vec2(1.0f, 1.0f)),
				RenderAPI::Vertex(glm::vec3(-1.0f,1.0f,0.0f), glm::vec3(0.0f,1.0f,0.0f), glm::vec2(0.0f, 0.0f))};
			return vertecies;
		}(), std::vector<unsigned int>{0, 1, 2}, "texture")));

		auto frameStart = std::chrono::high_resolution_clock::now();
		while(running && m_window->windowOpen) {
			auto frameTime = std::chrono::high_resolution_clock::now() - frameStart;
			frameStart = std::chrono::high_resolution_clock::now();

			m_window->onUpdate();
			
			m_renderEngine->onUpdate(frameTime);
			for(auto context:m_contexts) {
				m_renderEngine->onRender(context);
				context->window->onDrawUpdate();
			}
		}
	}

	void Application::onEvent(Event& e) {
		Hydrogen::Scope<EventDispatcher> dispatcher = Hydrogen::createScope<EventDispatcher>(e);

		H_CORE_MESSAGE(e.traceEvent());

		//App Events
		dispatcher->dispatch<AppUpdate>(BIND_EVENT_FUNCTION(onAppUpdate));
		dispatcher->dispatch<AppRender>(BIND_EVENT_FUNCTION(onAppRender));

		//Window Events
		dispatcher->dispatch<WindowClose>(BIND_EVENT_FUNCTION(onWindowClose));

		m_layerStack.onEvent(e);
	}

	bool Application::onAppUpdate(AppUpdate& e) {
		H_CORE_MESSAGE(e.traceEvent());
		return true;
	}
	bool Application::onAppRender(AppRender& e) {
		return true;
	}

	bool Application::onWindowClose(WindowClose& e) {
		running = false;
		return true;
	}
}