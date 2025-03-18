#include "Application.h"

namespace Hydrogen {
	Application::Application(const appSpecs specs):specs(specs) {
	}
	Application::~Application() {
		
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

		dispatcher->dispatch<GameUpdate>([this](GameUpdate& e) {return this->onGameUpdate(e);});
		dispatcher->dispatch<GameEvent>([this](GameEvent& e) {return this->onGameEvent(e); });
	}
}