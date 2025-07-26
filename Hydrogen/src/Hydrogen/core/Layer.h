#pragma once

#include "core.h"
#include "../Events/Event.h"

namespace Hydrogen {
	struct LayerData {
		const std::string name;
		std::function<void(Event&)> onEvent;
		LayerData(std::function<void(Event&)> onEvent, const std::string name = "Layer"):name(name), onEvent(onEvent) {}
	};

	class Layer {
		public:
			Layer(const LayerData layerData);
			virtual ~Layer() = default;

			virtual void onEvent(Event& e) = 0;
			virtual void onUpdate(std::chrono::nanoseconds deltaTime) = 0;
			virtual void onAttach() = 0;
			virtual void onDetach() = 0;

		protected:
			LayerData m_layerData;
			Logger::OutputStream m_layerLog;
	};
}