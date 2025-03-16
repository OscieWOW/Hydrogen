#include <Hydrogen.h>

class ExampleApp:public Hydrogen::Application {
	public:
		ExampleApp(Hydrogen::appSpecs appSpecs):Application(appSpecs) {
			
		}
		void run() override {
			H_TRACE("client example trace");
			H_MESSAGE("client example message");
			H_WARN("client example warning");
			H_FATAL("client example fatal");
		}
};

Hydrogen::Application* Hydrogen::createApp() {
	std::string name = "createName";
	Hydrogen::appSpecs appSpec = Hydrogen::appSpecs(&name);

	ExampleApp* app = new ExampleApp(appSpec);
	return app;
}