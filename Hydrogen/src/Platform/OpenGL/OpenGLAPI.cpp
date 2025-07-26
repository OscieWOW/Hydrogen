#include "OpenGLAPI.h"

namespace OpenGLAPI {
	OpenGLWindow::OpenGLWindow(RenderAPI::WindowData data):Window(data) {
		m_window = glfwCreateWindow(data.width, data.height, data.title.c_str(), NULL, NULL);
		if(m_window == NULL) {
			H_CORE_FATAL("GLFW WINDOW FAILED TO CREATE");
			glfwTerminate();
			exit(-1);
		}
		glfwSetWindowUserPointer(m_window, &m_data);
		
		glfwMakeContextCurrent(m_window);
		windowOpen = true;

		H_CORE_TRACE("Init GLAD");
		if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
			H_CORE_FATAL("Failed to initialize GLAD");
			exit(-1);
		}

		glfwSetWindowCloseCallback(m_window, [](GLFWwindow* window) {
			RenderAPI::WindowData* data = (RenderAPI::WindowData*)glfwGetWindowUserPointer(window);

			Hydrogen::WindowClose e = Hydrogen::WindowClose();
			data->onEvent(e);
		});

		glfwSetWindowSizeCallback(m_window, [](GLFWwindow* window, int width, int height) {
			RenderAPI::WindowData* data = (RenderAPI::WindowData*)glfwGetWindowUserPointer(window);

			Hydrogen::WindowResize e = Hydrogen::WindowResize(width, height);
			data->onEvent(e);
		});

		glfwSetFramebufferSizeCallback(m_window, [](GLFWwindow* window, int width, int height) {
			glViewport(0,0,width, height);
		});

		glfwSetWindowFocusCallback(m_window, [](GLFWwindow* window, int focus) {
			RenderAPI::WindowData* data = (RenderAPI::WindowData*)glfwGetWindowUserPointer(window);
			
			if(focus == GLFW_TRUE) {
				Hydrogen::WindowFocus e = Hydrogen::WindowFocus();
				data->onEvent(e);
			} else {
				Hydrogen::WindowLostFocus e = Hydrogen::WindowLostFocus();
				data->onEvent(e);
			}
		});

		glfwSetKeyCallback(m_window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
			RenderAPI::WindowData* data = (RenderAPI::WindowData*)glfwGetWindowUserPointer(window);
			switch(action) {
				case(GLFW_PRESS):
				{
					Hydrogen::KeyPressed e = Hydrogen::KeyPressed(key,false);
					data->onEvent(e);
					break;
				}
				case(GLFW_RELEASE):
				{
					Hydrogen::KeyReleased e = Hydrogen::KeyReleased(key);
					data->onEvent(e);
					break;
				}
				case(GLFW_REPEAT):
				{
					Hydrogen::KeyPressed e = Hydrogen::KeyPressed(key, true);
					data->onEvent(e);
					break;
				}
			}
		});

		glfwSetWindowPosCallback(m_window, [](GLFWwindow* window, int x, int y) {
			RenderAPI::WindowData* data = (RenderAPI::WindowData*)glfwGetWindowUserPointer(window);

			Hydrogen::WindowMoved e = Hydrogen::WindowMoved(x,y);
			data->onEvent(e);
		});

		glfwSetMouseButtonCallback(m_window, [](GLFWwindow* window,int button, int action, int mods) {
			RenderAPI::WindowData* data = (RenderAPI::WindowData*)glfwGetWindowUserPointer(window);

			switch(action) {
				case(GLFW_PRESS): {
					Hydrogen::MouseButtonPressed e = Hydrogen::MouseButtonPressed(button);
					data->onEvent(e);
					break;
				}
				case(GLFW_RELEASE):
				{
					Hydrogen::MouseButtonReleased e = Hydrogen::MouseButtonReleased(button);
					data->onEvent(e);
					break;
				}
			}
		});

		glfwSetCursorPosCallback(m_window, [](GLFWwindow* window, double x, double y) {
			RenderAPI::WindowData* data = (RenderAPI::WindowData*)glfwGetWindowUserPointer(window);

			Hydrogen::MouseMoved e = Hydrogen::MouseMoved((int)x, (int)y);
			data->onEvent(e);
		});

		glfwSetScrollCallback(m_window, [](GLFWwindow* window, double xOffset, double yOffset) {
			RenderAPI::WindowData* data = (RenderAPI::WindowData*)glfwGetWindowUserPointer(window);

			Hydrogen::MouseScrolled e = Hydrogen::MouseScrolled(yOffset);
			data->onEvent(e);
		});
	}
	OpenGLWindow::~OpenGLWindow() {
		glfwDestroyWindow(m_window);
		glfwTerminate();
	}
	GLFWwindow* OpenGLWindow::getWindow() {
		return m_window;
	}

	void OpenGLWindow::onUpdate() {
		glfwPollEvents();
	}
	void OpenGLWindow::onDrawUpdate() {
		glfwSwapBuffers(m_window);
	}
}

