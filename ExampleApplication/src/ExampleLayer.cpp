#include "ExampleLayer.h"

ExampleLayer::ExampleLayer(Hydrogen::Handle<RenderAPI::Renderer> renderer, const std::string& name):Layer(name),renderer(renderer) {
	if(!renderer) {
		H_CORE_FATAL("PASSED RENDERER WAS NULL");
	} else {
		H_CORE_FATAL("PASSED RENDERER WAS NOT NULL");
		//renderer->setClearColour(RenderAPI::Colour(255, 230, 0, 255));
	}
}
void ExampleLayer::onEvent(Hydrogen::Event& e) {
	Hydrogen::EventDispatcher dispatcher = Hydrogen::EventDispatcher(e);
	dispatcher.dispatch<Hydrogen::KeyPressed>(BIND_EVENT_FUNCTION(onKeyPress));
}
void ExampleLayer::onUpdate(std::chrono::nanoseconds deltaTime) {
	m_layerLog.logMessage("on update "+std::to_string(deltaTime.count()));
}
void ExampleLayer::onAttach() {
	m_layerLog.logMessage("on attach");
}
void ExampleLayer::onDetach() {
	m_layerLog.logMessage("on detach");
}

bool ExampleLayer::onKeyPress(Hydrogen::KeyPressed& e) {
	if(e.getKeycode() == Hydrogen::Key::W) {
		if(colourState1 == 0) {
			renderer->setClearColour(RenderAPI::Colour(255, 230, 0, 255));
			colourState1 = 1;
		} else {
			renderer->setClearColour(RenderAPI::Colour(246, 110, 0, 255));
			colourState1 = 0;
		}
	}
	if(e.getKeycode() == Hydrogen::Key::S) {
		if(colourState2 == 0) {
			renderer->setClearColour(RenderAPI::Colour(213, 105, 174, 255));
			colourState2 = 1;
		} else {
			renderer->setClearColour(RenderAPI::Colour(75, 255, 152, 255));
			colourState2 = 0;
		}
	}
	return true;
}

