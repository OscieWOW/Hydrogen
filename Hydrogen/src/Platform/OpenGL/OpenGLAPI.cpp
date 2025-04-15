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

		if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
			H_CORE_FATAL("Failed to initialize GLAD");
			exit(-1);
		}
		glViewport(0,0,data.width, data.height);

		glfwSetWindowCloseCallback(m_window, [](GLFWwindow* window) {
			WindowData* data = (WindowData*)glfwGetWindowUserPointer(window);

			Hydrogen::WindowClose e = Hydrogen::WindowClose();
			data->onEvent(e);
		});

		glfwSetWindowSizeCallback(m_window, [](GLFWwindow* window, int width, int height) {
			WindowData* data = (WindowData*)glfwGetWindowUserPointer(window);

			Hydrogen::WindowResize e = Hydrogen::WindowResize(width, height);
			data->onEvent(e);
		});

		glfwSetFramebufferSizeCallback(m_window, [](GLFWwindow* window, int width, int height) {
			glViewport(0,0,width, height);
		});

		glfwSetWindowFocusCallback(m_window, [](GLFWwindow* window, int focus) {
			WindowData* data = (WindowData*)glfwGetWindowUserPointer(window);
			
			if(focus == GLFW_TRUE) {
				Hydrogen::WindowFocus e = Hydrogen::WindowFocus();
				data->onEvent(e);
			} else {
				Hydrogen::WindowLostFocus e = Hydrogen::WindowLostFocus();
				data->onEvent(e);
			}
		});
	}
	OpenGLWindow::~OpenGLWindow() {
		glfwDestroyWindow(m_window);
		glfwTerminate();
	}

	void OpenGLWindow::update() {
		glfwPollEvents();

		glClearColor(0.2f, 0.1f, 0.5f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(m_window);
	}
}

