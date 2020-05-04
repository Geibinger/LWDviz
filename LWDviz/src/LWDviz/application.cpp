#include "lwpch.h"

#include "application.h"
#include "Renderer/renderer.h"

#include <GLFW/glfw3.h>

namespace lw {

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application* Application::s_instance = nullptr;

	Application::Application()
		{
		LW_ASSERT(!s_instance, "Application already exists!");
		s_instance = this;

		m_window = std::unique_ptr<Window>(Window::create());
		m_window->setEventCallback(BIND_EVENT_FN(onEvent));
		m_window->setVSync(true);

		m_imGuiLayer = new ImGuiLayer();
		pushOverlay(m_imGuiLayer);
	}

	
	Application::~Application() {}
	
	void Application::run() {
		while (m_running) {
			float time = (float)glfwGetTime(); // Platform::getTime()
			Timestep timestep = time - m_lastFrameTime;
			m_lastFrameTime = time;

			for (Layer* layer : m_layerStack) {
				layer->onUpdate(timestep);
			}

			m_imGuiLayer->begin();
			for (Layer* layer : m_layerStack) {
				layer->onImGuiRender();
			}
			m_imGuiLayer->end();

			m_window->onUpdate();
		}
	}

	void Application::onEvent(Event& event) {
		EventDispatcher dispatcher(event);
		dispatcher.dispatch<WindowCloseEvent>(BIND_EVENT_FN(onWindowClose));

		for (auto it = m_layerStack.end(); it != m_layerStack.begin(); ) {
			(*--it)->onEvent(event);
			if (event.handled) {
				break;
			}
		}
	}

	bool Application::onWindowClose(WindowCloseEvent& event) {
		m_running = false;
		return true;
	}

	void Application::pushLayer(Layer* layer) {
		m_layerStack.pushLayer(layer);
		layer->onAttach();
	}

	void Application::pushOverlay(Layer* overlay) {
		m_layerStack.pushOverlay(overlay);
		overlay->onAttach();
	}
}