#pragma once
#include "AccountRepository.h"


class AccountService
{
private:
    AccountRepository& accountRepo;
    bool isLogin;
public:
    AccountService(AccountRepository&);
    ~AccountService();


    bool signIn(const string&, const string&);
    bool changePassword(const string&, const string&, const string&);
    bool isSignIn();

    bool createAccount(const Account&);
    bool updateAccount(const Account&);
    bool deleteAccount(const int&);


    Account findAccountByUsername(const string&);
    Account findAccountById(const int&);
};