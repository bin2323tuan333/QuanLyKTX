#pragma once
#include "LinkedList.h"
#include "Person.h"


class Contract;
class Student : public Person
{
private:
    int studentId;
    string className;
    string faculty;
    LinkedList<Contract*> contracts;
public:
    Student( const string & = "", const Date & = Date(), const bool& = true, const string & = "", const string & = "", const int& = 0, Account* = nullptr, const int& = 0, const string& = "", const string& = "");
    Student(const Student&);
    ~Student();

    void AddContract(Contract*);
    LinkedList<Contract*>* getContracts();
    string getRole() override;
    bool hasActiveContract();
    
    int getStudentId() const;
    void setStudentId(const int&);
    string getClassName() const;
    void setClassName(const string&);
    string getFaculty() const;
    void setFaculty(const string&);
    Student& operator=(const Student&);
    bool operator==(const Student&);
    bool operator!=(const Student&);
};
