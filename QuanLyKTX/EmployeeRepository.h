#pragma once
#include "Employee.h"




class EmployeeRepository
{
private:
    Employee* p;
    int n;

public:
    EmployeeRepository();
    ~EmployeeRepository();

    // Create
    void Add(const Employee&);
    void Insert(const Employee&, const int&);

    // Read
    void Show();
    int IndexOf(const int&);
    Employee Search(const int&);

    // Update
    void Update(const int&);

    // Delete
    void Delete(const int&);

    void LoadDataFromFile();
    void SaveDateToFile();
};
