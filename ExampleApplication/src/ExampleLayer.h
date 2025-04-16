#pragma once

#include <Hydrogen.h>

class ExampleLayer:public Hydrogen::Layer {
	public:
	ExampleLayer(Hydrogen::Handle<RenderAPI::Renderer> renderer,const std::string& name = "ExampleLayer");
		void onEvent(Hydrogen::Event& e) override;
		void onUpdate(std::chrono::nanoseconds deltaTime) override;
		void onAttach() override;
		void onDetach() override;

		bool onKeyPress(Hydrogen::KeyPressed& e);

	private:
		int colourState1 = 0;
		int colourState2 = 0;
		Hydrogen::Handle<RenderAPI::Renderer> renderer;
};