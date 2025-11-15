#pragma once
#include "Date.h"


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
	Person(const string & = "", const Date & = Date(), const bool& = true, const string & = "", const string & = "", const int& = 0, Account* = nullptr);
	Person(const Person&);
	virtual ~Person();

	void AddAccount(Account*);
	Account* getAccount();

	virtual string getRole() = 0;
	string getFullName() const;
	void setFullName(const string&);
	Date getDateOfBirth() const;
	void setDateOfBirth(const Date&);
	bool getGender() const;
	void setGender(const bool&);
	string getPhoneNumber() const;
	void setPhoneNumber(const string&);
	string getEmail() const;
	void setEmail(const string&);
	int getUserId() const;
	void setUserId(const int&);
	Person& operator=(const Person&);
	bool operator==(const Person&);
	bool operator!=(const Person&);
};