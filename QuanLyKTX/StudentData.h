#pragma once
#include "Student.h"
#include "LinkedList.h"
#include "HashTable.h"


class StudentData
{
private:
    string fileName;
    LinkedList<Student*> list;
    HashTable<int, Student*> map;

public:
    StudentData(const string&);
    ~StudentData();

    void loadData();
    void saveData();

    void Add(const Student&);
    void Update(const Student&);
    void Delete(const Student&);
    Student* GetById(const int&);
    LinkedList<Student> GetAll();

    int GetSize();
};
