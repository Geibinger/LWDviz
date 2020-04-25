#pragma once

#include "LWDviz/layer.h"

#include "LWDviz/Events/applicationEvent.h"
#include "LWDviz/Events/keyEvent.h"
#include "LWDviz/Events/mouseEvent.h"

namespace lw {
	class LWDVIZ_API ImGuiLayer : public Layer {
	public:
		ImGuiLayer();
		~ImGuiLayer();
			
		void onAttach();
		void onDetach();
		void onUpdate();
		void onEvent(Event& event);
	private:
		bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& e);
		bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e);
		bool OnMouseMovedEvent(MouseMovedEvent& e);
		bool OnMouseScrolledEvent(MouseScrolledEvent& e);
		bool OnKeyPressedEvent(KeyPressedEvent& e);
		bool OnKeyReleasedEvent(KeyReleasedEvent& e);
		bool OnKeyTypedEvent(KeyTypedEvent& e);
		bool OnWindowResizedEvent(WindowResizeEvent& e);

		float m_time = 0.f;
	};
}