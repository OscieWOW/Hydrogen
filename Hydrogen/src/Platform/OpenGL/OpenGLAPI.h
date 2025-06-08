#pragma once

#include "../../Hydrogen/Renderer/Window.h"
#include "../../Hydrogen/Renderer/RenderAPI.h"
#include "../../Hydrogen/Core/Core.h"
#include "../../Hydrogen/Events/WindowEvent.h"
#include "../../Hydrogen/Events/KeyEvent.h"
#include "OpenGLRenderAPI.h"

#include <GLAD/glad.h>
#include <GLFW/glfw3.h>

namespace OpenGLAPI {
	class H_API OpenGLWindow:public RenderAPI::Window {
		public:
			OpenGLWindow(RenderAPI::WindowData data, Hydrogen::Handle<OpenGLAPI::OpenGLRenderer> renderer);
			~OpenGLWindow() override;

			void update() override;
			void render() override;

			operator GLFWwindow*();

		private:
			GLFWwindow* m_window;
			Hydrogen::Handle<OpenGLRenderer> m_renderer;
			
	};
}