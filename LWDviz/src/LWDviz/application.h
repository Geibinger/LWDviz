#pragma once

#include "LVcore.h"

#include "window.h"
#include "layerStack.h"
#include "Events/event.h"
#include "Events/applicationEvent.h"

namespace lw {
	
	class LWDVIZ_API Application {
	public:
		Application();
		virtual ~Application();

		void run();

		void onEvent(Event& e);

		void pushLayer(Layer* layer);
		void pushOverlay(Layer* overlay);
	private:
		bool onWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_window;
		bool m_running = true;
		LayerStack m_layerStack;
	};

	// to be defined in client
	Application* createApplication();
}