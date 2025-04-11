#include "OpenGLAPI.h"

namespace RenderAPI {
	OpenGLWindow::OpenGLWindow(WindowData data):Window(data) {
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		m_window = glfwCreateWindow(data.width, data.height, data.title.c_str(), NULL, NULL);
		if(m_window == NULL) {
			H_CORE_FATAL("GLFW WINDOW FAILED TO CREATE");
			glfwTerminate();
			exit(-1);
		}
		glfwSetWindowUserPointer(m_window, &m_data);
		
		glfwMakeContextCurrent(m_window);
		windowOpen = true;

		glfwSetWindowCloseCallback(m_window, [](GLFWwindow* window) {
			WindowData* data = (WindowData*)glfwGetWindowUserPointer(window);
			Hydrogen::WindowClose e = Hydrogen::WindowClose();
			if(data && data->onEvent) {
				data->onEvent(e);
			} else {
				H_CORE_FATAL("window data is a null pointer");
			}
		});
	}
	OpenGLWindow::~OpenGLWindow() {
		glfwDestroyWindow(m_window);
		glfwTerminate();
	}

	void OpenGLWindow::update() {
		glfwPollEvents();
	}
}

