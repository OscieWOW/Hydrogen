#pragma once

#include "../../Hydrogen/Core/Core.h"
#include "../../Hydrogen/Renderer/Shader.h"
#include "../../Hydrogen/Core/Log.h"

#include <GLAD/glad.h>

namespace OpenGLAPI {
	class  OpenGLShader: public RenderAPI::Shader {
		public:
			OpenGLShader();
			void compileProgram() override;
			void addShaderSource(RenderAPI::ShaderType type, std::string source) override;
			void addShaderCode(RenderAPI::ShaderType type, std::string source) override;
			void passUniform(std::string name, std::variant<int, float, glm::mat3, glm::vec3, glm::mat4> value) override;
			void useProgram() override;
			void deleteShader() override;
			void checkError(std::string location);

		private:
			std::map<RenderAPI::ShaderType, std::string> m_shaderCode = {};
			std::vector<unsigned int> shaders;
			unsigned int program;
	};
}