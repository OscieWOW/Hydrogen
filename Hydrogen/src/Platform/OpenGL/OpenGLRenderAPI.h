#pragma once

#include "../../Hydrogen/Renderer/RenderAPI.h"
#include "../../Hydrogen/Core/Core.h"
#include "../../Hydrogen/Core/Log.h"

#include <GLAD/glad.h>

namespace OpenGLAPI {
	class H_API OpenGLRenderer: public RenderAPI::Renderer {
		public:
			OpenGLRenderer();
			void setClearColour(RenderAPI::Colour colour) override;
	};
}