#include "OpenGLRenderAPI.h"

namespace OpenGLAPI {
	OpenGLRenderer::OpenGLRenderer(Hydrogen::Scope<RenderAPI::Shader> shader):Renderer(std::move(shader)) {
		H_CORE_TRACE("Init renderer");
	}
	void OpenGLRenderer::setClearColour(RenderAPI::Colour colour) {
		glClearColor((float)colour.getRedFloat(), (float)colour.getGreenFloat(), (float)colour.getBlueFloat(), (float)colour.getAlphaFloat());
	}
}