#pragma once
#include "Date.h"
#include "Account.h"
#include <iostream>
using namespace std;


class Account;
class Person
{
protected:
	string fullName;
	Date dateOfBirth;
	bool gender;
	string phoneNumber;
	string email;
	int userId;
	Account* userAccount;
public:
	Person(
		const string & = "",
		const Date & = Date(),
		const bool& = true,
		const string & = "",
		const string & = "",
		const int& = 0,
		Account* = nullptr
	);
	Person(const Person&);
	virtual ~Person();

	void AddAccount(Account*);
	Account* getAccount() const;
	virtual string getRole() = 0;

	string getFullName();
	void setFullName(const string&);
	Date getDateOfBirth();
	void setDateOfBirth(const Date&);
	bool getGender();
	void setGender(const bool&);
	string getPhoneNumber();
	void setPhoneNumber(const string&);
	string getEmail();
	void setEmail(const string&);
	int getUserId();
	void setUserId(const int&);

	Person& operator=(const Person&);
	bool operator==(const Person&);
	bool operator!=(const Person&);
};