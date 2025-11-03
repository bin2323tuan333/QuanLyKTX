#pragma once
#include "StudentData.h"


class StudentService
{
private:
	StudentData& studentData;

public:
	StudentService(StudentData&);
	~StudentService();


	//int Add(const Student&);
	//Student* SearchByID(const int&);
	//LinkedList<Student> GetAll();
	//int Update(const Student&);
	//int Delete(const Student&);
};


