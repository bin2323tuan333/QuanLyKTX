#pragma once
#include "Date.h"
#include <string>
using namespace std;




class Employee {
private:
    int employeeID;
    string fullName;
    Date dateOfBirth;
    string gender;
    string position;
    string phoneNumber;
    string email;

public:
    // Constructor, Copy constructor, Destructor
    Employee(const int& = 0, const string & = "", const Date & = Date(), const string & = "",
        const string & = "", const string & = "", const string & = "");
    Employee(const Employee&);
    ~Employee();

    // Getter & Setter
    int getEmployeeID();
    void setEmployeeID(const int&);

    string getFullName();
    void setFullName(const string&);

    Date getDateOfBirth();
    void setDateOfBirth(const Date&);

    string getGender();
    void setGender(const string&);

    string getPosition();
    void setPosition(const string&);

    string getPhoneNumber();
    void setPhoneNumber(const string&);

    string getEmail();
    void setEmail(const string&);

    
    void show();
};
