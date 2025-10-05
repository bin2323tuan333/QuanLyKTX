#pragma once
#include "Date.h"
#include <string>
using namespace std;




class Student {
private:
    int studentID;
    string fullName;
    Date dateOfBirth;
    string gender;
    string className;
    string faculty;
    string phoneNumber;
    string email;

public:
    Student(const int& = 0, const string & = "", const Date & = Date(), const string & = "",
        const string & = "", const string & = "", const string & = "", const string & = "");
    Student(const Student&);
    ~Student();

    // Getter & Setter
    int getStudentID();
    void setStudentID(const int&);

    string getFullName();
    void setFullName(const string&);

    Date getDateOfBirth();
    void setDateOfBirth(const Date&);

    string getGender();
    void setGender(const string&);

    string getClassName();
    void setClassName(const string&);

    string getFaculty();
    void setFaculty(const string&);

    string getPhoneNumber();
    void setPhoneNumber(const string&);

    string getEmail();
    void setEmail(const string&);
};
