#pragma once
#include "Account.h"
#include "AccountRepository.h"



class AccountService
{
private:
    AccountRepository& accountRepo;

    bool isLogin;
    int currentID;

public:
    AccountService(AccountRepository&);
    ~AccountService();


    int SignIn(const string&, const string&);
    bool isSignIn();
    void setSignIn(const bool&);
    int getCurrentID();
    int changePassword(const int&, const string&, const string&, const string&);

    int Add(const Account&);
    Account* SearchByID(const int&);
    Account* SearchByUsername(const string&);
    LinkedList<Account> GetAll();
    int Update(const Account&);
    int Delete(const Account&);
};