#pragma once

#include "../../Hydrogen/Renderer/Window.h"
#include "../../Hydrogen/Renderer/RenderAPI.h"
#include "../../Hydrogen/Core/Core.h"
#include "../../Hydrogen/Events/WindowEvent.h"
#include "../../Hydrogen/Events/KeyEvent.h"
#include "OpenGLRenderAPI.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Hydrogen::OpenGLAPI {
	class  OpenGLWindow:public RenderAPI::Window {
		public:
			OpenGLWindow(RenderAPI::WindowData data);
			~OpenGLWindow() override;
			GLFWwindow* getWindow();
			
			static void windowCloseCallback(GLFWwindow* window);

			void onUpdate() override;
			void onDrawUpdate() override;

		private:
			GLFWwindow* m_window;
	};
}
