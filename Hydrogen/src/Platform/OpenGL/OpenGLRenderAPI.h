#pragma once

#include "../../Hydrogen/Renderer/RenderAPI.h"
#include "../../Hydrogen/Core/Core.h"
#include "../../Hydrogen/Core/Log.h"
#include "OpenGLShader.h"
#include "OpenGLAPI.h"
#include "../../Hydrogen/Renderer/Mesh.h"

#include <GLAD/glad.h>
#include <GLFW/glfw3.h>

namespace OpenGLAPI {
	class  OpenGLRenderer: public RenderAPI::Renderer {
		public:
			OpenGLRenderer();
			~OpenGLRenderer();

			void setClearColour(RenderAPI::Colour colour) override;
			void Clear() override;
			int bindGeometry(RenderAPI::Mesh& geometry) override;
			void drawGeometry(int index) override;
			void setCurrentContext(Hydrogen::Ref<RenderAPI::Context> context) override;
			void checkError(std::string location);

		private:
			std::vector<float> verticies;
			unsigned int m_VAO, m_VBO, m_EBO;
			unsigned int m_pointCount = 3;
			std::vector<std::tuple<GLuint, int>> m_VAOQueue;
	};
}