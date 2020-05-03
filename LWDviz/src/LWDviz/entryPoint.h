#pragma once

#ifdef LW_PLATFORM_WINDOWS

extern lw::Application* lw::createApplication();

int main(int argc, char** argv) {
	lw::log::init();
	LW_CORE_INFO("Initialized logger");

	auto app = lw::createApplication();
	app->run();
	delete app;
	return 0;
}

#endif