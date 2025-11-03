#pragma once
#include "ServiceManager.h"
#include "HomePage.h"
#include "EmployeePage.h"
#include "StudentPage.h"

class Application
{
private:
    ServiceManager* service;

    HomePage* homePage;
    EmployeePage* employeePage;
    StudentPage* studentPage;

    bool isRunning;
    bool isSignIn;
    Account* currentAccount;
public:
    Application(ServiceManager*);
    ~Application();
    void run();
};