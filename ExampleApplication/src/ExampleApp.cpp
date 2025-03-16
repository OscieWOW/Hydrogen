#include <Hydrogen.h>

class ExampleApp:public Hydrogen::Application {
	public:
		ExampleApp(Hydrogen::appSpecs appSpecs):Application(appSpecs) {
			
		}
		void run() override {
			H_MESSAGE("hello from client");
		}
};

Hydrogen::Application* Hydrogen::createApp() {
	std::string name = "createName";
	Hydrogen::appSpecs appSpec = Hydrogen::appSpecs(&name);

	ExampleApp* app = new ExampleApp(appSpec);
	return app;
}