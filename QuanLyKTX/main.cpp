#include "Application.h"

int main() 
{
	ServiceManager* service = new ServiceManager();
	Application* app = new Application(service);
	app->run();
	delete app;
	delete service;
	return 0;
}