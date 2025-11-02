#include "Account.h"
#include <iomanip>
#include <iostream>



// Constructor
Account::Account(const int& userId, const string & username, const string & password, Person* user)
	:userId(userId), username(username), password(password), user(user)
{
}
Account::Account(const Account& acc)
	:userId(acc.userId), username(acc.username), password(acc.password), user(acc.user)
{
}
Account::~Account()
{
}

void Account::AddUser(Person* user)
{
	this->user = user;
}


int Account::getUserId() const
{
	return this->userId;
}
void Account::setUserId(const int& id)
{
	this->userId = id;
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
	return (this->userId == acc.userId &&
		this->username == acc.username &&
		this->password == acc.password &&
		this->user == acc.user);
}

bool Account::operator!=(const Account& acc)
{
	return (this->userId != acc.userId ||
		this->username != acc.username ||
		this->password != acc.password ||
		this->user != acc.user);
}

Account& Account::operator=(const Account& acc)
{
	if (this == &acc)
		return *this;

	this->userId = acc.userId;
	this->username = acc.username;
	this->password = acc.password;
	this->user = acc.user;
	return *this;
}