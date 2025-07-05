#pragma once

#include "../../Hydrogen/Renderer/RenderAPI.h"
#include "../../Hydrogen/Core/Core.h"
#include "../../Hydrogen/Core/Log.h"
#include "OpenGLShader.h"

#include <GLAD/glad.h>
#include <GLFW/glfw3.h>

namespace OpenGLAPI {
	class H_API OpenGLRenderer: public RenderAPI::Renderer {
		public:
			OpenGLRenderer();
			~OpenGLRenderer();

			void setClearColour(RenderAPI::Colour colour) override;
			void render() override;
			void setCurrentContext(Hydrogen::Ref<RenderAPI::Context> context) override;
			
	};
}