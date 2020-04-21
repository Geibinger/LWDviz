#pragma once

#include "core.h"

namespace lv {
	class LVDVIZ_API Application
	{
	public:
		Application();
		virtual ~Application();

		void run();
	};

	// to be defined in client
	Application* createApplication();
}