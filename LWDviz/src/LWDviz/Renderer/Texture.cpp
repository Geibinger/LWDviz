#include "lwpch.h"

#include "Texture.h"

#include "renderer.h"
#include "Platforms/OpenGL/OpenGLTexture.h"

namespace lw {
	ref<Texture2D> Texture2D::create(const std::string& path) {
		switch (Renderer::getAPI()) {
			case RendererAPI::API::None:		LW_CORE_ASSERT(false, "RendererAPI::None is currently not supported"); return nullptr;
			case RendererAPI::API::OpenGL:		return std::make_shared<OpenGLTexture2D>(path);
		}

		LW_CORE_ASSERT(false, "Unknown renderer API");
		return nullptr;
	}
}