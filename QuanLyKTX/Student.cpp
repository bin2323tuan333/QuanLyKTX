#include "Student.h"
#include <iostream>

// Constructor
Student::Student(const string& fullName, const Date& dateOfBirth, const bool& gender, const string & phoneNumber,
	const string & email, const int& userId, Account* acc, const int& studentId, const string & className, const string & faculty)
	: Person(fullName, dateOfBirth, gender, phoneNumber, email, userId, acc), studentId(studentId), className(className), faculty(faculty)
{
}
Student::Student(const Student& s)
	: Person(s.fullName, s.dateOfBirth, s.gender, s.phoneNumber, s.email, s.userId, s.userAccount), studentId(s.studentId), className(s.className), faculty(s.faculty)
{
}
Student::~Student()
{
}


void Student::AddContract(Contract* contract)
{
	this->contracts.add(contract);
}
LinkedList<Contract*>* Student::getContracts()
{
	return &(this->contracts);
}
string Student::getRole()
{
	return "student";
}
// Getter & Setter
int Student::getStudentID() const
{
	return this->studentId;
}
void Student::setStudentID(const int& studentId)
{
	this->studentId = studentId;
}
string Student::getClassName()
{
	return this->className;
}
void Student::setClassName(const string& className)
{
	this->className = className;
}
string Student::getFaculty()
{
	return this->faculty;
}
void Student::setFaculty(const string& faculty)
{
	this->faculty = faculty;
}


Student& Student::operator=(const Student& other)
{
	if (this == &other)
		return *this;

	this->Person::operator=(other);
	this->studentId = other.studentId;
	this->className = other.className;
	this->faculty = other.faculty;

	return *this;
}
bool Student::operator==(const Student& other)
{
	if (!(this->Person::operator==(other)))
		return false;
	return (this->studentId == other.studentId &&
		this->className == other.className &&
		this->faculty == other.faculty);
}


bool Student::operator!=(const Student& other)
{
	if (this->Person::operator!=(other))
		return true;
	return (this->studentId != other.studentId ||
		this->className != other.className ||
		this->faculty != other.faculty);
}

