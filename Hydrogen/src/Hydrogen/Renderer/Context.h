#pragma once

#include "Window.h"
#include "../Core/Core.h"

namespace RenderAPI {
	class H_API Context {
		public:
			Context(int width, int height, int x, int y, Hydrogen::Handle<RenderAPI::Window> window):width(width), height(height), x(x), y(y), h_window(window) {}

		public:
			int width, height;
			int x, y;
			Hydrogen::Handle<RenderAPI::Window> h_window;
	};
}
