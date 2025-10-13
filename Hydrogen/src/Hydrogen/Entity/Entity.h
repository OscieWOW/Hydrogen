#pragma once

#include "../Core/Core.h"
#include <glm/glm.hpp>

namespace Entity {
	class Entity {
		public:
			Entity(std::string debugName = "Entity"):m_debugName(debugName) {}

		public:
			glm::vec3 pos = glm::vec3(0.0f);
			glm::vec3 rot = glm::vec3(0.0f);
			
		protected:
			std::string m_debugName;
	};
}