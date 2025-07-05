#pragma once

#include "../Core/Core.h"
#include <glm/matrix.hpp>

namespace RenderAPI {
	struct H_API Vertex {
		glm::vec3 pos;
		glm::vec3 normal;
	};

	class H_API Mesh {
		public:
			Mesh(std::vector<Vertex> vertecies);

		protected:
			std::vector<Vertex> m_vertecies;
	};
}

