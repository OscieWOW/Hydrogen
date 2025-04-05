#include "ExampleLayer.h"

ExampleLayer::ExampleLayer(const std::string& name):Layer(name) {
}
void ExampleLayer::onEvent(Hydrogen::Event& e) {
	Hydrogen::EventDispatcher eventDispatcher = Hydrogen::EventDispatcher(e);
	eventDispatcher.dispatch<Hydrogen::GameUpdate>(BIND_EVENT_FUNCTION(onGameUpdate));
}
void ExampleLayer::onUpdate(float deltaTime) {
	m_layerLog.logMessage("on update "+std::to_string(deltaTime));
}
void ExampleLayer::onAttach() {
	m_layerLog.logMessage("on attach");
}
void ExampleLayer::onDetach() {
	m_layerLog.logMessage("on detach");
}

bool ExampleLayer::onGameUpdate(Hydrogen::GameUpdate& e) {
	m_layerLog.logMessage(e.traceEvent());
	return true;
}