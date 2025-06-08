#include "RenderAPI.h"
#include "../../Platform/OpenGL/OpenGLRenderAPI.h"
#include "Window.h"

namespace RenderAPI {
	Hydrogen::Ref<Renderer> Renderer::createRenderer(Hydrogen::Scope<Shader> shader) {
		switch(renderAPI) {
			case(Renderers::OpenGL): {
				return Hydrogen::createRef<OpenGLAPI::OpenGLRenderer>(std::move(shader));
			}
		}
	}
	Renderer::Renderer(Hydrogen::Scope<Shader> shader):m_shader(std::move(shader)) {}
}