#pragma once

#include "../Core/Core.h"
#include <glm/matrix.hpp>

namespace RenderAPI {
	struct  Vertex {
		glm::vec3 pos;
		glm::vec3 normal;
		glm::vec2 textCoord;
		Vertex(glm::vec3 pos, glm::vec3 normal, glm::vec2 textCoord):pos(pos),normal(normal), textCoord(textCoord) {}
	};

	class  Mesh {
		public:
			Mesh(std::vector<Vertex> verticies, std::vector<unsigned int> indicies, const char* texture):verticies(verticies), indicies(indicies), texture(texture) {}

		public:
			std::vector<Vertex> verticies;
			std::vector<unsigned int> indicies;
			const char* texture;
	};
}
