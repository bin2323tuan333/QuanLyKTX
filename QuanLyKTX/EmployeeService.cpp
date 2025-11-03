#include "EmployeeService.h"

EmployeeService::EmployeeService(EmployeeData& employeeData)
	:employeeData(employeeData)
{
}

EmployeeService::~EmployeeService()
{
}

//int EmployeeService::Add(const Employee& temp)
//{
//	this->employeeRepo.Add(temp);
//	return 1;
//}
//Employee* EmployeeService::SearchByID(const int& id)
//{
//	return this->employeeRepo.GetById(id);
//}
//LinkedList<Employee> EmployeeService::GetAll()
//{
//	return this->employeeRepo.GetAll();
//}
//int EmployeeService::Update(const Employee& temp)
//{
//	this->employeeRepo.Update(temp);
//	return 1;
//}
//int EmployeeService::Delete(const Employee& temp)
//{
//	this->employeeRepo.Delete(temp);
//	return 1;
//}