#pragma once

#include "../Core/Core.h"
#include "../Events/Event.h"
#include "../../Hydrogen/Events/AppEvent.h"
//#include "RenderAPI.h"

namespace RenderAPI {

	struct WindowData {
		std::string title;
		int width, height;
		std::function<void(Hydrogen::Event&)> onEvent;
		WindowData(std::string title, int width, int height):title(title),width(width), height(height) {}
	};
	class H_API Window {
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
}