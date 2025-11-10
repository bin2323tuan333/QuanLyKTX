#pragma once
#include "AuthService.h"
#include "BillingService.h"
#include "ContractService.h"
#include "RoomService.h"
#include "UserService.h"
#include "HomeView.h"
#include "StudentView.h"
#include "EmployeeView.h"

class Application
{
private:
	AuthService* authService;
	BillingService* billingService;
	ContractService* contractService;
	RoomService* roomService;
	UserService* userService;

	Account* currentUser;
	BaseView* currentView;
	bool isRunning;
public:
	Application();
	~Application();
	void run();
};


