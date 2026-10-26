#pragma once

#include "Engine.h"
#include "../Renderer/RenderAPI.h"
#include "../ResourceManager/ResourceManager.h"
#include "../Renderer/Mesh.h"
#include "../Renderer/Shader.h"

namespace Hydrogen::RenderAPI {
	class  RenderEngine: public Hydrogen::Engine {
		public:
			RenderEngine();
			~RenderEngine();

			void onUpdate(std::chrono::nanoseconds deltaT) override;
			void onRender(Hydrogen::Ref<Context> context, const ResourceManager::ResourceManager& resManager);
			void addDrawMesh(Hydrogen::Ref<RenderAPI::Mesh> mesh);
			void init(Scope<RenderAPI::Shader> shader);
			void setClearColour(RenderAPI::Colour colour);

			Hydrogen::Ref<Window> createWindow(WindowData data, std::function<void(Hydrogen::Event&)> onEvent);

		protected:
			Hydrogen::Scope<RenderAPI::Shader> m_shader;
			Hydrogen::Ref<RenderAPI::Renderer> m_renderer;

			std::vector<int> m_renderQueueIndex;
	};
}
