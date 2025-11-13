#pragma once
#include "IPerson.h"


class IEmployee : public virtual IPerson
{
public:
    virtual ~IEmployee();

    virtual int getEmployeeId() const = 0;
    virtual void setEmployeeId(const int&) = 0;
    virtual int getSalary() const = 0;
    virtual void setSalary(const int&) = 0;
};

