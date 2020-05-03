#pragma once

#include "RenderCommand.h"

namespace lw {
	class Renderer {
	public:
		static void beginScene(); // TODO
		static void endScene();

		static void submit(const std::shared_ptr<VertexArray>& vertexArray);

		inline static RendererAPI::API getAPI() { return RendererAPI::getAPI(); }
	};
}