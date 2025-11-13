#pragma once
#include "IStudent.h"
#include "Person.h"
#include <iostream>
using namespace std;


class IContract;
class Student : public virtual IStudent, public Person
{
private:
    int studentId;
    string className;
    string faculty;
    LinkedList<IContract*> contracts;
public:
    Student( const string & = "", const Date & = Date(), const bool& = true, const string & = "", const string & = "", const int& = 0, IAccount* = nullptr, const int& = 0, const string& = "", const string& = "");
    Student(const Student&);
    ~Student();

    void AddContract(IContract*);
    LinkedList<IContract*>* getContracts();
    string getRole() override;
    bool hasActiveContract() override;
    
    int getStudentId() const;
    void setStudentId(const int&) override;
    string getClassName() const override;
    void setClassName(const string&) override;
    string getFaculty() const override;
    void setFaculty(const string&) override;

    Student& operator=(const Student&);
    bool operator==(const Student&);
    bool operator!=(const Student&);
};
