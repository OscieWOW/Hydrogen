#pragma once

#include "../Core/Core.h"
#include "EntityStack.h"
#include "../Renderer/Mesh.h"

namespace Hydrogen::ResourceManager {
	class ResourceManager {
		public:
			ResourceManager();

			void init();
			int loadMesh(const std::string& fileName);

			Ref<Entity::EntityStack> entityStack;
			std::vector<RenderAPI::Mesh> meshStack;
	};
}
