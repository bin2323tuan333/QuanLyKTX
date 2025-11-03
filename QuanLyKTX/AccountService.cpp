#include "AccountService.h"


AccountService::AccountService(AccountData& data)
	: accountData(data), isLogin(false)
{
	this->currentId = 0;
}
AccountService::~AccountService()
{
}

int AccountService::SignIn(const string& username, const string& password)
{
	Account* temp = this->SearchByUsername(username);
	if (temp == nullptr) return 0;
	else if (temp->getPassword() != password) return 0;
	
	this->currentId = temp->getUserId();
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
int AccountService::getCurrentId()
{
	return this->currentId;
}
int AccountService::changePassword(const int& userId, const string& oldPass, const string& newPass, const string& reNewPass)
{
	if (oldPass == "" || newPass == "" || reNewPass == "") return -1;
	if (oldPass == newPass) return 0;
	if (newPass != reNewPass) return -4;
	Account* temp = this->SearchByUserId(userId);
	if (temp == nullptr) return -2;
	if (temp->getPassword() != oldPass) return -3;

	temp->setPassword(newPass);
	return 1;
}



int AccountService::Add(const Account& temp)
{
	this->accountData.Add(temp);
	return 1;
}
Account* AccountService::SearchByUserId(const int& userId)
{
	return this->accountData.GetByUserId(userId);
}
Account* AccountService::SearchByUsername(const string& username)
{
	return this->accountData.GetByUsername(username);
}
LinkedList<Account*>* AccountService::GetAll()
{
	return this->accountData.getList();
}
int AccountService::Update(const Account& temp)
{
	this->accountData.Update(temp);
	return 1;
}
int AccountService::Delete(const Account& temp)
{
	this->accountData.Delete(temp);
	return 1;
}
