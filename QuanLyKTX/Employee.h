#pragma once
#include "Person.h"


class Employee : public Person
{
private:
    int employeeId;
    int salary;

public:
    Employee(const string & = "", const Date & = Date(), const bool& = true, const string & = "", const string & = "", const int& = 0, Account* = nullptr, const int& = 0, const int& = 0);
    Employee(const Employee&);
    ~Employee();

    int getEmployeeId() const;
    void setEmployeeId(const int&);
    string getRole() override;
    int getSalary() const;
    void setSalary(const int&);
    Employee& operator=(const Employee&);
    bool operator==(const Employee&);
    bool operator!=(const Employee&);
};
