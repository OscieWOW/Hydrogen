#pragma once

#include "Core.h"
#include "../Logger/Logger.h"
#include "Log.h"

extern Hydrogen::Application* Hydrogen::createApp();

int main() {
	Hydrogen::Log::logInit();
	H_CORE_TRACE("entry point");

	Hydrogen::Application* app = Hydrogen::createApp();
	app->run();
	delete app;
	return 0;
}
