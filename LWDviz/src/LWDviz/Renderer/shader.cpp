#include "lwpch.h"

#include "shader.h"
#include "renderer.h"

#include "Platforms/OpenGL/OpenGLShader.h"

namespace lw {
	Shader* Shader::create(const std::string& vertexSrc, const std::string& fragmentSrc) {
		switch (Renderer::getAPI()) {
			case RendererAPI::API::None:		LW_CORE_ASSERT(false, "RendererAPI::None is currently not supported"); return nullptr;
			case RendererAPI::API::OpenGL:		return new OpenGLShader(vertexSrc, fragmentSrc);
		}

		LW_CORE_ASSERT(false, "Unknown renderer API");
		return nullptr;
	}
}