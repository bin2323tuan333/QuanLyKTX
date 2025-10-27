#include "AccountService.h"


AccountService::AccountService(AccountRepository& repo)
	: accountRepo(repo), isLogin(false)
{
	this->currentID = 0;
}
AccountService::~AccountService()
{
}

int AccountService::SignIn(const string& username, const string& password)
{
	Account* temp = this->SearchByUsername(username);
	if (temp == nullptr) return 0;
	else if (temp->getPassword() != password) return 0;
	
	this->currentID = temp->getAccountID();
	this->isLogin = true;
	return 1;
}
bool AccountService::isSignIn()
{
	return this->isLogin;
}
void AccountService::setSignIn(const bool& bol)
{
	this->isLogin = bol;
}
int AccountService::getCurrentID()
{
	return this->currentID;
}
int AccountService::changePassword(const int& accountID, const string& oldPass, const string& newPass, const string& reNewPass)
{
	if (oldPass == "" || newPass == "" || reNewPass == "") return -1;
	if (oldPass == newPass) return 0;
	if (newPass != reNewPass) return -4;
	Account* temp = this->SearchByID(accountID);
	if (temp == nullptr) return -2;
	if (temp->getPassword() != oldPass) return -3;

	temp->setPassword(newPass);
	return 1;
}



int AccountService::Add(const Account& temp)
{
	this->accountRepo.Add(temp);
	return 1;
}
Account* AccountService::SearchByID(const int& accountID)
{
	return this->accountRepo.GetById(accountID);
}
Account* AccountService::SearchByUsername(const string& username)
{
	return this->accountRepo.GetByUsername(username);
}
LinkedList<Account> AccountService::GetAll()
{
	return this->accountRepo.GetAll();
}
int AccountService::Update(const Account& temp)
{
	this->accountRepo.Update(temp);
	return 1;
}
int AccountService::Delete(const Account& temp)
{
	this->accountRepo.Delete(temp);
	return 1;
}
