#include "Application.h"

namespace Hydrogen {
	Application::Application(const appSpecs specs):specs(specs) {
	}
	Application::~Application() {
		
	}

	bool Application::onWindowClose(WindowClose& e) {
		return true;
	}
	bool Application::onWindowResize(WindowResize& e) {
		H_CORE_MESSAGE(e.traceEvent());
		return true;
	}
	bool Application::onWindowFocus(WindowFocus& e) {
		return true;
	}
	bool Application::onWindowLostFocus(WindowLostFocus& e) {
		return true;
	}
	bool Application::onWindowMoved(WindowMoved& e) {
		H_CORE_MESSAGE(e.traceEvent());
		return true;
	}

	bool Application::onAppUpdate(AppUpdate& e) {
		H_CORE_MESSAGE(e.traceEvent());
		return true;
	}
	bool Application::onAppRender(AppRender& e) {
		return true;
	}


	void Application::onEvent(Event& e) {
		Hydrogen::Scope<EventDispatcher> dispatcher = Hydrogen::createScope<EventDispatcher>(e);

		//Window Events
		dispatcher->dispatch<WindowClose>(BIND_EVENT_FUNCTION(onWindowClose));
		dispatcher->dispatch<WindowResize>(BIND_EVENT_FUNCTION(onWindowResize));
		dispatcher->dispatch<WindowFocus>(BIND_EVENT_FUNCTION(onWindowFocus));
		dispatcher->dispatch<WindowFocus>(BIND_EVENT_FUNCTION(onWindowFocus));
		dispatcher->dispatch<WindowLostFocus>(BIND_EVENT_FUNCTION(onWindowLostFocus));
		dispatcher->dispatch<WindowMoved>(BIND_EVENT_FUNCTION(onWindowMoved));

		//App Events
		dispatcher->dispatch<AppUpdate>(BIND_EVENT_FUNCTION(onAppUpdate));
		dispatcher->dispatch<AppRender>(BIND_EVENT_FUNCTION(onAppRender));

		m_layerStack.onEvent(e);
	}
}