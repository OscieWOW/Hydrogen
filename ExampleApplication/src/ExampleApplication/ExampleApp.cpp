#include <Hydrogen.h>
#include <Hydrogen/Core/EntryPoint.h>

#include "ExampleLayer.h"

class ExampleApp:public Hydrogen::Application {
	public:
		ExampleApp(Hydrogen::appSpecs appSpecs):Application(appSpecs) {
			Hydrogen::Scope<ExampleLayer> exampleLayer = Hydrogen::createScope<ExampleLayer>(m_renderEngine, Hydrogen::LayerData(BIND_EVENT_FUNCTION(onEvent),"ExampleLayer"));
			m_layerStack.pushLayer(std::move(exampleLayer));	
		}
};

Hydrogen::Application* Hydrogen::createApp() {
	Hydrogen::appSpecs appSpec = Hydrogen::appSpecs("Hydrogen",RenderAPI::Renderers::OpenGL);

	ExampleApp* app = new ExampleApp(appSpec);
	return app;
}	