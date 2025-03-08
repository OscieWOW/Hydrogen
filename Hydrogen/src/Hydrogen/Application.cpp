#include "Application.h"

namespace Hydrogen {
	Application::Application(const std::string& name):m_name(std::make_unique<std::string>(name)) {
		
	}
	Application::~Application() {
		
	}

	std::string Application::getName() {
		return *m_name;
	}
}