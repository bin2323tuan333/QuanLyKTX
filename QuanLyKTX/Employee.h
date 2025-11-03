#pragma once
#include "Person.h"


class Employee : public Person
{
private:
    int employeeId;
    string role;
    int salary;

public:
    // Constructor, Copy constructor, Destructor
    Employee(
        const string & = "",
        const Date & = Date(),
        const bool& = true,
        const string & = "",
        const string & = "",
        const int& = 0,
        Account* = nullptr,
        const int& = 0,
        const string& = "",
        const int& = 0
    );
    Employee(const Employee&);
    ~Employee();


    // Getter & Setter
    int getEmployeeId() const;
    void setEmployeeId(const int&);
    string getRole() override;
    void setRole(const string&);
    int getSalary();
    void setSalary(const int&);


    Employee& operator=(const Employee&);
    bool operator==(const Employee&);
    bool operator!=(const Employee&);
};
