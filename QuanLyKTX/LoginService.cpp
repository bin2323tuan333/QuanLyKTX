#include "LoginService.h"




LoginService::LoginService(AccountRepository& repo)
    : accountRepo(repo) 
{
}
LoginService::~LoginService()
{
}


bool LoginService::SignIn(const string& username, const string& password)
{
    Account temp = (this->accountRepo.SearchByUsername(username));
    if (username == temp.getUsername() && password == temp.getPassword())
        return true;
    return false;
}

bool LoginService::ChangePassword(const string& username, const string& oldPassword, const string& newPassword)
{
    Account temp = (this->accountRepo.SearchByUsername(username));
    if (oldPassword == temp.getPassword())
    {
        temp.setPassword(newPassword);
        return true;
    }
    return false;
}

Account* LoginService::GetAllAccount()
{

}

bool LoginService::UpdateAccount(const Account& account)
{

}

bool LoginService::DeleteAccount(const int& accountID)
{

}

Account LoginService::FindAccountByUsername(const string& username)
{

}