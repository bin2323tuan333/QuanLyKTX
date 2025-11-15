#pragma once
#include "LinkedList.h"

class Student;
class IUserService
{
public:
    virtual ~IUserService();

    virtual int createStudent(Student&) = 0;
    virtual Student* getStudentById(const int&) = 0;
    virtual LinkedList<Student*>* getAllStudents() = 0;
    virtual int updateStudent(int, const Student&) = 0;
    virtual int deleteStudent(int) = 0;
    virtual LinkedList<Student*> getStudentsWithoutRoom() = 0;
};