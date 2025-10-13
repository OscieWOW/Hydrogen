#pragma once

#include "Entity.h"
#include "../Core/Core.h"

namespace Entity {
	class EntityStack {
		public:
			static int addEntity(Hydrogen::Ref<Entity> entity);

		public:
			static std::vector<Hydrogen::Ref<Entity>> m_entityStack;
	};
}
