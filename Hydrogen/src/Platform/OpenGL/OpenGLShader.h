#pragma once

#include "../../Hydrogen/Core/Core.h"
#include "../../Hydrogen/Renderer/Shader.h"
#include "../../Hydrogen/Core/Log.h"

#include <GLAD/glad.h>

namespace OpenGLAPI {
	class H_API OpenGLShader: public RenderAPI::Shader {
		public:
			OpenGLShader();
			void addShaderSource(RenderAPI::ShaderType type, std::string source) override;
			void compileProgram() override;
			void useProgram() override;
			void deleteShader() override;

		private:
			std::map<RenderAPI::ShaderType, std::string> shaderSource;
			std::vector<unsigned int> shaders;
			unsigned int program;
	};
}