#include <Hydrogen.h>
#include <Hydrogen/Core/EntryPoint.h>

#include "ExampleLayer.h"

class ExampleApp:public Hydrogen::Application {
	public:
		ExampleApp(Hydrogen::appSpecs appSpecs, Hydrogen::Ref<RenderAPI::Renderer> renderer):Application(appSpecs, std::move(renderer)) {
			Hydrogen::Scope<ExampleLayer> exampleLayer = Hydrogen::createScope<ExampleLayer>(m_renderer, "GAME UPDATES");
			m_layerStack.pushLayer(std::move(exampleLayer));	
		}
};

Hydrogen::Application* Hydrogen::createApp() {
	std::string name = "Hydrogen";	
	Hydrogen::appSpecs appSpec = Hydrogen::appSpecs(&name);

	Hydrogen::Scope<RenderAPI::Shader> shader = RenderAPI::Shader::createShader();
	shader->addShaderSource(RenderAPI::ShaderType::VERTEX, "Assets\\Shaders\\VertexShader.vert");

	Hydrogen::Ref<RenderAPI::Renderer> renderer = RenderAPI::Renderer::createRenderer(std::move(shader));

	ExampleApp* app = new ExampleApp(appSpec,std::move(renderer));
	return app;
}	