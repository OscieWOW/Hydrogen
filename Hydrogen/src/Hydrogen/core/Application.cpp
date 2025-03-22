#include "Application.h"

namespace Hydrogen {
	Application::Application(const appSpecs specs):specs(specs) {
	}
	Application::~Application() {
		
	}

	bool Application::onWindowResize(WindowResize& e) {
		H_CORE_MESSAGE(e.traceEvent());
		return true;
	}
	bool Application::onWindowClose(WindowClose& e) {
		return true;
	}

	bool Application::onGameUpdate(GameUpdate& e) {
		return true;
	}
	bool Application::onGameEvent(GameEvent& e) {
		e.func();
		return true;
	}

	void Application::onEvent(Event& e) {
		Hydrogen::Scope<EventDispatcher> dispatcher = Hydrogen::createScope<EventDispatcher>(e);

		//Window Events
		dispatcher->dispatch<WindowClose>(BIND_EVENT_FUNCTION(onWindowClose));
		dispatcher->dispatch<WindowResize>(BIND_EVENT_FUNCTION(onWindowResize));

		//App Events

		//Key Events

		//Mouse Events

		//GameEvents
		dispatcher->dispatch<GameUpdate>(BIND_EVENT_FUNCTION(onGameUpdate));
		dispatcher->dispatch<GameEvent>(BIND_EVENT_FUNCTION(onGameEvent));
	}
}