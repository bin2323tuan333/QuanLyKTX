#include "Application.h"



int main() 
{
	ServiceManager* service = new ServiceManager();
	service->initialize();
	PageManager* page = new PageManager(service);

	Application app(page);
	app.run();

	delete page;
	service->shutdown();
	delete service;
	return 0;
}