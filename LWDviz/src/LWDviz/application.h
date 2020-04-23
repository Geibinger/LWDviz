#pragma once

#include "LVcore.h"
#include "Events/event.h"

namespace lv {
	class LWDVIZ_API Application
	{
	public:
		Application();
		virtual ~Application();

		void run();
	};

	// to be defined in client
	Application* createApplication();
}