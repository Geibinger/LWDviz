#pragma once

#include "LWcore.h"
#include "Events/event.h"
#include "Core/Timestep.h"

namespace lw {
	class Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual	~Layer();

		virtual void onAttach() {}
		virtual void onDetach() {}
		virtual void onUpdate(Timestep ts) {}
		virtual void onImGuiRender() {}
		virtual void onEvent(Event& event) {}

		inline const std::string& getName() const { return m_debugName; }
	protected:
		std::string m_debugName;
	};
}

