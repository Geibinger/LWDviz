#include <LWDviz.h>

#include <imgui/imgui.h>

class ExampleLayer : public lw::Layer {
public:
	ExampleLayer()
		: Layer("Example") {}

	void onUpdate() override {
		if (lw::Input::isKeyPressed(LW_KEY_TAB)) {
			LW_INFO("Key {0} is pressed!", LW_KEY_TAB);
		}
	}

	virtual void onImGuiRender() override {
		ImGui::Begin("Test");
		ImGui::Text("Text");
		ImGui::End();
	}

	void onEvent(lw::Event& event) override {
		switch (event.getEventType()) {
		case lw::EventType::KeyPressed:
			lw::KeyPressedEvent& e = (lw::KeyPressedEvent&)event;
			LW_TRACE("{0}", (char)e.getKeyCode());
			break;
		}
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