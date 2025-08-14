#pragma once

#include "../Core/Core.h"
#include "Shader.h"
#include "Window.h"
#include "Mesh.h"
#include <glm/gtc/matrix_transform.hpp>

namespace RenderAPI {
	enum class  Renderers {
		OpenGL
	};
	static Renderers renderAPI = Renderers::OpenGL;

	struct Colour {
		Colour(int red, int green, int blue, int alpha = 255):red(red), green(green), blue(blue), alpha(alpha) {}
		
		float getRedFloat() { return (float)(red/255.0f); }
		float getGreenFloat() { return (float)(green/255.0f); }
		float getBlueFloat() { return (float)(blue/255.0f); }
		float getAlphaFloat() { return (float)(alpha/255.0f); }

		int red, green, blue, alpha;
	};

	class  Renderer {
		public:
			static Hydrogen::Ref<Renderer> createRenderer();
		public:
			Renderer();
			virtual ~Renderer();

			virtual void init();
			virtual void setClearColour(Colour colour) = 0;
			virtual void Clear() = 0;
			virtual int bindGeometry(RenderAPI::Mesh& geometry) = 0;
			virtual void drawGeometry(int index) = 0;
			virtual void setCurrentContext(Hydrogen::Ref<Context> context) = 0;

		protected:
			Camera m_camera = Camera(glm::vec3(0.0f));
	};
}
