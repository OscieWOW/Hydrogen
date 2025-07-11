#pragma once

#include "../Core/Core.h"
#include "Shader.h"
#include "Context.h"

namespace RenderAPI {
	enum class H_API Renderers {
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

	class H_API Renderer {
		public:
			static Hydrogen::Ref<Renderer> createRenderer();
		public:
			Renderer();
			virtual ~Renderer();

			virtual void init(Hydrogen::Scope<Shader> shader);
			virtual void setClearColour(Colour colour) = 0;
			void compileShaders();
			virtual void render() = 0;
			virtual void setCurrentContext(Hydrogen::Ref<Context> context) = 0;

		protected:
			Hydrogen::Scope<Shader> m_shader;
	};
}
