#include <Hydrogen.h>
#include <Hydrogen/Core/EntryPoint.h>

#include "ExampleLayer.h"

class ExampleApp:public Hydrogen::Application {
	public:
		ExampleApp(Hydrogen::appSpecs appSpecs):Application(appSpecs) {}

		void run() override {
			Hydrogen::Scope<ExampleLayer> layer = Hydrogen::createScope<ExampleLayer>("name");
			m_layerStack.pushLayer(std::move(layer));
			
			Hydrogen::GameUpdate e = Hydrogen::GameUpdate(5.61f);
			onEvent(e);
			}
};

Hydrogen::Application* Hydrogen::createApp() {
	std::string name = "createName";	
	Hydrogen::appSpecs appSpec = Hydrogen::appSpecs(&name);

	ExampleApp* app = new ExampleApp(appSpec);
	return app;
}	