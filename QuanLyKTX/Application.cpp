#include "Application.h"
#include "ConsolaUI.h"

Application::Application(ServiceManager* service)
	:service(service), isRunning(false), isSignIn(false)
{
	this->currentAccount = nullptr;
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
			this->currentAccount = nullptr;
			this->homePage->show();
		}
		else
		{
			if (this->currentAccount == nullptr)
			{
				int userId = this->service->getAccountService()->getCurrentId();
				this->currentAccount = this->service->getAccountService()->SearchByUserId(userId);
			}
			if (currentAccount != nullptr)
			{
				if (currentAccount->getUser()->getRole() == "Manager")
				{
					this->employeePage->show();
				}
				else if (currentAccount->getUser()->getRole() == "Student")
				{
					//this->studentPage->show();
				}
			}
		}
	}
	ConsolaUI::clearScreen();
}