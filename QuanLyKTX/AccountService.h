#pragma once
#include "Account.h"
#include "AccountData.h"



class AccountService
{
private:
    AccountData& accountData;

    bool isLogin;
    int currentId;

public:
    AccountService(AccountData&);
    ~AccountService();


    int SignIn(const string&, const string&);
    bool isSignIn();
    void setSignIn(const bool&);
    int getCurrentId();
    int changePassword(const int&, const string&, const string&, const string&);

    int Add(const Account&);
    Account* SearchByUserId(const int&);
    Account* SearchByUsername(const string&);
    LinkedList<Account*>* GetAll();
    int Update(const Account&);
    int Delete(const Account&);
};