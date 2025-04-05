#pragma once

#include "core.h"
#include "../Events/Event.h"

namespace Hydrogen {
	class H_API Layer {
		public:
			Layer(const std::string& name = "Layer");
			virtual ~Layer() = default;

			virtual void onEvent(Event& e) = 0;
			virtual void onUpdate(float deltaTime) = 0;
			virtual void onAttach() = 0;
			virtual void onDetach() = 0;

		protected:
			std::string m_debugName;
			Logger::OutputStream m_layerLog;
	};
}