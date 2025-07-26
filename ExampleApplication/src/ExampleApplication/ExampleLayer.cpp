#include "ExampleLayer.h"

ExampleLayer::ExampleLayer(Hydrogen::Handle<RenderAPI::RenderEngine> renderEngine, const Hydrogen::LayerData layerData):Layer(layerData),m_renderEngine(renderEngine) {
}
void ExampleLayer::onEvent(Hydrogen::Event& e) {
	Hydrogen::EventDispatcher dispatcher = Hydrogen::EventDispatcher(e);
	dispatcher.dispatch<Hydrogen::KeyPressed>(BIND_EVENT_FUNCTION(onKeyPress));
}
void ExampleLayer::onUpdate(std::chrono::nanoseconds deltaTime) {
	m_layerLog.logMessage("on update {}",std::to_string(deltaTime.count()));
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
			m_renderEngine->setClearColour(RenderAPI::Colour(255, 230, 0, 255));
			colourState1 = 1;
		} else {
			m_renderEngine->setClearColour(RenderAPI::Colour(246, 110, 0, 255));
			colourState1 = 0;
		}
	}
	if(e.getKeycode() == Hydrogen::Key::S) {
		if(colourState2 == 0) {
			m_renderEngine->setClearColour(RenderAPI::Colour(213, 105, 174, 255));
			colourState2 = 1;
		} else {
			m_renderEngine->setClearColour(RenderAPI::Colour(75, 255, 152, 255));
			colourState2 = 0;
		}
	}
	if(e.getKeycode() == Hydrogen::Key::Escape) {
		Hydrogen::WindowClose e = Hydrogen::WindowClose();
		m_layerData.onEvent(e);
	}
	return true;
}

