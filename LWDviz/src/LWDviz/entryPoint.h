#pragma once

#ifdef LV_PLATTFORM_WINDOWS

extern lv::Application* lv::createApplication();

int main(int argc, char** argv) {
	lv::log::init();
	LV_CORE_WARN("initialized logger");
	int a = 5;
	float b = 4.2f;
	LV_INFO("hello Var1={0} Var2={1}", a, b);

	auto app = lv::createApplication();
	app->run();
	delete app;
	return 0;
}

#endif