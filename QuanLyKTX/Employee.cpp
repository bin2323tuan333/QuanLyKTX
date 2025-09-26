#include <iostream>
#include "Employee.h"

// Constructor
Employee::Employee(const int& employeeID, const string& fullName, const Date& dateOfBirth, const string& gender, 
    const string& position, const string& phoneNumber, const string& email)
    : employeeID(employeeID), fullName(fullName), dateOfBirth(dateOfBirth),
    gender(gender), position(position), phoneNumber(phoneNumber), email(email) 
{
}
Employee::Employee(const Employee& e)
    : employeeID(e.employeeID), fullName(e.fullName), dateOfBirth(e.dateOfBirth), 
    gender(e.gender), position(e.position), phoneNumber(e.phoneNumber), email(e.email) 
{
}
Employee::~Employee() 
{
}



// Getter & Setter
int Employee::getEmployeeID() 
{
    return this->employeeID;
}
void Employee::setEmployeeID(const int& employeeID) 
{
    this->employeeID = employeeID;
}
string Employee::getFullName() 
{
    return this->fullName;
}
void Employee::setFullName(const string& fullName) 
{
    this->fullName = fullName;
}
Date Employee::getDateOfBirth() 
{
    return this->dateOfBirth;
}
void Employee::setDateOfBirth(const Date& dateOfBirth) 
{
    this->dateOfBirth = dateOfBirth;
}
string Employee::getGender() 
{
    return this->gender;
}
void Employee::setGender(const string& gender) 
{
    this->gender = gender;
}
string Employee::getPosition() 
{
    return this->position;
}
void Employee::setPosition(const string& position) 
{
    this->position = position;
}
string Employee::getPhoneNumber() 
{
    return this->phoneNumber;
}
void Employee::setPhoneNumber(const string& phoneNumber) 
{
    this->phoneNumber = phoneNumber;
}
string Employee::getEmail() 
{
    return this->email;
}
void Employee::setEmail(const string& email) 
{
    this->email = email;
}





void Employee::show() 
{
    std::cout << this->employeeID << " "
        << this->fullName << " "
        << this->dateOfBirth << " "
        << this->gender << " "
        << this->position << " "
        << this->phoneNumber << " "
        << this->email;
}
