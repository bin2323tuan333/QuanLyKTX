#pragma once
#include "AccountRepository.h"


class LoginService
{
private:
    AccountRepository& accountRepo;

public:
    LoginService(AccountRepository&);
    ~LoginService();


    // SignIn
    bool SignIn(const string&, const string&);

    // ChangePassword
    bool ChangePassword(const string&, const string&, const string&);

    // GetAllAccount
    Account* GetAllAccount();

    // UpdateAccount
    bool UpdateAccount(const Account&);
   

    // DeleteAccount
    bool DeleteAccount(const int&);

    // FindAccountByUsername
    Account FindAccountByUsername(const string&);
};