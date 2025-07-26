#include "OpenGLRenderAPI.h"

namespace OpenGLAPI {
	OpenGLRenderer::OpenGLRenderer() {
		H_CORE_TRACE("Init GLFW");
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		H_CORE_TRACE("Init renderer");
	}
	OpenGLRenderer::~OpenGLRenderer() {
		glDeleteVertexArrays(1, &m_VAO);
		glDeleteBuffers(1, &m_VBO);
	}

	void OpenGLRenderer::setClearColour(RenderAPI::Colour colour) {
		glClearColor((float)colour.getRedFloat(), (float)colour.getGreenFloat(), (float)colour.getBlueFloat(), (float)colour.getAlphaFloat());
	}

	void OpenGLRenderer::Clear() {
		glClear(GL_COLOR_BUFFER_BIT);
	}
	int OpenGLRenderer::bindGeometry(RenderAPI::Mesh& geometry) {
		H_CORE_FATAL("Binding geometry");

		glGenVertexArrays(1, &m_VAO);
		glGenBuffers(1, &m_VBO);

		glBindVertexArray(m_VAO);

		m_pointCount = 0;
		for(auto& vertex:geometry.verticies) {
			verticies.push_back((float)vertex.pos.x);
			verticies.push_back((float)vertex.pos.y);
			verticies.push_back((float)vertex.pos.z);
			m_pointCount++;
		}

		glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
		glBufferData(GL_ARRAY_BUFFER, verticies.size()*sizeof(float), verticies.data(), GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3*sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
		m_VAOQueue.push_back(std::make_tuple(m_VAO,m_pointCount));
		return m_VAOQueue.size()-1;
	}
	void OpenGLRenderer::drawGeometry(int index) {
		m_pointCount = 3;

		glBindVertexArray(std::get<0>(m_VAOQueue[index]));
		checkError("glBindVertexArray");
		glDrawArrays(GL_TRIANGLES, 0, std::get<1>(m_VAOQueue[index]));
		checkError("glDrawArrays");
	}
	void OpenGLRenderer::setCurrentContext(Hydrogen::Ref<RenderAPI::Context> context) {
		glfwMakeContextCurrent(((OpenGLWindow*)context->window.get())->getWindow());
		glViewport(context->x, context->y, context->width, context->height);
		checkError("glViewport");
		m_camera = context->camera;
	}
	void OpenGLRenderer::checkError(std::string location) {
		
		GLenum err;
		while((err = glGetError()) != GL_NO_ERROR) {
			std::string error;
			switch(err) {
				case GL_INVALID_ENUM:      error = "GL_INVALID_ENUM"; break;
				case GL_INVALID_VALUE:     error = "GL_INVALID_VALUE"; break;
				case GL_INVALID_OPERATION: error = "GL_INVALID_OPERATION"; break;
				case GL_STACK_OVERFLOW:    error = "GL_STACK_OVERFLOW"; break;
				case GL_STACK_UNDERFLOW:   error = "GL_STACK_UNDERFLOW"; break;
				case GL_OUT_OF_MEMORY:     error = "GL_OUT_OF_MEMORY"; break;
				case GL_INVALID_FRAMEBUFFER_OPERATION: error = "GL_INVALID_FRAMEBUFFER_OPERATION"; break;
				default:                   error = "Unknown error"; break;
			}
			H_CORE_FATAL("OpenGL error at {}: {} (code: {})", location, error, std::to_string(err));
		}

	}
}