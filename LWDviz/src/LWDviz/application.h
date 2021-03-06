#pragma once

#include "LWcore.h"

#include "window.h"
#include "layerStack.h"
#include "Events/event.h"
#include "Events/applicationEvent.h"
#include "ImGui/ImGuiLayer.h"
#include "LWDviz/Core/Timestep.h"

namespace lw {
	
	class Application {
	public:
		Application();
		virtual ~Application();

		void run();

		void onEvent(Event& e);

		void pushLayer(Layer* layer);
		void pushOverlay(Layer* overlay);

		inline Window& getWindow() { return *m_window; }
		inline static Application& get() { return *s_instance; }
	private:
		bool onWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_window;
		ImGuiLayer* m_imGuiLayer;
		bool m_running = true;
		LayerStack m_layerStack;
		float m_lastFrameTime = 0.0f;

		static Application* s_instance;
	};

	// to be defined in client
	Application* createApplication();
}