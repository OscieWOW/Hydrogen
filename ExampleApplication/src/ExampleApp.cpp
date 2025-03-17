#include <Hydrogen.h>

bool function(Hydrogen::GameEvent& e);

class ExampleApp:public Hydrogen::Application {
	public:
		ExampleApp(Hydrogen::appSpecs appSpecs):Application(appSpecs) {
			
		}
		void run() override {
			Hydrogen::Scope<Hydrogen::GameEvent> e = Hydrogen::createScope<Hydrogen::GameEvent>(Hydrogen::EventType::GameEvent,1.0f);
			Hydrogen::EventDispatcher dispatcher = Hydrogen::EventDispatcher(*e);
			dispatcher.dispatch<Hydrogen::GameEvent>(function);
		}
};

Hydrogen::Application* Hydrogen::createApp() {
	std::string name = "createName";	
	Hydrogen::appSpecs appSpec = Hydrogen::appSpecs(&name);

	ExampleApp* app = new ExampleApp(appSpec);
	return app;
}

bool function(Hydrogen::GameEvent& e) {
	H_MESSAGE("This game event reports that it has been "+e.traceEvent());
	return true;
}