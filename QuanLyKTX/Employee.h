#pragma once
#include "Person.h"
#include "IEmployee.h"


class Employee : public Person, public virtual IEmployee
{
private:
    int employeeId;
    int salary;

public:
    Employee(const string & = "", const Date & = Date(), const bool& = true, const string & = "", const string & = "", const int& = 0, IAccount* = nullptr, const int& = 0, const int& = 0);
    Employee(const Employee&);
    ~Employee();

    int getEmployeeId() const override;
    void setEmployeeId(const int&) override;
    string getRole() override;
    int getSalary() const override;
    void setSalary(const int&) override;


    Employee& operator=(const Employee&);
    bool operator==(const Employee&);
    bool operator!=(const Employee&);
};
