#include "RenderAPI.h"
#include "../../Platform/OpenGL/OpenGLRenderAPI.h"

namespace RenderAPI {
	Hydrogen::Ref<Renderer> Renderer::createRenderer() {
		switch(renderAPI) {
			case(Renderers::OpenGL): {
				return Hydrogen::createRef<OpenGLAPI::OpenGLRenderer>();
			}
			default: {
				return nullptr;
				break;
			}
		}
	}
	Renderer::Renderer() {}
	Renderer::~Renderer() {}

	void Renderer::init() {
	}
}