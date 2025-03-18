#include <Hydrogen.h>

bool uponGameUpdate(Hydrogen::GameUpdate& e);

class ExampleApp:public Hydrogen::Application {
	public:
		ExampleApp(Hydrogen::appSpecs appSpecs):Application(appSpecs) {
			
		}
		void run() override {
			Hydrogen::Scope<Hydrogen::GameEvent> e = Hydrogen::createScope<Hydrogen::GameEvent>(Hydrogen::EventType::GameEvent, []() {
				H_MESSAGE("Game event");
			});
			onEvent(*e);
		}
};

Hydrogen::Application* Hydrogen::createApp() {
	std::string name = "createName";	
	Hydrogen::appSpecs appSpec = Hydrogen::appSpecs(&name);

	ExampleApp* app = new ExampleApp(appSpec);
	return app;
}

bool uponGameUpdate(Hydrogen::GameUpdate& e) {
	H_MESSAGE("This game event reports that it has been "+e.traceEvent());
	return true;
}