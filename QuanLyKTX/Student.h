#pragma once
#include "Person.h"
#include "Contract.h"
#include "LinkedList.h"




class Student : public Person
{
private:
    int studentId;
    string className;
    string faculty;

    LinkedList<Contract*> contracts;
public:
    Student(
        const string & = "",
        const Date & = Date(),
        const bool& = true,
        const string & = "",
        const string & = "",
        const int& = 0,
        Account* = nullptr,
        const int& = 0,
        const string& = "",
        const string& = ""
    );
    Student(const Student&);
    ~Student();

    void AddContract(Contract*);
    string getRole() override;

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
