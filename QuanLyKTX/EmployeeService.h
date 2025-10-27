#pragma once
#include "EmployeeRepository.h"

class EmployeeService {
private:
    EmployeeRepository& employeeRepo;

public:
    EmployeeService(EmployeeRepository&);
    ~EmployeeService();

    int Add(const Employee&);
    Employee* SearchByID(const int&);
    LinkedList<Employee> GetAll();
    int Update(const Employee&);
    int Delete(const Employee&);
};