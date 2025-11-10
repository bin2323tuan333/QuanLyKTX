#include "Application.h"
#include "ConsolaUI.h"

Application::Application()
	:isRunning(false)
{
	this->authService = new AuthService();
	this->billingService = new BillingService();
	this->contractService = new ContractService();
	this->roomService = new RoomService();
	this->userService = new UserService();
	this->currentUser = nullptr;
	this->currentView = nullptr;
}

Application::~Application()
{
	delete this->authService;
	delete this->billingService;
	delete this->contractService;
	delete this->roomService;
	delete this->userService;
}

void Application::run()
{
	DB::Instance();
	this->isRunning = true;
	this->currentView = new HomeView(currentUser, authService);
	while (isRunning)
	{
		if (this->currentUser == nullptr && this->currentView == nullptr)
		{
			this->currentView = new HomeView(currentUser, authService);
		}
		if (this->currentUser != nullptr && this->currentView == nullptr)
		{
			if (currentUser->getUser()->getRole() == "Student")
			{
				this->currentView = new StudentView();
			}
			else if (currentUser->getUser()->getRole() == "Manager")
			{
				this->currentView = new EmployeeView(
					this->currentUser, 
					this->authService, 
					this->userService, 
					this->roomService,
					this->billingService,
					this->contractService
				);
			}
		}

		if (currentView != nullptr)
		{
			ConsolaUI::clearScreen();
			int result = this->currentView->show();
			if (result == 0) this->isRunning = false;
			if (result == 2) 
			{
				delete this->currentView;
				this->currentView = nullptr;
			}
		
		}
	}
	ConsolaUI::clearScreen();
}