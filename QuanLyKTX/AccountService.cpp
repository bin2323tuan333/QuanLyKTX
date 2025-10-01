#include "AccountService.h"




AccountService::AccountService(AccountRepository& repo)
    : accountRepo(repo) 
{
}
AccountService::~AccountService()
{
}


bool AccountService::SignIn(const string& username, const string& password)
{
    Account temp = (this->accountRepo.SearchByUsername(username));
    if (username == temp.getUsername() && password == temp.getPassword())
        return true;
    return false;
}

bool AccountService::ChangePassword(const string& username, const string& oldPassword, const string& newPassword)
{
    Account temp = (this->accountRepo.SearchByUsername(username));
    if (oldPassword == temp.getPassword())
    {
        temp.setPassword(newPassword);
        return true;
    }
    return false;
}

Account* AccountService::GetAllAccount()
{

}

bool AccountService::UpdateAccount(const Account& account)
{

}

bool AccountService::DeleteAccount(const int& accountID)
{

}

Account AccountService::FindAccountByUsername(const string& username)
{

}