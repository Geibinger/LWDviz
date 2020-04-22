#pragma once

#include "LVcore.h"

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