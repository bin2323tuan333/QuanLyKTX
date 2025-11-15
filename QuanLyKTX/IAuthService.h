#pragma once
#include <string>
using namespace std;

class Person;
class Account;
class IAuthService
{
public:
    virtual ~IAuthService();

    virtual Account* login(const string&, const string&) = 0;
    virtual int changePassword(Account*, const string&, const string&, const string&) = 0;
    virtual bool genAccount(Person*) = 0;
    virtual int getIdAuto() = 0;
};