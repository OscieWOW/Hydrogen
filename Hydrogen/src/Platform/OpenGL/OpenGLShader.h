#pragma once

#include "../../Hydrogen/Core/Core.h"
#include "../../Hydrogen/Renderer/Shader.h"
#include "../../Hydrogen/Core/Log.h"
#include <glm/gtc/type_ptr.hpp>

#include <GLAD/glad.h>

namespace OpenGLAPI {
	class  OpenGLShader: public RenderAPI::Shader {
		public:
			OpenGLShader();
			void compileProgram() override;
			void addShaderSource(RenderAPI::ShaderType type, std::string source) override;
			void addShaderCode(RenderAPI::ShaderType type, std::string source) override;
			void passUniform(std::string name, const int value) override;
			void passUniform(std::string name, const float value) override;
			void passUniform(std::string name, const glm::mat3 value) override;
			void passUniform(std::string name, const glm::vec3 value) override;
			void passUniform(std::string name, const glm::mat4 value) override;
			void useProgram() override;
			void deleteShader() override;
			void checkError(std::string location);

		private:
			std::map<RenderAPI::ShaderType, std::string> m_shaderCode = {};
			std::vector<unsigned int> shaders;
			unsigned int m_program;
	};
}