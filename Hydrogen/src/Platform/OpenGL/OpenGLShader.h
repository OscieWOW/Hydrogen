#pragma once

#include "../../Hydrogen/Core/Core.h"
#include "../../Hydrogen/Renderer/Shader.h"
#include "../../Hydrogen/Core/Log.h"

namespace OpenGLAPI {
	class H_API OpenGLShader: public RenderAPI::Shader {
		public:
			OpenGLShader();
			void addShaderSource(RenderAPI::ShaderType type, std::string source) override;
			void compileProgram() override;
	};
}