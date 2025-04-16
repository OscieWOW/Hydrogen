#pragma once

#include "../Core/Core.h"

namespace RenderAPI {
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
			virtual void setClearColour(Colour colour) = 0;
	};
}
