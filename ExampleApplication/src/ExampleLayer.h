#pragma once

#include <Hydrogen.h>

class ExampleLayer:public Hydrogen::Layer {
	public:
	ExampleLayer(const std::string& name = "ExampleLayer", std::function<void()> abort = []() {});
		void onEvent(Hydrogen::Event& e) override;
		void onUpdate(std::chrono::nanoseconds deltaTime) override;
		void onAttach() override;
		void onDetach() override;

		bool onGameUpdate(Hydrogen::GameUpdate& e);

	public:
		std::function<void()> abort;
		std::chrono::nanoseconds timeElapsed = std::chrono::nanoseconds(std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::seconds(0)));
		std::chrono::nanoseconds criteriaTime = std::chrono::nanoseconds(std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::seconds(30)));
};