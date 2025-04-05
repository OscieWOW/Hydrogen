#include "LayerStack.h"
#include "../Events/Event.h"

namespace Hydrogen {
	LayerStack::LayerStack() {}

	LayerStack::LayerStack(const LayerStack&) {
		H_CORE_FATAL("making a new LayerStack");
	}

	void LayerStack::onEvent(Event& e) {
		for(auto layer:m_layerStack) {
			layer->onEvent(e);
		}
	}

	void LayerStack::pushLayer(Scope<Layer> layer) {
		layer->onAttach();
		m_layerStack.push_back(std::move(layer));
	}
	void LayerStack::popLayer(Scope<Layer> layer) {
		
	}

	LayerStack& LayerStack::operator=(const LayerStack& other) {
		H_CORE_FATAL("LayerStack has been coppied");
		return *this;
	}
}