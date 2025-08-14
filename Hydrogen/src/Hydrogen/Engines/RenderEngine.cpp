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
		auto time = (float)std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now().time_since_epoch()).count()/1000;
		glm::mat4 transform = glm::rotate(glm::mat4(1.0f), time , glm::vec3(-0.457f, 0.336f, 0.823f));
		m_shader->passUniform("trans", transform);
		for(auto meshIndex:m_renderQueueIndex) {
			m_renderer->drawGeometry(meshIndex);
		}
	}
	void RenderAPI::RenderEngine::addDrawMesh(Hydrogen::Scope<RenderAPI::Mesh> mesh) {
		m_renderQueueIndex.push_back(m_renderer->bindGeometry(*mesh));
		m_shader->useProgram();
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