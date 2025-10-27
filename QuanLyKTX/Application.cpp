#include "Application.h"
#include "ConsolaUI.h"

Application::Application(ServiceManager* service)
	:service(service), isRunning(false), isSignIn(false)
{
	this->homePage = new HomePage(
		service->getAccountService()
	);
	this->employeePage = new EmployeePage(
		service->getAccountService(),
		service->getEmployeeService(),
		service->getStudentService(),
		service->getRoomService(),
		service->getInvoiceService(),
		service->getContractService()
	);
	this->studentPage = new StudentPage();
}

Application::~Application()
{
	delete this->homePage;
	delete this->employeePage;
	delete this->studentPage;
}

void Application::run()
{
	this->isRunning = true;
	while (isRunning)
	{
		this->isSignIn = this->service->getAccountService()->isSignIn();
		if (!isSignIn)
		{
			this->homePage->show();
		}
		else
		{
			int accountID = this->service->getAccountService()->getCurrentID();
			Account* currentAccount = this->service->getAccountService()->SearchByID(accountID);
			if (currentAccount != nullptr)
			{
				if (currentAccount->getRole() == "Manager")
				{
					this->employeePage->show();
				}
				else if (currentAccount->getRole() == "Student")
				{
					//this->studentPage->show();
				}
			}
		}
	}
	ConsolaUI::clearScreen();
}