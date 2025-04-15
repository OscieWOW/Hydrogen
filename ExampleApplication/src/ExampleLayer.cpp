#include "ExampleLayer.h"

ExampleLayer::ExampleLayer(const std::string& name, std::function<void()> abort):Layer(name),abort(abort) {
}
void ExampleLayer::onEvent(Hydrogen::Event& e) {
	Hydrogen::EventDispatcher eventDispatcher = Hydrogen::EventDispatcher(e);

	eventDispatcher.dispatch<Hydrogen::GameUpdate>(BIND_EVENT_FUNCTION(onGameUpdate));
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

bool ExampleLayer::onGameUpdate(Hydrogen::GameUpdate& e) {
	timeElapsed += e.deltaTime;
	if(timeElapsed.count() >= criteriaTime.count()) {
		abort();
	}
	return true;
}