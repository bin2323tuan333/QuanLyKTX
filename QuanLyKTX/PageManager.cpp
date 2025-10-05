#include "PageManager.h"


PageManager::PageManager(ServiceManager* service)
	:service(service)
{
}
PageManager::~PageManager()
{
}


HomePage PageManager::getHomePage()
{
	return HomePage();
}

//StudentPage PageManager::getStudentPage()
//{
//	return StudentPage();
//}
//
//EmployeePage PageManager::getEmployeePage()
//{
//	return EmployeePage();
//}
