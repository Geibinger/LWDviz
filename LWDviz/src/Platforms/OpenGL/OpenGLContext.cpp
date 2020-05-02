#include "lwpch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace lw {

	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_windowHandle(windowHandle) {
		LW_CORE_ASSERT(windowHandle, "Window handle is null!");
	}

	void OpenGLContext::init() {
		glfwMakeContextCurrent(m_windowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		LW_CORE_ASSERT(status, "Failed to initialize Glad!");

		LW_CORE_INFO("OpenGL Info:");
		LW_CORE_INFO("\tOpenGL Vendor:\t\t{0}", glGetString(GL_VENDOR));
		LW_CORE_INFO("\tOpenGL Renderer:\t{0}", glGetString(GL_RENDERER));
		LW_CORE_INFO("\tOpenGL Version:\t\t{0}", glGetString(GL_VERSION));
	}

	void OpenGLContext::swapBuffers() {
		glfwSwapBuffers(m_windowHandle);
	}
}