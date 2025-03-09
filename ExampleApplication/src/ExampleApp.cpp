#include <Hydrogen.h>

int main() {
	std::string name = "sandbox";
	Hydrogen::appSpecs appSpec = Hydrogen::appSpecs(&name);

	Hydrogen::Application* app = new Hydrogen::Application(appSpec);
	//std::cout << "hi" << std::endl;
	std::cout << "app called " << *(app->specs.name) << std::endl;
	delete app;
	return 0;
}