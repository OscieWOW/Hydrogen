#pragma once

#include "../Core/Core.h"
#include "../Events/Event.h"
#include "../../Hydrogen/Events/AppEvent.h"
#include "Camera.h"

namespace RenderAPI {

	struct WindowData {
		std::string title;
		int width, height;
		std::function<void(Hydrogen::Event&)> onEvent;
		WindowData(std::string title, int width, int height):title(title),width(width), height(height) {}
	};

	class  Window {
		public:
			static Hydrogen::Ref<Window> createWindow(WindowData data);

		public:
			Window(WindowData data);
			virtual ~Window() = default;
			void setEventCallback(const std::function<void(Hydrogen::Event&)>& func);
			virtual void onUpdate() = 0;
			virtual void onDrawUpdate() = 0;

		public:
			bool windowOpen = false;
			WindowData m_data;

		protected:
	};

	struct  Context {
		int width, height;
		int x, y;
		Hydrogen::Ref<Window> window;
		Camera camera;
		Context(int x, int y, int width, int height, Hydrogen::Ref<Window> window, Camera camera):width(width), height(height), x(x), y(y), window(window), camera(camera) {}
	};
}