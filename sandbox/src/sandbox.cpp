#include <LWDviz.h>

class Sandbox : public lv::Application {
public:
	Sandbox(){

	}

	~Sandbox(){

	}
};

lv::Application* lv::createApplication() {
	return new Sandbox();
}