#include "RenderEngine.h"

namespace RenderAPI {
	RenderEngine::RenderEngine() {
		m_renderer = Renderer::createRenderer();
	}
	RenderEngine::~RenderEngine() {
		m_shader->deleteShader();
	}

	void RenderEngine::onUpdate(std::chrono::nanoseconds deltaT) {}
	void RenderEngine::onRender(Hydrogen::Ref<Context> context) {
		m_renderer->setCurrentContext(context);
		m_renderer->Clear();
		m_shader->useProgram();
		for(auto meshIndex:m_renderQueueIndex) {
			m_renderer->drawGeometry(meshIndex);
		}
	}
	void RenderAPI::RenderEngine::addDrawMesh(Hydrogen::Scope<RenderAPI::Mesh> mesh) {
		m_renderQueueIndex.push_back(m_renderer->bindGeometry(*mesh));
		m_shader->passUniform("sortaPi",3.142f);

	}
	void RenderEngine::init(Hydrogen::Scope<Shader> shader) {
		shader->compileProgram();
		m_shader = std::move(shader);
		m_renderer->init();
		setClearColour(Colour(0, 239, 6));
	}
	void RenderEngine::setClearColour(Colour colour) {
		m_renderer->setClearColour(std::move(colour));
	}
	Hydrogen::Ref<Window> RenderEngine::createWindow(WindowData data, std::function<void(Hydrogen::Event&)> onEvent) {
		Hydrogen::Ref<Window> window = RenderAPI::Window::createWindow(std::move(data));
		window->setEventCallback(onEvent);
		return std::move(window);
	}
}