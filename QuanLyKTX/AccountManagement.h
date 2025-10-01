#pragma once
#include "AccountRepository.h"


class AccountService
{
private:
    AccountRepository& accountRepo;

public:
    AccountService(AccountRepository&);
    ~AccountService();


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