#pragma once
#include "IAccount.h"
#include "Person.h"

class Account : public virtual IAccount
{
private:
    int userId;
    string username;
    string password;
    IPerson* user;
public:
    Account(const int& = 0, const string & = "", const string & = "", IPerson* = nullptr);
    Account(const Account&);
    ~Account();

    void AddUser(IPerson*) override;
    IPerson* getUser() const override;

    int getUserId() const override;
    void setUserId(const int&) override;
    string getUsername() const override;
    void setUsername(const string&) override;
    string getPassword() const override;
    void setPassword(const string&) override;

    Account& operator=(const Account&);
    bool operator==(const Account&);
    bool operator!=(const Account&);
};
