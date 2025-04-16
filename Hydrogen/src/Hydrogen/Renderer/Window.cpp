#include "Window.h"
#include "../../Platform/OpenGL/OpenGLAPI.h"

namespace RenderAPI {	

	Hydrogen::Scope<Window> Window::createWindow(WindowData data, Hydrogen::Handle<Renderer> renderer) {
		switch(renderAPI) {
			case(Renderers::OpenGL): {
				return Hydrogen::createScope<OpenGLAPI::OpenGLWindow>(data, std::dynamic_pointer_cast<OpenGLAPI::OpenGLRenderer>(renderer.lock()));
				break;
			}
		}
	}
	
	Window::Window(WindowData data):m_data(data) {}
	void Window::setEventCallback(const std::function<void(Hydrogen::Event&)>& func) {
		m_data.onEvent = func;
	}
}