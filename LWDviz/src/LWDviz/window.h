#pragma once

#include "lwpch.h"

#include "LVcore.h"
#include "Events/event.h"

namespace lw {
	
	struct WindowProps {
		std::string title;
		unsigned int width;
		unsigned int height;

		WindowProps(const std::string title = "LWDviz Engine",
					unsigned int width = 720,
					unsigned int height = 480)
			: title(title), width(width), height(height) {}
	};

	// interface for desktop based system

	class LWDVIZ_API Window {
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() {}

		virtual void onUpdate() = 0;

		virtual unsigned int getWidth() const = 0;
		virtual unsigned int getHeight() const = 0;

		virtual void setEventCallback(const EventCallbackFn& callback) = 0;
		virtual void setVSync(bool enabled) = 0;
		virtual bool isVSync() const = 0;

		static Window* create(const WindowProps& props = WindowProps());
	};
}