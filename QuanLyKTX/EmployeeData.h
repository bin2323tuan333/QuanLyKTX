#pragma once
#include "Employee.h"
#include "LinkedList.h"
#include "HashTable.h"


class EmployeeData
{
private:
    string fileName;
    LinkedList<Employee*> list;
    HashTable<int, Employee*> mapEmployeeId;

public:
    EmployeeData(const string&);
    ~EmployeeData();

    void loadData();
    void saveData();
    LinkedList<Employee*>* getList();

    void Add(const Employee&);
    void Update(const Employee&);
    void Delete(const Employee&);
    Employee* GetByEmployeeId(const int&);

    int GetSize();
};
