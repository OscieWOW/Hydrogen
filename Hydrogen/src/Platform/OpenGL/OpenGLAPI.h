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
	class  OpenGLWindow:public RenderAPI::Window {
		public:
			OpenGLWindow(RenderAPI::WindowData data);
			~OpenGLWindow() override;
			GLFWwindow* getWindow();

			void onUpdate() override;
			void onDrawUpdate() override;

		private:
			GLFWwindow* m_window;
	};
}