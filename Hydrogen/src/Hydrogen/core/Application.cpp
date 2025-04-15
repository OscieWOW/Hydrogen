#include "Application.h"

namespace Hydrogen {
	Application::Application(const appSpecs specs):specs(specs) {
		RenderAPI::WindowData windowData = RenderAPI::WindowData(*specs.appName,800,600);
		m_window = RenderAPI::Window::createWindow(windowData);
		m_window->setEventCallback(BIND_EVENT_FUNCTION(onEvent));
	}
	Application::~Application() {
	}

	void Application::run() {
		auto frameStart = std::chrono::high_resolution_clock::now();
		while(running && m_window->windowOpen) {
			auto frameTime = std::chrono::high_resolution_clock::now() - frameStart;
			frameStart = std::chrono::high_resolution_clock::now();
			
			GameUpdate gameUpdate = GameUpdate(frameTime);
			onEvent(gameUpdate);

			m_window->update();
		}
	}

	void Application::onEvent(Event& e) {
		Hydrogen::Scope<EventDispatcher> dispatcher = Hydrogen::createScope<EventDispatcher>(e);

		//App Events
		dispatcher->dispatch<AppUpdate>(BIND_EVENT_FUNCTION(onAppUpdate));
		dispatcher->dispatch<AppRender>(BIND_EVENT_FUNCTION(onAppRender));

		//Window Events
		dispatcher->dispatch<WindowClose>(BIND_EVENT_FUNCTION(onWindowClose));
		dispatcher->dispatch<WindowResize>(BIND_EVENT_FUNCTION(onWindowResize));
		dispatcher->dispatch<WindowFocus>(BIND_EVENT_FUNCTION(onWindowFocus));
		dispatcher->dispatch<WindowLostFocus>(BIND_EVENT_FUNCTION(onWindowLostFocus));

		m_layerStack.onEvent(e);
	}

	bool Application::onAppUpdate(AppUpdate& e) {
		H_CORE_MESSAGE(e.traceEvent());
		return true;
	}
	bool Application::onAppRender(AppRender& e) {
		return true;
	}

	bool Application::onWindowClose(WindowClose& e) {
		H_CORE_MESSAGE(e.traceEvent());
		running = false;
		return true;
	}
	bool Application::onWindowResize(WindowResize& e) {
		H_CORE_MESSAGE(e.traceEvent());
		return true;
	}
	bool Application::onWindowFocus(WindowFocus& e) {
		H_CORE_MESSAGE(e.traceEvent());
		return true;
	}
	bool Application::onWindowLostFocus(WindowLostFocus& e){
		H_CORE_MESSAGE(e.traceEvent());
		return true;
	}
}