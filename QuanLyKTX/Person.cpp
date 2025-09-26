#include "Person.h"
#include <iostream>

using namespace std;

// Constructor
Person::Person(const string& fullName, const Date& dateOfBirth, const string& gender, const string& phoneNumber, const string& email)
    : fullName(fullName), dateOfBirth(dateOfBirth), gender(gender), phoneNumber(phoneNumber), email(email)
{
}
Person::Person(const Person& p)
    : fullName(p.fullName), dateOfBirth(p.dateOfBirth), gender(p.gender), phoneNumber(p.phoneNumber), email(p.email)
{
}
Person::~Person()
{
}



// Getter & Setter
string Person::getFullName()
{
    return fullName;
}
void Person::setFullName(const string& fullName)
{
    this->fullName = fullName;
}
Date Person::getDateOfBirth()
{
    return dateOfBirth;
}
void Person::setDateOfBirth(const Date& dateOfBirth)
{
    this->dateOfBirth = dateOfBirth;
}
string Person::getGender()
{
    return gender;
}
void Person::setGender(const string& gender)
{
    this->gender = gender;
}
string Person::getPhoneNumber()
{
    return phoneNumber;
}
void Person::setPhoneNumber(const string& phoneNumber)
{
    this->phoneNumber = phoneNumber;
}
string Person::getEmail()
{
    return email;
}
void Person::setEmail(const string& email)
{
    this->email = email;
}




// Show method
void Person::show()
{
    cout << "Full Name: " << fullName << " "
        << "Date of Birth: " << dateOfBirth << " "
        << "Gender: " << gender << " "
        << "Phone: " << phoneNumber << " "
        << "Email: " << email << endl;
}
