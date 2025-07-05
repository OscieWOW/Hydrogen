#pragma once

#include "Core.h"
#include "../Logger/Logger.h"
#include "Log.h"

extern Hydrogen::Application* Hydrogen::createApp();

int main() {
	Hydrogen::Log::logInit();

	H_CORE_TRACE("Initialising the app");
	Hydrogen::Application* app = Hydrogen::createApp();

	H_CORE_TRACE("Initialising the window");
	if(!app->createWindow()) {
		H_CORE_WARN("Failed to init the window");
	}
	
	H_CORE_TRACE("Initialising the render engine");
	if(!app->initRenderEngine()) {
		H_CORE_WARN("Failed to init the render engine");
	}


	H_CORE_TRACE("running the app");
	app->run();

	H_CORE_TRACE("deleting the app");
	delete app;

	return 0;
}
