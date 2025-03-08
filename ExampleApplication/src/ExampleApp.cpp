#include <Hydrogen.h>

int main() {
	Hydrogen::Application* app = new Hydrogen::Application("Sandbox");
	std::cout << "app called " << app->getName() << std::endl;
	std::cout << "other stuff" << std::endl;
	delete app;
	return 0;
}