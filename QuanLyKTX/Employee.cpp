#include <iostream>
#include "Employee.h"

// Constructor
Employee::Employee(const string& fullName, const Date& dateOfBirth, const bool& gender, const string& phoneNumber,
	const string& email, const int& userId, Account* acc, const int& employeeId, const string & role, const int& salary)
	:Person(fullName, dateOfBirth, gender, phoneNumber, email, userId, acc), employeeId(employeeId), role(role), salary(salary)
{
}
Employee::Employee(const Employee& e)
	: Person(e.fullName, e.dateOfBirth, e.gender, e.phoneNumber, e.email, e.userId, e.userAccount), employeeId(e.employeeId), role(e.role), salary(e.salary)
{
}
Employee::~Employee()
{
}





// Getter & Setter
int Employee::getEmployeeId() const
{
	return this->employeeId;
}
void Employee::setEmployeeId(const int& employeeId)
{
	this->employeeId = employeeId;
}
string Employee::getRole()
{
	return this->role;
}
void Employee::setRole(const string& role)
{
	this->role = role;
}
int Employee::getSalary()
{
	return this->salary;
}
void Employee::setSalary(const int& salary)
{
	this->salary = salary;
}


Employee& Employee::operator=(const Employee& other)
{
	if (this == &other)
		return *this;

	this->Person::operator=(other);
	this->employeeId = other.employeeId;
	this->role = other.role;
	this->salary = other.salary;
	return *this;
}

bool Employee::operator==(const Employee& other)
{
	if (!(this->Person::operator==(other)))
		return false;
	return (this->employeeId == other.employeeId &&
		this->role == other.role &&
		this->salary == other.salary);
}


bool Employee::operator!=(const Employee& other)
{
	if (this->Person::operator!=(other))
		return true;
	return (this->employeeId != other.employeeId ||
		this->role != other.role ||
		this->salary != other.salary);
}
