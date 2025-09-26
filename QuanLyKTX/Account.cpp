#include "Account.h"
#include <iomanip>
#include <iostream>



// Constructor
Account::Account(const int& accountID, const string& username, const string& password, const string& role,
    const int& studentID, const int& employeeID)
    : accountID(accountID), username(username), password(password), role(role), studentID(studentID), employeeID(employeeID)
{
}
Account::Account(const Account& acc)
    : accountID(acc.accountID), username(acc.username), password(acc.password), role(acc.role), studentID(acc.studentID), employeeID(acc.employeeID)
{
}
Account::~Account()
{
}



// Getter & setter
int Account::getAccountID()
{
    return this->accountID;
}
void Account::setAccountID(const int& accountID)
{
    this->accountID = accountID;
}
string Account::getUsername() 
{
    return this->username;
}
void Account::setUsername(const string& username) 
{
    this->username = username;
}
string Account::getPassword() 
{
    return this->password;
}
void Account::setPassword(const string& password) 
{
    this->password = password;
}
string Account::getRole() 
{
    return this->role;
}
void Account::setRole(const string& role) 
{
    this->role = role;
}
int Account::getStudentID() 
{
    return this->studentID;
}
void Account::setStudentID(const int& studentID) 
{
    this->studentID = studentID;
}
int Account::getEmployeeID() 
{
    return this->employeeID;
}
void Account::setEmployeeID(const int& employeeID) 
{
    this->employeeID = employeeID;
}




void Account::show() 
{
    cout << setw(5) << right << this->accountID << setw(20) << right << this->username << setw(15) << right << this->role;
    if (role == "student") {
        cout << setw(10) << right << this->studentID;
    }
    else {
        cout << setw(10) << right << this->employeeID;
    }
}
