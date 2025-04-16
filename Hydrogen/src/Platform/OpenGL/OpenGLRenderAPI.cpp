#include "OpenGLRenderAPI.h"

namespace OpenGLAPI {
	OpenGLRenderer::OpenGLRenderer() {
		H_CORE_TRACE("Init renderer");
	}
	void OpenGLRenderer::setClearColour(RenderAPI::Colour colour) {
		//H_CORE_WARN(std::to_string((float)colour.getRedFloat()));
		glClearColor((float)colour.getRedFloat(), (float)colour.getGreenFloat(), (float)colour.getBlueFloat(), (float)colour.getAlphaFloat());
		//glClear(GL_COLOR_BUFFER_BIT);
	}
}