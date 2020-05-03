#include "lwpch.h"

#include "buffer.h"
#include "renderer.h"
#include "Platforms/OpenGL/OpenGLBuffer.h"

namespace lw {
	VertexBuffer* VertexBuffer::create(float* vertices, uint32_t size) {
		switch (Renderer::getAPI()) {
		case RendererAPI::API::None:		LW_CORE_ASSERT(false, "RendererAPI::None is currently not supported"); return nullptr;
		case RendererAPI::API::OpenGL:		return new OpenGLVertexBuffer(vertices, size);
		}

		LW_CORE_ASSERT(false, "Unknown renderer API");
		return nullptr;
	}

	IndexBuffer* IndexBuffer::create(uint32_t* indices, uint32_t size) {
		switch (Renderer::getAPI()) {
		case RendererAPI::API::None:		LW_CORE_ASSERT(false, "RendererAPI::None is currently not supported"); return nullptr;
		case RendererAPI::API::OpenGL:		return new OpenGLIndexBuffer(indices, size);
		}

		LW_CORE_ASSERT(false, "Unknown renderer API");
		return nullptr;
	}
}