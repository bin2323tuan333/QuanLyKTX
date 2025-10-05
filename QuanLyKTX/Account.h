#pragma once
#include <string>
using namespace std;




class Account
{
private:
    int accountID;
    string username, password;
    string role;
    int studentID, employeeID;

public:
    Account(const int& = 0, const string & = "", const string & = "", const string & = "", const int& = 0, const int& = 0);
    Account(const Account&);
    ~Account();

    // Getter & Setter
    int getAccountID();
    void setAccountID(const int&);

    string getUsername();
    void setUsername(const string&);

    string getPassword();
    void setPassword(const string&);

    string getRole();
    void setRole(const string&);

    int getStudentID();
    void setStudentID(const int&);

    int getEmployeeID();
    void setEmployeeID(const int&);

};
