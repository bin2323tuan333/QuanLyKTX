#pragma once
#include "ServiceManager.h"
#include "HomePage.h"
#include "StudentPage.h"
#include "EmployeePage.h"

class PageManager
{
public:
	ServiceManager* service;

	PageManager(ServiceManager*);
	~PageManager();

	HomePage getHomePage();
	StudentPage getStudentPage();
	EmployeePage getEmployeePage();
};