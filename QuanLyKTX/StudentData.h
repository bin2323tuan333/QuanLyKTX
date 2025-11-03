#pragma once
#include "Student.h"
#include "LinkedList.h"
#include "HashTable.h"


class StudentData
{
private:
    string fileName;
    LinkedList<Student*> list;
    HashTable<int, Student*> mapStudentId;

public:
    StudentData(const string&);
    ~StudentData();

    void loadData();
    void saveData();
    LinkedList<Student*>* getList();

    //void Add(const Student&);
    //void Update(const Student&);
    //void Delete(const Student&);
    Student* GetByStudentId(const int&);
    //LinkedList<Student> GetAll();

    //int GetSize();
};
