#include <LWDviz.h>

class ExampleLayer : public lw::Layer {
public:
	ExampleLayer()
		: Layer("Example") {}

	void onUpdate() override {
		LW_INFO("ExampleLayer::Update");
	}

	void onEvent(lw::Event& event) override {
		LW_TRACE("{0}", event);
	}
};

class Sandbox : public lw::Application {
public:
	Sandbox(){
		pushLayer(new ExampleLayer());
	}

	~Sandbox(){

	}
};

lw::Application* lw::createApplication() {
	return new Sandbox();
}