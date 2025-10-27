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

public:
    Application(ServiceManager*);
    ~Application();
    void run();
};