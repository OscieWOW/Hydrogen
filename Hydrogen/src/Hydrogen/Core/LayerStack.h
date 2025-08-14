#pragma once

#include "core.h"
#include "Layer.h"

namespace Hydrogen {
	class  LayerStack {
		public:
			LayerStack();
			LayerStack(const LayerStack&);

			void onEvent(Event&);
			void onUpdate(std::chrono::nanoseconds dTime);

			void pushLayer(Scope<Layer> layer);
			void popLayer(Scope<Layer> layer);

		private:
			std::vector<Ref<Layer>> m_layerStack;
	};
}