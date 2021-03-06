#pragma once

#include "RenderCommand.h"

#include "shader.h"
#include "Camera.h"

namespace lw {
	class Renderer {
	public:
		static void beginScene(OrthographicCamera& camera);
		static void endScene();

		static void submit(const ref<Shader>& shader, const ref<VertexArray>& vertexArray, const glm::mat4& transform = glm::mat4(1.0f));

		inline static RendererAPI::API getAPI() { return RendererAPI::getAPI(); }
	private:
		struct SceneData {
			glm::mat4 viewProjectionMatrix;
		};

		static SceneData* m_sceneData;
	};
}