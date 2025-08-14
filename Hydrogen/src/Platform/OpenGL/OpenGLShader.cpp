#include "OpenGLShader.h"

namespace OpenGLAPI {

	OpenGLShader::OpenGLShader() {
		
	}
	void OpenGLShader::addShaderSource(RenderAPI::ShaderType type, std::string source) {
		std::string code = Hydrogen::File(source, std::ios::in).readAll();
		m_shaderCode[type] = code;
	}
	void OpenGLShader::addShaderCode(RenderAPI::ShaderType type, std::string source) {
		m_shaderCode[type] = source;
	}
	void OpenGLShader::compileProgram() {
		H_CORE_TRACE("compiling shader");
		if(m_shaderCode.size() == 0) {
			H_CORE_FATAL("Please add a source to the shader program");
		}
		m_program = glCreateProgram();
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
			glAttachShader(m_program, shader);
			shaders.push_back(shader);
		}
		glLinkProgram(m_program);

		for(unsigned int i:shaders) {
			glDeleteShader(i);
		}
	}
	void OpenGLShader::passUniform(std::string name, const int value) {
		//H_CORE_MESSAGE("passing {} as an int", value);
		int uniformLocation = glGetUniformLocation(m_program, name.c_str());
		if(uniformLocation == -1) H_CORE_FATAL("Uniform {} not found", name);
		glUniform1i(uniformLocation, value);
		checkError("glUniform1i");
	}
	void OpenGLShader::passUniform(std::string name, const float value) {
		//H_CORE_MESSAGE("passing {} as a float", value);
		int uniformLocation = glGetUniformLocation(m_program, name.c_str());
		if(uniformLocation == -1) H_CORE_FATAL("Uniform {} not found",name);
		glUniform1f(uniformLocation, value);
		checkError("glUniform1f");
	}
	void OpenGLShader::passUniform(std::string name, const glm::mat3 value) {
		//H_CORE_MESSAGE("passing ({}, {}, {})({}, {}, {})({}, {}, {}) as a mat3", value[0].x, value[0].y, value[0].z, value[1].x, value[1].y, value[1].z, value[2].x, value[2].y, value[2].z);
		int uniformLocation = glGetUniformLocation(m_program, name.c_str());
		if(uniformLocation == -1) { H_CORE_FATAL("Uniform {} not found", name); }
		glUniformMatrix3fv(uniformLocation, 1, GL_FALSE, glm::value_ptr(value));
		checkError("glUniformMatrix3fv");
	}
	void OpenGLShader::passUniform(std::string name, const glm::vec3 value) {
		//H_CORE_MESSAGE("passing X:{}, Y:{}, Z:{} as a vec3", value.x, value.y, value.z);
		int uniformLocation = glGetUniformLocation(m_program, name.c_str());
		if(uniformLocation == -1) { H_CORE_FATAL("Uniform {} not found", name); }
		glUniform3fv(uniformLocation, 1, glm::value_ptr(value));
		checkError("glUniform3fv");
	}
	void OpenGLShader::passUniform(std::string name, const glm::mat4 value) {
		//H_CORE_MESSAGE("passing ({}, {}, {}, {})({}, {}, {}, {})({}, {}, {}, {})({}, {}, {}, {}) as a mat4", value[0].x, value[0].y, value[0].z, value[0].w, value[1].x, value[1].y, value[1].z, value[1].w, value[2].x, value[2].y, value[2].z, value[2].w, value[3].x, value[3].y, value[3].z, value[3].w);
		int uniformLocation = glGetUniformLocation(m_program, name.c_str());
		if(uniformLocation == -1) { H_CORE_FATAL("Uniform {} not found", name); }
		glUniformMatrix4fv(uniformLocation, 1, GL_FALSE, glm::value_ptr(value));
		checkError("glUniformMatrix4fv");
	}

	void OpenGLShader::useProgram() {
		glUseProgram(m_program);
		checkError("glUseProgram");
	}
	void OpenGLShader::deleteShader() {
		glDeleteProgram(m_program);
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