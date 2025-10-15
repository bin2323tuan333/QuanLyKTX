#pragma once
#include "EmployeeRepository.h"

class EmployeeService {
private:
    EmployeeRepository& employeeRepo;

public:
    EmployeeService(EmployeeRepository&);
    ~EmployeeService();

    bool addEmployee(const Employee&);
    bool updateEmployee(const Employee&);
    bool deleteEmployee(int);
    bool deactivateEmployee(int);

    Employee* getEmployeeById(const int&);
};