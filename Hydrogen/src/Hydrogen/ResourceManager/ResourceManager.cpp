#include "ResourceManager.h"

namespace Hydrogen::ResourceManager {
	ResourceManager::ResourceManager() {
		entityStack = createRef<Entity::EntityStack>();
	}

	void ResourceManager::init() {}
	int loadMesh(const std::string& fileName) {
		return 0;
	}
}
