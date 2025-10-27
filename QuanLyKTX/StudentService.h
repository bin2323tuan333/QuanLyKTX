#pragma once
#include "StudentRepository.h"


class StudentService
{
private:
	StudentRepository& studentRepo;

public:
	StudentService(StudentRepository&);
	~StudentService();


	int Add(const Student&);
	Student* SearchByID(const int&);
	LinkedList<Student> GetAll();
	int Update(const Student&);
	int Delete(const Student&);
};


