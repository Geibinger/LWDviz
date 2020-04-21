#pragma once

#ifdef LV_PLATTFORM_WINDOWS

extern lv::Application* lv::createApplication();

int main(int argc, char** argv) {
	auto app = lv::createApplication();
	app->run();
	delete app;
	return 0;
}

#endif