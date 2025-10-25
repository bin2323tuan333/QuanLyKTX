#pragma once
#include "Account.h"
#include "AccountRepository.h"



class AccountService
{
private:
    AccountRepository* accountRepo;

public:
    AccountService(AccountRepository*);
    ~AccountService();


    int Login(const string&, const string&);
    int GetSize();

    int Add(const Account&);
    Account* SearchByID(const int&);
    Account* SearchByUsername(const string&);
    LinkedList<Account> getAll();
    int Update(const Account&);
    int Delete(const Account&);
};