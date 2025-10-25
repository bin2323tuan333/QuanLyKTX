#pragma once
#include "Student.h"
#include "LinkedList.h"


class StudentRepository
{
private:
    string fileName;
    LinkedList<Student> list;

public:
    StudentRepository(const string&);
    ~StudentRepository();

    void loadData();
    void saveData();

    void Add(const Student&);
    void Update(const Student&);
    void Delete(const Student&);
    Student* GetById(const int&);
    LinkedList<Student> GetAll();

    int GetSize();
};
