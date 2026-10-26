#include "Shader.h"
#include "RenderAPI.h"
#include "../../Platform/OpenGL/OpenGLShader.h"

namespace Hydrogen::RenderAPI {
	Hydrogen::Scope<Shader> Shader::createShader() {
		switch(renderAPI) {
			case(Renderers::OpenGL): {
				return Hydrogen::createScope<OpenGLAPI::OpenGLShader>();
				break;
			}
			default: {
				return nullptr;
				break;
			}
		}
	}
}
