#pragma once
#include "Employee.h"
#include "LinkedList.h"
#include "HashTable.h"


class EmployeeData
{
private:
    string fileName;
    LinkedList<Employee*> list;
    HashTable<int, Employee*> map;

public:
    EmployeeData(const string&);
    ~EmployeeData();

    void loadData();
    void saveData();

    void Add(const Employee&);
    void Update(const Employee&);
    void Delete(const Employee&);
    Employee* GetById(const int&);
    LinkedList<Employee> GetAll();

    int GetSize();
};
