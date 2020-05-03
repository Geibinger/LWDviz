#include "lwpch.h"

#include "RenderCommand.h"

#include "Platforms/OpenGL/OpenGLRendererAPI.h"

namespace lw {
	RendererAPI* RenderCommand::s_rendererAPI = new OpenGLRendererAPI;
}