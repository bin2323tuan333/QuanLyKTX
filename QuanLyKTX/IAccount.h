#pragma once
#include "IPerson.h"

class IAccount {
public:
    virtual ~IAccount();

    virtual void AddUser(IPerson* user) = 0;
    virtual IPerson* getUser() const = 0;

    virtual int getUserId() const = 0;
    virtual string getUsername() const = 0;
    virtual string getPassword() const = 0;
    virtual void setUserId(const int&) = 0;
    virtual void setUsername(const string&) = 0;
    virtual void setPassword(const string&) = 0;
};

IAccount::~IAccount()
{
}