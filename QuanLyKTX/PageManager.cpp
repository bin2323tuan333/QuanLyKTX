#include "PageManager.h"


PageManager::PageManager(ServiceManager* service)
	:service(service)
{
	this->homePage = new HomePage(
		this->service->getAccountService()
	);
	this->employeePage = new EmployeePage(
		this->service->getAccountService(),
		this->service->getEmployeeService(),
		this->service->getStudentService(),
		this->service->getRoomService(),
		this->service->getInvoiceService(),
		this->service->getContractService()
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
