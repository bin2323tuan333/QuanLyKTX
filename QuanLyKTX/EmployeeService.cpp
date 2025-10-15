#include "EmployeeService.h"

EmployeeService::EmployeeService(EmployeeRepository& employeeRepo)
	:employeeRepo(employeeRepo)
{
}

EmployeeService::~EmployeeService()
{
}


Employee* EmployeeService::getEmployeeById(const int& employeeID)
{
	return this->employeeRepo.Search(employeeID);
}