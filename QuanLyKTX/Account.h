#pragma once
#include <string>
using namespace std;


class Person;
class Account
{
private:
    string username;
    string password;

    Person* user;
public:
    Account(const string & = "", const string & = "", Person* = nullptr);
    Account(const Account&);
    ~Account();

    void AddUser(Person*);

    string getUsername() const;
    void setUsername(const string&);
    string getPassword();
    void setPassword(const string&);

    Account& operator=(const Account&);
    bool operator==(const Account&);
    bool operator!=(const Account&);
};
