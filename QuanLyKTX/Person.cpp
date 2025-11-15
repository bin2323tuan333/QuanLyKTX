#include "Person.h"
#include "Account.h"

Person::Person(const string& fullName, const Date& dateOfBirth, const bool& gender, const string& phoneNumber, const string& email, const int& userId, Account* acc)
	:fullName(fullName), dateOfBirth(dateOfBirth), gender(gender), phoneNumber(phoneNumber), email(email), userId(userId), userAccount(acc)
{
}
Person::Person(const Person& person)
	:fullName(person.fullName), dateOfBirth(person.dateOfBirth), gender(person.gender), phoneNumber(person.phoneNumber), email(person.email), userId(person.userId), userAccount(person.userAccount)
{
}
Person::~Person()
{
}

void Person::AddAccount(Account* acc)
{
	this->userAccount = acc;
	acc->AddUser(this);
}
Account* Person::getAccount()
{
	return this->userAccount;
}

string Person::getFullName() const
{
	return this->fullName;
}
void Person::setFullName(const string& fullName)
{
	this->fullName = fullName;
}
Date Person::getDateOfBirth() const
{
	return this->dateOfBirth;
}
void Person::setDateOfBirth(const Date& dateOfBirth)
{
	this->dateOfBirth = dateOfBirth;
}
bool Person::getGender() const
{
	return this->gender;
}
void Person::setGender(const bool& gender)
{
	this->gender = gender;
}
string Person::getPhoneNumber() const
{
	return this->phoneNumber;
}
void Person::setPhoneNumber(const string& phoneNumber)
{
	this->phoneNumber = phoneNumber;
}
string Person::getEmail() const
{
	return this->email;
}
void Person::setEmail(const string& email)
{
	this->email = email;
}
int Person::getUserId() const
{
	return this->userId;
}
void Person::setUserId(const int& id)
{
	this->userId = id;
}


Person& Person::operator=(const Person& other)
{
	if (this == &other)
		return *this;

	this->fullName = other.fullName;
	this->dateOfBirth = other.dateOfBirth;
	this->email = other.email;
	this->gender = other.gender;
	this->phoneNumber = other.phoneNumber;
	this->userId = other.userId;
	this->userAccount = other.userAccount;
	return *this;
}

bool Person::operator==(const Person& other)
{
	return (this->fullName == other.fullName &&
		this->dateOfBirth == other.dateOfBirth &&
		this->gender == other.gender &&
		this->phoneNumber == other.phoneNumber &&
		this->email == other.email &&
		this->userId == other.userId &&
		this->userAccount == other.userAccount);
}

bool Person::operator!=(const Person& other)
{
	return (this->fullName != other.fullName ||
		this->dateOfBirth != other.dateOfBirth ||
		this->gender != other.gender ||
		this->phoneNumber != other.phoneNumber ||
		this->email != other.email ||
		this->userId != other.userId ||
		this->userAccount != other.userAccount);
}

