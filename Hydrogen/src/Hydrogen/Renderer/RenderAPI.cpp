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


	Renderer::Renderer() {
		
	}
}