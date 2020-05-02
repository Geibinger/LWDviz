#pragma once

#include <string>

namespace lw {
	class Shader {
	public:
		Shader(const std::string& vertexSrc, const std::string& fragmentSrc);
		~Shader();

		void bind() const;
		void unBind() const;
	private:
		uint32_t m_rendererID;
	};
}