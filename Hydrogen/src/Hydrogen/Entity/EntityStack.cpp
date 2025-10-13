#include "EntityStack.h"

namespace Entity {
	std::vector<Hydrogen::Ref<Entity>> EntityStack::m_entityStack;

	int EntityStack::addEntity(Hydrogen::Ref<Entity> entity) {
		m_entityStack.push_back(entity);
		return (int
				)m_entityStack.size()-1;
	} 
}