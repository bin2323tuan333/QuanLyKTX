#pragma once
#include "DB.h"
#include "IUserService.h"


class Student;
class UserService : public IUserService
{
private:
    DB* database;

public:
    UserService();
    ~UserService();

    int createStudent(Student&) override;
    Student* getStudentById(const int&) override;
    LinkedList<Student*>* getAllStudents() override;
    int updateStudent(int, const Student&) override;
    int deleteStudent(int) override;
    LinkedList<Student*> getStudentsWithoutRoom() override;
};

