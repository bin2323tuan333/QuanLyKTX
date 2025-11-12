#pragma once
#include "Person.h"
#include "IEmployee.h"


class Employee : public Person, public IEmployee
{
private:
    int employeeId;
    string role;
    int salary;

public:
    // Constructor, Copy constructor, Destructor
    Employee(const string & = "", const Date & = Date(), const bool& = true, const string & = "", const string & = "", const int& = 0, IAccount* = nullptr, const int& = 0, const string& = "", const int& = 0);
    Employee(const Employee&);
    ~Employee();

    int getEmployeeId() const override;
    void setEmployeeId(const int&) override;
    string getRole() override;
    void setRole(const string&) override;
    int getSalary() const override;
    void setSalary(const int&) override;


    Employee& operator=(const Employee&);
    bool operator==(const Employee&);
    bool operator!=(const Employee&);
};
