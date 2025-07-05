#include "OpenGLRenderAPI.h"

namespace OpenGLAPI {
	OpenGLRenderer::OpenGLRenderer() {
		H_CORE_TRACE("Init GLFW");
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

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
	void OpenGLRenderer::setCurrentContext(Hydrogen::Ref<RenderAPI::Context> context) {
		glViewport(context->x, context->y, context->width, context->height);
	}
}