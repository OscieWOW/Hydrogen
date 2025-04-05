#pragma once

#include "core.h"
#include "Layer.h"

namespace Hydrogen {
	class H_API LayerStack {
		public:
			LayerStack();
			LayerStack(const LayerStack&);

			LayerStack& operator=(const LayerStack& other);

			void onEvent(Event&);

			void pushLayer(Scope<Layer> layer);
			void popLayer(Scope<Layer> layer);

		private:
			std::vector<Ref<Layer>> m_layerStack;
	};
}