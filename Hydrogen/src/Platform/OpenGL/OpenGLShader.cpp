#include "OpenGLShader.h"

namespace OpenGLAPI {

	OpenGLShader::OpenGLShader() {
		
	}
	void OpenGLShader::addShaderSource(RenderAPI::ShaderType type, std::string source) {
		std::string code = Hydrogen::File(source, std::ios::in).readAll();
		m_shaderCode[type] = code;
	}
	void OpenGLAPI::OpenGLShader::addShaderCode(RenderAPI::ShaderType type, std::string source) {
		m_shaderCode[type] = source;
	}
	void OpenGLShader::compileProgram() {
		if(m_shaderCode.size() == 0) {
			H_CORE_FATAL("Please add a source to the shader program");
		}
		program = glCreateProgram();
		checkError("glCreateProgram");
		
		for(auto source : m_shaderCode) {
			GLenum shaderType = NULL;
			switch(source.first) {
				case(RenderAPI::ShaderType::FRAGMENT): shaderType = GL_FRAGMENT_SHADER; break;
				case(RenderAPI::ShaderType::VERTEX): shaderType = GL_VERTEX_SHADER; break;
			}

			const char* shaderCode = source.second.c_str();

			unsigned int shader = glCreateShader(shaderType);
			checkError("glCreateShader");
			glShaderSource(shader, 1, &shaderCode, NULL);
			glCompileShader(shader);
			
			int  success;
			char infoLog[512];
			glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
			if(!success) {
				glGetShaderInfoLog(shader, 512, NULL, infoLog);
				H_CORE_FATAL("ERROR::SHADER::COMPILATION FAILED {}\n{}",source.second,infoLog);
			}
			glAttachShader(program, shader);
			shaders.push_back(shader);
		}
		glLinkProgram(program);

		for(unsigned int i:shaders) {
			glDeleteShader(i);
		}
	}
	void OpenGLAPI::OpenGLShader::passUniform(std::string name, std::variant<int, float, glm::mat3, glm::vec3, glm::mat4> value) {
		std::visit([](auto&& value) {
			using valueType = std::decay_t<decltype(value)>;
			if constexpr (std::is_same_v<valueType, float>) {
				float val = value;
				H_CORE_MESSAGE("passing {} a float", 1.0f);
			} else {
				H_CORE_WARN("not implemented yet");
			}
		}, value);
	}
	void OpenGLShader::useProgram() {
		glUseProgram(program);
		checkError("glUseProgram");
	}
	void OpenGLShader::deleteShader() {
		glDeleteProgram(program);
	}
	void OpenGLShader::checkError(std::string location) {

		GLenum err;
		while((err = glGetError()) != GL_NO_ERROR) {
			std::string error;
			switch(err) {
				case GL_INVALID_ENUM:      error = "GL_INVALID_ENUM"; break;
				case GL_INVALID_VALUE:     error = "GL_INVALID_VALUE"; break;
				case GL_INVALID_OPERATION: error = "GL_INVALID_OPERATION"; break;
				case GL_STACK_OVERFLOW:    error = "GL_STACK_OVERFLOW"; break;
				case GL_STACK_UNDERFLOW:   error = "GL_STACK_UNDERFLOW"; break;
				case GL_OUT_OF_MEMORY:     error = "GL_OUT_OF_MEMORY"; break;
				case GL_INVALID_FRAMEBUFFER_OPERATION: error = "GL_INVALID_FRAMEBUFFER_OPERATION"; break;
				default:                   error = "Unknown error"; break;
			}
			H_CORE_FATAL("OpenGL error at {}: {} (code: {})", location, error, std::to_string(err));
		}

	}
}