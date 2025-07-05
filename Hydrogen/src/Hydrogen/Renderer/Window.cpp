#include "Window.h"
#include "../../Platform/OpenGL/OpenGLAPI.h"

namespace RenderAPI {	

	Hydrogen::Ref<Window> Window::createWindow(WindowData data) {
		switch(renderAPI) {
			case(Renderers::OpenGL): {
				return Hydrogen::createRef<OpenGLAPI::OpenGLWindow>(data);
				break;
			}
		}
	}
	
	Window::Window(WindowData data):m_data(data) {}
	void Window::setEventCallback(const std::function<void(Hydrogen::Event&)>& func) {
		m_data.onEvent = func;
	}
}