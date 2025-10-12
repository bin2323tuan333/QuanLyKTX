#pragma once
#include "AccountRepository.h"


class AccountService
{
private:
    AccountRepository& accountRepo;
    bool isLogin;
    string role;
    int employeeID;
    int studentID;
    string username;

public:
    AccountService(AccountRepository&);
    ~AccountService();


    bool signIn(const string&, const string&);
    bool changePassword(const int&, const string&, const string&, const string&);
    bool isSignIn();
    void setSignIn(bool);
    int getEmployeeID();
    int getStudentID();
    string getUsername();
    string getRole();

    bool createAccount(const Account&);
    bool updateAccount(const Account&);
    bool deleteAccount(const int&);


    Account findAccountByUsername(const string&);
    Account findAccountById(const int&);
};