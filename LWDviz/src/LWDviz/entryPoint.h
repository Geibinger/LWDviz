#pragma once

#ifdef LW_PLATFORM_WINDOWS

extern lw::Application* lw::createApplication();

int main(int argc, char** argv) {
	lw::log::init();
	LW_CORE_WARN("initialized logger");
	int a = 5;
	float b = 4.2f;
	LW_INFO("hello Var1={0} Var2={1}", a, b);

	auto app = lw::createApplication();
	app->run();
	delete app;
	return 0;
}

#endif