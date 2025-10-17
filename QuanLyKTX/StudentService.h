#pragma once
#include "StudentRepository.h"


class StudentService
{
private:
	StudentRepository& studentRepo;

public:
	StudentService(StudentRepository&);
	~StudentService();


	Student* SearchByID(const int&);

	bool Add(Student&);
	bool Delete(Student&);
	bool Update(Student&);
};


