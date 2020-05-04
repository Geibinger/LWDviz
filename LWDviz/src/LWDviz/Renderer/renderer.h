#pragma once

#include "RenderCommand.h"

#include "shader.h"
#include "Camera.h"

namespace lw {
	class Renderer {
	public:
		static void beginScene(OrthographicCamera& camera);
		static void endScene();

		static void submit(const std::shared_ptr<Shader>& shader, const std::shared_ptr<VertexArray>& vertexArray);

		inline static RendererAPI::API getAPI() { return RendererAPI::getAPI(); }
	private:
		struct SceneData {
			glm::mat4 viewProjectionMatrix;
		};

		static SceneData* m_sceneData;
	};
}