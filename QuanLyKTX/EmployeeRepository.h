#pragma once
#include "Employee.h"
#include "LinkedList.h"


class EmployeeRepository
{
private:
    string fileName;
    LinkedList<Employee> list;

public:
    EmployeeRepository(const string&);
    ~EmployeeRepository();

    void loadData();
    void saveData();

    void Add(const Employee&);
    void Update(const Employee&);
    void Delete(const Employee&);
    Employee* GetById(const int&);
    LinkedList<Employee> GetAll();

    int GetSize();
};
