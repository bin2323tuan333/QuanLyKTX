#pragma once
#include "Date.h"

class IAccount;
class IPerson {
public:
    virtual ~IPerson();
    virtual string getRole() = 0;

    virtual IAccount* getAccount() = 0;
    virtual void AddAccount(IAccount*) = 0;

    virtual string getFullName() const = 0;
    virtual void setFullName(const string&) = 0;
    virtual Date getDateOfBirth() const = 0;
    virtual void setDateOfBirth(const Date&) = 0;
    virtual bool getGender() const = 0;
    virtual void setGender(const bool&) = 0;
    virtual string getPhoneNumber() const = 0;
    virtual void setPhoneNumber(const string&) = 0;
    virtual string getEmail() const = 0;
    virtual void setEmail(const string&) = 0;
    virtual int getUserId() const = 0;
    virtual void setUserId(const int&) = 0;
};

IPerson::~IPerson()
{
}