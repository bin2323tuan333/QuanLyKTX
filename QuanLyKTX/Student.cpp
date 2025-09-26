#include "Student.h"
#include <iostream>

// Constructor
Student::Student(const int& studentID, const string& fullName, const Date& dateOfBirth, const string& gender, 
    const string& className, const string& faculty, const string& phoneNumber, const string& email)
    : studentID(studentID), fullName(fullName), dateOfBirth(dateOfBirth), gender(gender), 
    className(className), faculty(faculty), phoneNumber(phoneNumber), email(email) 
{
}
Student::Student(const Student& s)
    : studentID(s.studentID), fullName(s.fullName), dateOfBirth(s.dateOfBirth), gender(s.gender), 
    className(s.className), faculty(s.faculty), phoneNumber(s.phoneNumber), email(s.email) 
{
}
Student::~Student() 
{
}




// Getter & Setter
int Student::getStudentID() 
{
    return this->studentID;
}
void Student::setStudentID(const int& studentID) 
{
    this->studentID = studentID;
}
string Student::getFullName() 
{
    return this->fullName;
}
void Student::setFullName(const string& fullName) 
{
    this->fullName = fullName;
}
Date Student::getDateOfBirth() 
{
    return this->dateOfBirth;
}
void Student::setDateOfBirth(const Date& dateOfBirth) 
{
    this->dateOfBirth = dateOfBirth;
}
string Student::getGender() 
{
    return this->gender;
}
void Student::setGender(const string& gender) 
{
    this->gender = gender;
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
string Student::getPhoneNumber() 
{
    return this->phoneNumber;
}
void Student::setPhoneNumber(const string& phoneNumber) 
{
    this->phoneNumber = phoneNumber;
}
string Student::getEmail() 
{
    return this->email;
}
void Student::setEmail(const string& email) 
{
    this->email = email;
}






void Student::show() {
    cout << this->studentID << " "
        << this->fullName << " "
        << this->gender << " "
        << this->dateOfBirth << " "
        << this->className << " "
        << this->faculty << " "
        << this->phoneNumber << " "
        << this->email;
}
