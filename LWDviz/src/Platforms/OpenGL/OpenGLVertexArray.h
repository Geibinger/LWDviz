#pragma once

#include "LWDviz/Renderer/VertexArray.h"

namespace lw {
	class OpenGLVertexArray : public VertexArray{
	public:
		OpenGLVertexArray();
		virtual ~OpenGLVertexArray();

		virtual void bind() const override;
		virtual void unbind() const override;

		virtual void addVertexBuffer(const ref<VertexBuffer>& vertexBuffer) override;
		virtual void setIndexBuffer(const ref<IndexBuffer>& indexBuffer) override;

		virtual const std::vector<ref<VertexBuffer>>& getVertexBuffers() const { return m_vertexBuffers; }
		virtual const ref<IndexBuffer>& getIndexBuffer() const { return m_indexBuffer; }

	private:
		uint32_t m_rendererID;
		std::vector<ref<VertexBuffer>> m_vertexBuffers;
		ref<IndexBuffer> m_indexBuffer;
	};
}