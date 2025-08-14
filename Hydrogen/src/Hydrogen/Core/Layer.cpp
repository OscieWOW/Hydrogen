#include "Layer.h"

namespace Hydrogen {
	Layer::Layer(const LayerData layerData): m_layerData(layerData),m_layerLog(Log::newLogger("<LAYER>"+layerData.name)) {}
}