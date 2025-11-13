#pragma once
#include "Date.h"
#include "IPerson.h"


class IAccount;
class Person : public virtual IPerson
{
protected:
	string fullName;
	Date dateOfBirth;
	bool gender;
	string phoneNumber;
	string email;
	int userId;
	IAccount* userAccount;
public:
	Person(const string & = "", const Date & = Date(), const bool& = true, const string & = "", const string & = "", const int& = 0, IAccount* = nullptr);
	Person(const Person&);
	virtual ~Person();

	void AddAccount(IAccount*);
	IAccount* getAccount() override;

	virtual string getRole() override = 0;
	string getFullName() const override;
	void setFullName(const string&) override;
	Date getDateOfBirth() const override;
	void setDateOfBirth(const Date&) override;
	bool getGender() const override;
	void setGender(const bool&) override;
	string getPhoneNumber() const override;
	void setPhoneNumber(const string&) override;
	string getEmail() const override;
	void setEmail(const string&) override;
	int getUserId() const override;
	void setUserId(const int&) override;

	Person& operator=(const Person&);
	bool operator==(const Person&);
	bool operator!=(const Person&);
};