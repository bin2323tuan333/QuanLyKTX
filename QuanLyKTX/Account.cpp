#include "Account.h"
#include <iomanip>
#include <iostream>



// Constructor
Account::Account(const string & username, const string & password, Person* user)
	:username(username), password(password), user(user)
{
}
Account::Account(const Account& acc)
	:username(acc.username), password(acc.password), user(acc.user)
{
}
Account::~Account()
{
}

void Account::AddUser(Person* user)
{
	this->user = user;
}

string Account::getUsername() const
{
	return this->username;
}
void Account::setUsername(const string& username)
{
	this->username = username;
}
string Account::getPassword()
{
	return this->password;
}
void Account::setPassword(const string& password)
{
	this->password = password;
}




bool Account::operator==(const Account& acc)
{
	return (this->username == acc.username &&
		this->password == acc.password &&
		this->user == acc.user);
}

bool Account::operator!=(const Account& acc)
{
	return (this->username != acc.username ||
		this->password != acc.password ||
		this->user != acc.user);
}

Account& Account::operator=(const Account& acc)
{
	if (this == &acc)
		return *this;

	this->username = acc.username;
	this->password = acc.password;
	this->user = acc.user;
	return *this;
}