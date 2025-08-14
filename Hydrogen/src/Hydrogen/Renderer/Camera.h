#pragma once

#include "../Core/Core.h"
#include <glm/glm.hpp>

namespace RenderAPI {
	class  Camera {
		public:
		Camera(glm::vec3 pos):pos(pos) {}

		public:
			glm::vec3 pos;
	};
}