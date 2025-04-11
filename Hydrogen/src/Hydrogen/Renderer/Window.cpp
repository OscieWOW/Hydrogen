#include "Window.h"
#include "../../Platform/OpenGL/OpenGLAPI.h"

namespace RenderAPI {	

	Hydrogen::Scope<Window> Window::createWindow(WindowData data) {
		switch(renderer) {
			case(Renderers::OpenGL): {
				return Hydrogen::createScope<OpenGLWindow>(data);
				break;
			}
		}
	}
	
	Window::Window(WindowData data):m_data(data) {}
	void Window::setEventCallback(const std::function<void(Hydrogen::Event&)>& func) {
		m_data.onEvent = func;
	}
}