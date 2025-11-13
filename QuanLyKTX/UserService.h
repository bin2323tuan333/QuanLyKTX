#pragma once
#include "DB.h"
#include "IUserService.h"

class UserService : public IUserService
{
private:
    DB* database;

public:
    UserService();
    ~UserService();

    int createStudent(IStudent&) override;
    IStudent* getStudentById(const int&) override;
    LinkedList<IStudent*>* getAllStudents() override;
    int updateStudent(int, const IStudent&) override;
    int deleteStudent(int) override;
    LinkedList<IStudent*> getStudentsWithoutRoom() override;
};

