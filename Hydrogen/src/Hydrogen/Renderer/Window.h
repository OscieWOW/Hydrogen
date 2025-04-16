#pragma once

#include "../Core/Core.h"
#include "../Events/Event.h"
#include "../../Hydrogen/Events/AppEvent.h"
#include "RenderAPI.h"

namespace RenderAPI {
	enum class H_API Renderers {
		OpenGL
	};
	static Renderers renderAPI = Renderers::OpenGL;

	struct WindowData {
		std::string title;
		int width, height;
		std::function<void(Hydrogen::Event&)> onEvent;
		WindowData(std::string title, int width, int height):title(title),width(width), height(height) {}
	};
	class H_API Window {
		public:
			static Hydrogen::Scope<Window> createWindow(WindowData data, Hydrogen::Handle<Renderer> renderer);

		public:
			Window(WindowData data);
			virtual ~Window() = default;
			void setEventCallback(const std::function<void(Hydrogen::Event&)>& func);
			virtual void update() = 0;
			virtual void render() = 0;

			bool windowOpen = false;

		protected:
			WindowData m_data;
	};
}