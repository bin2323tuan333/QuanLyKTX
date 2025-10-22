#pragma once
#include "Date.h"
#include <iostream>
using namespace std;

class Person
{
protected:
	string fullName;
	Date dateOfBirth;
	string gender;
	string phoneNumber;
	string email;

public:
	Person(const string& = "", const Date& = Date(), const string & = "", const string & = "", const string & = "");
	Person(const Person&);
	~Person();

	string getFullName();
	void setFullName(const string&);
	Date getDateOfBirth();
	void setDateOfBirth(const Date&);
	string getGender();
	void setGender(const string&);
	string getPhoneNumber();
	void setPhoneNumber(const string&);
	string getEmail();
	void setEmail(const string&);

	Person& operator=(const Person&);
	bool operator==(const Person&);
};