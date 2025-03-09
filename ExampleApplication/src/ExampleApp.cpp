#include <Hydrogen.h>

Hydrogen::Application* Hydrogen::createApp() {
	std::string name = "createName";
	Hydrogen::appSpecs appSpec = Hydrogen::appSpecs(&name);

	Hydrogen::Application* app = new Hydrogen::Application(appSpec);
	return app;
}