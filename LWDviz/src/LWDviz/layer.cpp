#include "lwpch.h"
#include "layer.h"

namespace lw {
	Layer::Layer(const std::string& debugName)
		: m_debugName(debugName) {}

	Layer::~Layer()	{}
}