#pragma once
#include <string>
using namespace std;


class Person;
class Account
{
private:
    int userId;
    string username;
    string password;

    Person* user;
public:
    Account(const int& = 0, const string & = "", const string & = "", Person* = nullptr);
    Account(const Account&);
    ~Account();

    void AddUser(Person*);

    int getUserId() const;
    void setUserId(const int&);
    string getUsername() const;
    void setUsername(const string&);
    string getPassword();
    void setPassword(const string&);

    Account& operator=(const Account&);
    bool operator==(const Account&);
    bool operator!=(const Account&);
};
