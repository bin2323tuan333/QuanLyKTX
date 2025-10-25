#include <iostream>
#include "Employee.h"

// Constructor
Employee::Employee(const int& employeeID, const string& fullName, const Date& dateOfBirth, const string& gender,
	const string& position, const string& phoneNumber, const string& email)
	: Person(fullName, dateOfBirth, gender, phoneNumber, email), employeeID(employeeID), position(position)
{
}
Employee::Employee(const Employee& e)
	: Person(e.fullName, e.dateOfBirth, e.gender, e.phoneNumber, e.email), employeeID(e.employeeID), position(e.position)
{
}
Employee::~Employee()
{
}


// Getter & Setter
int Employee::getEmployeeID() const
{
	return this->employeeID;
}
void Employee::setEmployeeID(const int& employeeID)
{
	this->employeeID = employeeID;
}
string Employee::getPosition()
{
	return this->position;
}
void Employee::setPosition(const string& position)
{
	this->position = position;
}

Employee& Employee::operator=(const Employee& other)
{
	if (this == &other)
		return *this;

	this->Person::operator=(other);
	this->employeeID = other.employeeID;
	this->position = other.position;

	return *this;
}