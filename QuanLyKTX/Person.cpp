#include "Person.h"

Person::Person(const string& fullName, const Date& dateOfBirth, const string& gender, const string& phoneNumber, const string& email)
	:fullName(fullName), dateOfBirth(dateOfBirth), gender(gender), phoneNumber(phoneNumber), email(email)
{
}
Person::Person(const Person& person)
	:fullName(person.fullName), dateOfBirth(person.dateOfBirth), gender(person.gender), phoneNumber(person.phoneNumber), email(person.email)
{
}
Person::~Person()
{
}


string Person::getFullName()
{
	return this->fullName;
}
void Person::setFullName(const string& fullName)
{
	this->fullName = fullName;
}
Date Person::getDateOfBirth()
{
	return this->dateOfBirth;
}
void Person::setDateOfBirth(const Date& dateOfBirth)
{
	this->dateOfBirth = dateOfBirth;
}
string Person::getGender()
{
	return this->gender;
}
void Person::setGender(const string& gender)
{
	this->gender = gender;
}
string Person::getPhoneNumber()
{
	return this->phoneNumber;
}
void Person::setPhoneNumber(const string& phoneNumber)
{
	this->phoneNumber = phoneNumber;
}
string Person::getEmail()
{
	return this->email;
}
void Person::setEmail(const string& email)
{
	this->email = email;
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

	return *this;
}

bool Person::operator==(const Person& other)
{
	return (this->fullName == other.fullName &&
		this->dateOfBirth == other.dateOfBirth &&
		this->gender == other.gender &&
		this->phoneNumber == other.phoneNumber &&
		this->email == other.email);
}

