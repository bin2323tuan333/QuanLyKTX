#include "Application.h"
#include "ConsolaUI.h"

Application::Application(PageManager* page)
	:page(page), isRunning(false), isSignIn(false)
{
}

Application::~Application()
{
}

void Application::run()
{
	/*this->isRunning = true;
	while (isRunning)
	{
		this->isSignIn = this->page->service->getAccountService()->isSignIn();
		if (!isSignIn)
		{
			(this->page->getHomePage()).show();
		}
		else
		{
			if ((this->page->service->getAccountService())->getRole() == "staff")
			{

			}
			else if ((this->page->service->getAccountService())->getRole() == "student")
			{

			}
		}
	}*/
	(this->page->getEmployeePage()).show();
}