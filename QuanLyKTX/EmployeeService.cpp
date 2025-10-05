#include "EmployeeService.h"

EmployeeService::EmployeeService(EmployeeRepository& employeeRepo)
	:employeeRepo(employeeRepo)
{
}

EmployeeService::~EmployeeService()
{
}
