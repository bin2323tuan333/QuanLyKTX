#include "Account.h"
#include <iomanip>
#include <iostream>



// Constructor
Account::Account(const int& accountID, const string& username, const string& password, const string& role,
	const int& studentID, const int& employeeID)
	: accountID(accountID), username(username), password(password), role(role), studentID(studentID), employeeID(employeeID)
{
}
Account::Account(const Account& acc)
	: accountID(acc.accountID), username(acc.username), password(acc.password), role(acc.role), studentID(acc.studentID), employeeID(acc.employeeID)
{
}
Account::~Account()
{
}


// Getter & setter
int Account::getAccountID() const
{
	return this->accountID;
}
void Account::setAccountID(const int& accountID)
{
	this->accountID = accountID;
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
string Account::getRole()
{
	return this->role;
}
void Account::setRole(const string& role)
{
	this->role = role;
}
int Account::getStudentID()
{
	return this->studentID;
}
void Account::setStudentID(const int& studentID)
{
	this->studentID = studentID;
}
int Account::getEmployeeID()
{
	return this->employeeID;
}
void Account::setEmployeeID(const int& employeeID)
{
	this->employeeID = employeeID;
}



bool Account::operator==(const Account& acc)
{
	return (this->accountID == acc.accountID &&
		this->username == acc.username &&
		this->password == acc.password &&
		this->role == acc.role &&
		this->studentID == acc.studentID &&
		this->employeeID == acc.employeeID);
}

bool Account::operator!=(const Account& acc)
{
	return (this->accountID != acc.accountID ||
		this->username != acc.username ||
		this->password != acc.password ||
		this->role != acc.role ||
		this->studentID != acc.studentID ||
		this->employeeID != acc.employeeID);
}

Account& Account::operator=(const Account& acc)
{
	if (this == &acc)
		return *this;

	this->accountID = acc.accountID;
	this->username = acc.username;
	this->password = acc.password;
	this->role = acc.role;
	this->studentID = acc.studentID;
	this->employeeID = acc.employeeID;

	return *this;
}