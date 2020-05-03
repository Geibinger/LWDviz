#include "lwpch.h"

#include "VertexArray.h"

#include "renderer.h"
#include "Platforms/OpenGL/OpenGLVertexArray.h"

namespace lw {
	VertexArray* VertexArray::create() {
		switch (Renderer::getAPI()) {
			case RendererAPI::API::None:		LW_CORE_ASSERT(false, "RendererAPI::None is currently not supported"); return nullptr;
			case RendererAPI::API::OpenGL:		return new OpenGLVertexArray();
		}

		LW_CORE_ASSERT(false, "Unknown renderer API");
		return nullptr;
	}
}