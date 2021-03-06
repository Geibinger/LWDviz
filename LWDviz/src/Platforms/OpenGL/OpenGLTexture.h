#pragma once

#include "LWDviz/Renderer/Texture.h"

namespace lw {
	class OpenGLTexture2D : public Texture2D {
	public:
		OpenGLTexture2D(const std::string& path);
		~OpenGLTexture2D();

		virtual uint32_t getWidth() const override { return m_width; }
		virtual uint32_t getHeight() const override { return m_height; }

		virtual void bind(uint32_t slot) const override;

	private:
		std::string m_path;
		uint32_t m_width, m_height;
		uint32_t m_rendererID;
	};
}