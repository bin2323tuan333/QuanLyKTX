#include "Student.h"
#include <iostream>

// Constructor
Student::Student(const int& studentID, const string& fullName, const Date& dateOfBirth, const string& gender, 
    const string& className, const string& faculty, const string& phoneNumber, const string& email)
    : Person(fullName, dateOfBirth, gender, phoneNumber, email), studentID(studentID), className(className), faculty(faculty)
{
}
Student::Student(const Student& s)
    : Person(s.fullName, s.dateOfBirth, s.gender, s.phoneNumber, s.email), studentID(s.studentID),className(s.className), faculty(s.faculty)
{
}
Student::~Student() 
{
}


// Getter & Setter
int Student::getStudentID() const
{
    return this->studentID;
}
void Student::setStudentID(const int& studentID) 
{
    this->studentID = studentID;
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
    this->studentID = other.studentID;
    this->className = other.className;
    this->faculty = other.faculty;

    return *this;
}
bool Student::operator==(const Student& other)
{
    if (!(this->Person::operator==(other)))
        return false;
    return (this->studentID == other.studentID &&
        this->className == other.className &&
        this->faculty == other.faculty);
}


bool Student::operator!=(const Student& other)
{
    if (this->Person::operator!=(other))
        return true;
    return (this->studentID != other.studentID ||
        this->className != other.className ||
        this->faculty != other.faculty);
}
