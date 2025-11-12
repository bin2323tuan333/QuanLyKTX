#pragma once
#include "IStudent.h"



class Contract;
class Student : public Person, public IStudent
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

    void AddContract(Contract*);
    LinkedList<IContract*>* getContracts();
    string getRole() override;
    bool hasActiveContract();
    int getStudentId() const;
    void setStudentId(const int&);
    string getClassName();
    void setClassName(const string&);
    string getFaculty();
    void setFaculty(const string&);

    Student& operator=(const Student&);
    bool operator==(const Student&);
    bool operator!=(const Student&);
};
