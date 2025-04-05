#include "Layer.h"

namespace Hydrogen {
	Layer::Layer(const std::string& name): m_debugName(name),m_layerLog(Log::newLogger("<LAYER>"+name)) {
	}
	
}