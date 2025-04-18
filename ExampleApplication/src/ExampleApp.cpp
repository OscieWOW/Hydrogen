#include <Hydrogen.h>
#include <Hydrogen/Core/EntryPoint.h>

#include "ExampleLayer.h"

class ExampleApp:public Hydrogen::Application {
	public:
		ExampleApp(Hydrogen::appSpecs appSpecs):Application(appSpecs) {
			Hydrogen::Scope<ExampleLayer> exampleLayer = Hydrogen::createScope<ExampleLayer>(m_renderer, "GAME UPDATES");
			m_layerStack.pushLayer(std::move(exampleLayer));
		}
};

Hydrogen::Application* Hydrogen::createApp() {
	std::string name = "Hydrogen";	
	Hydrogen::appSpecs appSpec = Hydrogen::appSpecs(&name);

	ExampleApp* app = new ExampleApp(appSpec);
	return app;
}	