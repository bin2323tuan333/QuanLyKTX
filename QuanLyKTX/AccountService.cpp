#include "AccountService.h"




AccountService::AccountService(AccountRepository& repo)
    : accountRepo(repo), isLogin(false), role("")
{
}
AccountService::~AccountService()
{
}


bool AccountService::signIn(const string& username, const string& password)
{
    Account temp = (this->accountRepo.SearchByUsername(username));
    if (username == temp.getUsername() && password == temp.getPassword())
    {
        this->role = temp.getRole();
        this->username = temp.getUsername();
        this->studentID = temp.getStudentID();
        this->employeeID = temp.getEmployeeID();
        this->isLogin = true;
        return true;
    }
    return false;
}
bool AccountService::changePassword(const string& username, const string& oldPassword, const string& newPassword)
{
    return false;
}
bool AccountService::isSignIn()
{
    return this->isLogin;
}
string AccountService::getRole()
{
    return this->role;
}
int AccountService::getEmployeeID()
{
    return this->employeeID;
}
int AccountService::getStudentID()
{
    return this->studentID;
}
string AccountService::getUsername()
{
    return this->username;
}

bool AccountService::createAccount(const Account& account)
{
    return false;
}
bool AccountService::updateAccount(const Account& account)
{
    return false;
}
bool AccountService::deleteAccount(const int& accountID)
{
    return false;
}


Account AccountService::findAccountByUsername(const string& username)
{

    return Account();
}
Account AccountService::findAccountById(const int&)
{
    return Account();
}
