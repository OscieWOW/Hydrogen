#pragma once

#include "Engine.h"
#include "../Renderer/RenderAPI.h"
#include "../Renderer/Mesh.h"

namespace RenderAPI {
	class  RenderEngine: public Hydrogen::Engine {
		public:
			RenderEngine();
			~RenderEngine();

			void onUpdate(std::chrono::nanoseconds deltaT) override;
			void onRender(Hydrogen::Ref<Context> context);
			void addDrawMesh(Hydrogen::Scope<RenderAPI::Mesh> mesh);
			void init(Hydrogen::Scope<Shader> shader);
			void setClearColour(Colour colour);

			Hydrogen::Ref<Window> createWindow(WindowData data, std::function<void(Hydrogen::Event&)> onEvent);

		protected:
			Hydrogen::Scope<RenderAPI::Shader> m_shader;
			Hydrogen::Ref<RenderAPI::Renderer> m_renderer;

			std::vector<int> m_renderQueueIndex;
	};
}
