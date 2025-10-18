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
int AccountService::changePassword(const int& id, const string& oldPass, const string& newPass, const string& reEnterNewPass)
{
	if (newPass == "" || reEnterNewPass == "" || oldPass == "")
		return 2;

	

	Account tempAccount = this->accountRepo.SearchByID(id);

	if (tempAccount.getAccountID() == 0)
		return 2;

	if (tempAccount.getPassword() != oldPass)
		return 4;
	if (newPass != reEnterNewPass)
		return 3;

	tempAccount.setPassword(newPass);
	this->accountRepo.Update(tempAccount);

	this->accountRepo.SaveDateToFile();
	return 0;
}
bool AccountService::isSignIn()
{
	return this->isLogin;
}
void AccountService::setSignIn(bool b)
{
	this->isLogin = b;
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
