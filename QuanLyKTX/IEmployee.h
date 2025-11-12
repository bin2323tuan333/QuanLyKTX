#pragma once
#include "IPerson.h"


class IEmployee : public IPerson 
{
public:
    virtual ~IEmployee();

    virtual int getEmployeeId() const = 0;
    virtual void setEmployeeId(const int&) = 0;
    virtual string getRole() const = 0;
    virtual void setRole(const string&) = 0;
    virtual int getSalary() const = 0;
    virtual void setSalary(const int&) = 0;
    virtual void displayInfo() const = 0;
};

IEmployee::~IEmployee()
{
}