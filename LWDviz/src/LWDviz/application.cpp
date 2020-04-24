#include "application.h"

#include "Events/applicationEvent.h"
#include "log.h"
#include "Events/event.h"

namespace lv {
	Application::Application()
	{
	}


	Application::~Application()
	{
	}

	void Application::run() {
		WindowResizeEvent e(1280, 720);
		LV_TRACE(e);

		while (true);
	}
}