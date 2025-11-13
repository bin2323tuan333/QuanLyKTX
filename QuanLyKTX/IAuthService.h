#pragma once
#include <string>
using namespace std;

class IPerson;
class IAccount;
class IAuthService
{
public:
    virtual ~IAuthService();

    virtual IAccount* login(const string&, const string&) = 0;
    virtual int changePassword(IAccount*, const string&, const string&, const string&) = 0;
    virtual bool genAccount(IPerson*) = 0;
    virtual int getIdAuto() = 0;
};