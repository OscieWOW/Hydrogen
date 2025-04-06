#include "Application.h"

namespace Hydrogen {
	Application::Application(const appSpecs specs):specs(specs) {
	}
	Application::~Application() {
		
	}

	void Application::run() {
		auto appStart = std::chrono::high_resolution_clock::now();

		auto frameStart = std::chrono::high_resolution_clock::now();
		while(running) {
		//for(int i = 0; i<=10000;i++) {
			auto frameTime = std::chrono::high_resolution_clock::now() - frameStart;
			frameStart = std::chrono::high_resolution_clock::now();
			
			GameUpdate gameUpdate = GameUpdate(frameTime);
			onEvent(gameUpdate);
			//if(!running) {
			//	H_CORE_TRACE("running has ended");
			//	i = 10000;
			//}
		}

		auto appDuration = std::chrono::high_resolution_clock::now() - appStart;
		H_CORE_MESSAGE("seconds:" + std::to_string(std::chrono::duration_cast<std::chrono::seconds>(appDuration).count()));
		H_CORE_MESSAGE("nanoseconds:" + std::to_string(std::chrono::duration_cast<std::chrono::nanoseconds>(appDuration).count()));
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
}