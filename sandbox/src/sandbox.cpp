#include <LWDviz.h>

#include <imgui/imgui.h>

class ExampleLayer : public lw::Layer {
public:
	ExampleLayer()
		: Layer("Example"), m_camera(-1.6f, 1.6f, -0.9f, 0.9f), m_cameraPosition(0.0f) {

		m_vertexArray.reset(lw::VertexArray::create());

		float vertices[7 * 3] = {
			-0.75f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
			 0.75f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f,
			 0.0f,  0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,
		};

		std::shared_ptr<lw::VertexBuffer> vertexBuffer;
		vertexBuffer.reset(lw::VertexBuffer::create(vertices, sizeof(vertices)));

		lw::BufferLayout layout = {
			{ lw::ShaderDataType::Float3, "a_position" },
			{ lw::ShaderDataType::Float4, "a_color" }
		};

		vertexBuffer->setLayout(layout);
		m_vertexArray->addVertexBuffer(vertexBuffer);

		uint32_t indeces[3] = { 0, 1, 2 };

		std::shared_ptr<lw::IndexBuffer> indexBuffer;
		indexBuffer.reset(lw::IndexBuffer::create(indeces, sizeof(indeces) / sizeof(uint32_t)));
		m_vertexArray->setIndexBuffer(indexBuffer);

		m_squareVA.reset(lw::VertexArray::create());

		float vertices2[3 * 4] = {
			-0.75f, -0.75f, 0.0f,
			 0.75f, -0.75f, 0.0f,
			 0.75f,  0.75f, 0.0f,
			-0.75f,  0.75f, 0.0f
		};

		std::shared_ptr<lw::VertexBuffer> squareVB;
		squareVB.reset(lw::VertexBuffer::create(vertices2, sizeof(vertices2)));

		lw::BufferLayout layout2 = {
			{ lw::ShaderDataType::Float3, "a_position" }
		};

		squareVB->setLayout(layout2);
		m_squareVA->addVertexBuffer(squareVB);

		uint32_t indeces2[6] = { 0, 1, 2, 2, 3, 0 };
		std::shared_ptr<lw::IndexBuffer> squareIB;
		squareIB.reset(lw::IndexBuffer::create(indeces2, sizeof(indeces2) / sizeof(uint32_t)));
		m_squareVA->setIndexBuffer(squareIB);

		std::string vertexSrc = R"(
			#version 330 core
			
			layout(location = 0) in vec3 a_position;
			layout(location = 1) in vec4 a_color;

			uniform mat4 u_viewProjection;

			out vec3 v_position;
			out vec4 v_color;

			void main()
			{
				v_position = a_position;
				v_color = a_color;
				gl_Position = u_viewProjection * vec4(a_position, 1.0);
			}
		)";

		std::string fragmentSrc = R"(
			#version 330 core
			
			layout(location = 0) out vec4 color;
			
			in vec3 v_position;
			in vec4 v_color;

			void main()
			{
				// color = vec4(v_position * 0.5 + 0.5, 1.0);
				color = v_color;
			}
		)";

		m_shader.reset(new lw::Shader(vertexSrc, fragmentSrc));

		std::string vertexSrc2 = R"(
			#version 330 core
			
			layout(location = 0) in vec3 a_position;

			uniform mat4 u_viewProjection;

			out vec3 v_position;

			void main()
			{
				v_position = a_position;
				gl_Position = u_viewProjection * vec4(a_position, 1.0);
			}
		)";

		std::string fragmentSrc2 = R"(
			#version 330 core
			
			layout(location = 0) out vec4 color;
			
			in vec3 v_position;

			void main()
			{
				color = vec4(v_position * 0.5 + 0.5, 1.0);
			}
		)";

		m_squareShader.reset(new lw::Shader(vertexSrc2, fragmentSrc2));

	}

	void onUpdate() override {

		lw::RenderCommand::setClearColor({ 0.1f, 0.1f, 0.1f, 1 });
		lw::RenderCommand::clear();

		m_camera.setPosition(m_cameraPosition);

		lw::Renderer::beginScene(m_camera);

		lw::Renderer::submit(m_squareShader, m_squareVA);
		lw::Renderer::submit(m_shader, m_vertexArray);

		lw::Renderer::endScene();


	}

	virtual void onImGuiRender() override {

	}

	void onEvent(lw::Event& event) override {
		lw::EventDispatcher dispatcher(event);
		dispatcher.dispatch<lw::KeyPressedEvent>(LW_BIND_EVENT_FN(ExampleLayer::onKeyPressedEvent));
	}

	bool onKeyPressedEvent(lw::KeyPressedEvent& event) {
		if (event.getKeyCode() == LW_KEY_LEFT)
			m_cameraPosition.x -= m_cameraSpeed;

		if (event.getKeyCode() == LW_KEY_RIGHT)
			m_cameraPosition.x += m_cameraSpeed;

		if (event.getKeyCode() == LW_KEY_UP)
			m_cameraPosition.y += m_cameraSpeed;

		if (event.getKeyCode() == LW_KEY_DOWN)
			m_cameraPosition.y -= m_cameraSpeed;
		return false;
	}

private:

	std::shared_ptr<lw::Shader> m_shader;
	std::shared_ptr<lw::VertexArray> m_vertexArray;

	std::shared_ptr<lw::Shader> m_squareShader;
	std::shared_ptr<lw::VertexArray> m_squareVA;

	lw::OrthographicCamera m_camera;
	glm::vec3 m_cameraPosition;

	float m_cameraSpeed = 0.01f;
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