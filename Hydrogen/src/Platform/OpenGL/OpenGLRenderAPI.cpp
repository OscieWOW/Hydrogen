#include "OpenGLRenderAPI.h"

namespace OpenGLAPI {
	OpenGLRenderer::OpenGLRenderer(Hydrogen::Scope<RenderAPI::Shader> shader):Renderer(std::move(shader)) {
		H_CORE_TRACE("Init renderer");
	}
	OpenGLRenderer::~OpenGLRenderer() {
		m_shader->deleteShader();
	}

	void OpenGLRenderer::setClearColour(RenderAPI::Colour colour) {
		glClearColor((float)colour.getRedFloat(), (float)colour.getGreenFloat(), (float)colour.getBlueFloat(), (float)colour.getAlphaFloat());
	}
	void OpenGLRenderer::render() {
		m_shader->useProgram();
		glClear(GL_COLOR_BUFFER_BIT);
	}
}