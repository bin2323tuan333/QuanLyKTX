#include "EmployeeService.h"

EmployeeService::EmployeeService(EmployeeData& employeeData)
	:employeeData(employeeData)
{
}

EmployeeService::~EmployeeService()
{
}

int EmployeeService::Add(const Employee& temp)
{
	this->employeeData.Add(temp);
	return 1;
}
Employee* EmployeeService::SearchByID(const int& id)
{
	return this->employeeData.GetByEmployeeId(id);
}
LinkedList<Employee*>* EmployeeService::GetAll()
{
	return this->employeeData.getList();
}
int EmployeeService::Update(const Employee& temp)
{
	this->employeeData.Update(temp);
	return 1;
}
int EmployeeService::Delete(const Employee& temp)
{
	this->employeeData.Delete(temp);
	return 1;
}