#pragma once
#include "Person.h"


class Employee : public Person
{
private:
    int employeeID;
    string position;

public:
    // Constructor, Copy constructor, Destructor
    Employee(const int& = 0, const string & = "", const Date & = Date(), const string & = "",
        const string & = "", const string & = "", const string & = "");
    Employee(const Employee&);
    ~Employee();

    // Getter & Setter
    int getEmployeeID() const;
    void setEmployeeID(const int&);
    string getPosition();
    void setPosition(const string&);


    Employee& operator=(const Employee&);
    bool operator==(const Employee&);
    bool operator!=(const Employee&);
};
