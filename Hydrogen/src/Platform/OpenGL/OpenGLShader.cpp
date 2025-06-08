#include "OpenGLShader.h"

namespace OpenGLAPI {

	OpenGLShader::OpenGLShader() {
		
	}
	void OpenGLShader::addShaderSource(RenderAPI::ShaderType type, std::string source) {
		shaderSource[type] = source;
	}
	void OpenGLShader::compileProgram() {
		program = glCreateProgram();
		
		for(auto source : shaderSource) {
			GLenum shaderType = NULL;
			switch(source.first) {
				case(RenderAPI::ShaderType::FRAGMENT): shaderType = GL_FRAGMENT_SHADER; break;
				case(RenderAPI::ShaderType::VERTEX): shaderType = GL_VERTEX_SHADER; break;
			}

			std::string codeSource = Hydrogen::File(source.second, std::ios::in).readAll();
			const char* shaderCode = codeSource.data();

			unsigned int shader = glCreateShader(shaderType);
			glShaderSource(shader, 1, &shaderCode, NULL);
			glCompileShader(shader);
			
			int  success;
			char infoLog[512];
			glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
			if(!success) {
				glGetShaderInfoLog(shader, 512, NULL, infoLog);
				H_CORE_FATAL("ERROR::SHADER::COMPILATION FAILED "+source.second+"\n"+infoLog);
			}
			glAttachShader(program, shader);
			shaders.push_back(shader);
		}
		glLinkProgram(program);

		for(unsigned int i:shaders) {
			glDeleteShader(i);
		}
	}
	void OpenGLShader::useProgram() {
		glUseProgram(program);
	}
	void OpenGLShader::deleteShader() {
		glDeleteProgram(program);
	}
}