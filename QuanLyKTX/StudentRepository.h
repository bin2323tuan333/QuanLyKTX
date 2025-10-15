#pragma once
#include "Student.h"




class StudentRepository
{
private:
    Student* p;
    int n;

public:
    StudentRepository();
    ~StudentRepository();

    // Create
    void Add(const Student&);
    void Insert(const Student&, const int&);

    // Read
    int IndexOf(const int&);
    Student* Search(const int&);

    // Update
    void Update(Student&);

    // Delete
    void Delete(const int&);

    void LoadDataFromFile();
    void SaveDateToFile();
};
