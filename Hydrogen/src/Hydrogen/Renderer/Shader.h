#pragma once

#include "../Core/Core.h"
#include <glm/glm.hpp>

namespace RenderAPI {
	enum  ShaderType {
		VERTEX,
		FRAGMENT
	};

	class  Shader {
		public:
			static Hydrogen::Scope<Shader> createShader();

		public:
			Shader() = default;
			virtual void compileProgram() = 0;
			virtual void addShaderSource(ShaderType type, std::string source) = 0;
			virtual void addShaderCode(ShaderType type, std::string source) = 0;
			virtual void passUniform(std::string name, std::variant<int, float, glm::mat3, glm::vec3, glm::mat4> value) = 0;
			virtual void useProgram() = 0;
			virtual void deleteShader() = 0;
	};
}
