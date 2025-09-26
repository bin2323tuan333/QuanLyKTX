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
    void Show();
    int IndexOf(const int&);
    Student Search(const int&);

    // Update
    void Update(const int&);

    // Delete
    void Delete(const int&);

    void LoadDataFromFile();
    void SaveDateToFile();
};
