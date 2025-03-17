#include <Hydrogen.h>

bool function(Hydrogen::GameEvent& e);

class ExampleApp:public Hydrogen::Application {
	public:
		ExampleApp(Hydrogen::appSpecs appSpecs):Application(appSpecs) {
			
		}
		void run() override {
			H_TRACE("client example trace");
			H_MESSAGE("client example message");
			H_WARN("client example warning");
			H_FATAL("client example fatal");

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
	H_TRACE(e.traceEvent());
	return true;
}