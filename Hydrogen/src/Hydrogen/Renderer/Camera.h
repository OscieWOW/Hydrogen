#pragma once

#include "../Core/Core.h"

namespace RenderAPI {
	class H_API Camera {
		public:
		Camera(int x = 0, int y = 0):x(x), y(y) {}

		public:
		int x, y;
	};
}