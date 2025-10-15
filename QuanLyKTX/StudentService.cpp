#include "StudentService.h"

StudentService::StudentService(StudentRepository& studentRepo)
	:studentRepo(studentRepo)
{
}

StudentService::~StudentService()
{
}


Student* StudentService::SearchByID(const int& studentID)
{
	Student* student = this->studentRepo.Search(studentID);
	return student;
}

