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
			
		virtual void onAttach() override;
		virtual void onDetach() override;
		virtual void onImGuiRender() override;

		void begin();
		void end();

	private:
		float m_time = 0.f;
	};
}