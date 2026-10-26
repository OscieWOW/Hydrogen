#pragma once

#include "../Core/Core.h"
#include <glm/glm.hpp>

namespace Hydrogen::ResourceManager::Entity {
	class Entity {
		public:
			Entity(const std::string& debugName = "Entity"):m_debugName(debugName) {}

			glm::vec3 getPos() { return pos; }
			glm::vec3 getRot() { return lookAt; }

			void translate(glm::vec3 dpos) {
				pos += dpos;
				lookAt += dpos;
			}
			void rotate(glm::vec2 theta) {
				
			}

			glm::vec3 pos = glm::vec3(0.0f, 0.0f, 0.0f);
			glm::vec3 lookAt = glm::vec3(0.0f, 0.0f, -1.0f) + pos;
		
		protected:
			std::string m_debugName;
	};

	class EntityStack {
		public:
			EntityStack() = default;
			int addEntity(Hydrogen::Ref<Entity> entity) {
				m_entityStack.push_back(entity);
				return m_entityStack.size()-1;
			}
			Ref<Entity> getEntity(int index) {
				return m_entityStack[index];
			}

		public:
			std::vector<Hydrogen::Ref<Entity>> m_entityStack;
	};
}
