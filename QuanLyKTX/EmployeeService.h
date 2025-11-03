#pragma once
#include "EmployeeData.h"

class EmployeeService {
private:
    EmployeeData& employeeData;

public:
    EmployeeService(EmployeeData&);
    ~EmployeeService();

    //int Add(const Employee&);
    //Employee* SearchByID(const int&);
    //LinkedList<Employee> GetAll();
    //int Update(const Employee&);
    //int Delete(const Employee&);
};