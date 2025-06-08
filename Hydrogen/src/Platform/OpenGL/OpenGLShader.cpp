#include "OpenGLShader.h"

namespace OpenGLAPI {
	OpenGLShader::OpenGLShader() {
		
	}
	void OpenGLShader::addShaderSource(RenderAPI::ShaderType type, std::string source) {
		H_CORE_MESSAGE(Hydrogen::File(source,std::ios::in|std::ios::out).readAll());
	}
	void OpenGLShader::compileProgram() {
		
	}
}