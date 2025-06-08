#pragma once

#include "../Core/Core.h"

namespace RenderAPI {
	enum H_API ShaderType {
		VERTEX,
		FRAGMENT
	};

	class H_API Shader {
		public:
			static Hydrogen::Scope<Shader> createShader();

		public:
			Shader() = default;
			virtual void compileProgram() = 0;
			virtual void addShaderSource(ShaderType type, std::string source) = 0;
	};
}
