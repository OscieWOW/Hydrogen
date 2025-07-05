#include "RenderAPI.h"
#include "../../Platform/OpenGL/OpenGLRenderAPI.h"
#include "Window.h"

namespace RenderAPI {
	Hydrogen::Ref<Renderer> Renderer::createRenderer() {
		switch(renderAPI) {
			case(Renderers::OpenGL): {
				return Hydrogen::createRef<OpenGLAPI::OpenGLRenderer>();
			}
		}
	}
	Renderer::Renderer() {}
	Renderer::~Renderer() {}

	void Renderer::init(Hydrogen::Scope<Shader> shader) {
		m_shader = std::move(shader);
	}
	
	void Renderer::compileShaders() { 
		m_shader->compileProgram();
	}
}