#pragma once
#include "Person.h"




class Student : public Person
{
private:
    int studentID;
    string className;
    string faculty;

public:
    Student(const int& = 0, const string & = "", const Date & = Date(), const string & = "",
        const string & = "", const string & = "", const string & = "", const string & = "");
    Student(const Student&);
    ~Student();

    // Getter & Setter
    int getStudentID() const;
    void setStudentID(const int&);
    string getClassName();
    void setClassName(const string&);
    string getFaculty();
    void setFaculty(const string&);

    Student& operator=(const Student&);
    bool operator==(const Student&);
    bool operator!=(const Student&);
};
