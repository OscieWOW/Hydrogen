#pragma once

#include "../../Hydrogen/Renderer/Window.h"
#include "../../Hydrogen/Core/Core.h"
#include "../../Hydrogen/Events/WindowEvent.h"
#include "../../Hydrogen/Events/AppEvent.h"

#include <GLAD/glad.h>
#include <GLFW/glfw3.h>

namespace RenderAPI {
	class H_API OpenGLWindow:public Window {
		public:
			OpenGLWindow(WindowData data);
			~OpenGLWindow() override;

			void update() override;

		private:
			GLFWwindow* m_window;
	};
}