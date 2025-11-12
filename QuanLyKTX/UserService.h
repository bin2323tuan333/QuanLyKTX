#pragma once
#include "DB.h"

class UserService
{
private:
    DB* database;

public:
    UserService();
    ~UserService();


    //// ===== STUDENT MANAGEMENT =====
    int createStudent(Student&);
    Student* getStudentById(const int&);
    LinkedList<Student*>* getAllStudents();
    int updateStudent(int studentId, const Student& updatedStudent);
    int deleteStudent(int studentId);
    LinkedList<Student*> getStudentsWithoutRoom();
};

