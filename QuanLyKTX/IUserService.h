#pragma once
#include "IStudent.h"
#include "LinkedList.h"

class IUserService
{
public:
    virtual ~IUserService();

    virtual int createStudent(IStudent&) = 0;
    virtual IStudent* getStudentById(const int&) = 0;
    virtual LinkedList<IStudent*>* getAllStudents() = 0;
    virtual int updateStudent(int, const IStudent&) = 0;
    virtual int deleteStudent(int) = 0;
    virtual LinkedList<IStudent*> getStudentsWithoutRoom() = 0;
};