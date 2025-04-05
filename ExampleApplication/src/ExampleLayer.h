#pragma once

#include <Hydrogen.h>

class ExampleLayer:public Hydrogen::Layer {
	public:
		ExampleLayer(const std::string& name = "ExampleLayer");
		void onEvent(Hydrogen::Event& e) override;
		void onUpdate(float deltaTime) override;
		void onAttach() override;
		void onDetach() override;

		bool onGameUpdate(Hydrogen::GameUpdate& e);
};