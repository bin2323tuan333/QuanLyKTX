#include "PageManager.h"


PageManager::PageManager(ServiceManager* service)
	:service(service)
{
	this->homePage = new HomePage(
		service->getAccountService()
	);
	this->employeePage = new EmployeePage(
		service->getAccountService(),
		service->getEmployeeService(),
		service->getStudentService()
	);
}
PageManager::~PageManager()
{
	delete this->homePage;
	delete this->employeePage;
}


HomePage& PageManager::getHomePage()
{
	return *(this->homePage);
}

//StudentPage PageManager::getStudentPage()
//{
//	return StudentPage();
//}

EmployeePage& PageManager::getEmployeePage()
{
	return *(this->employeePage);
}
