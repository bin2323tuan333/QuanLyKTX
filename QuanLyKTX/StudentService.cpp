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


bool StudentService::Add(Student& student)
{

	if (!(student.getGender() == "Nam" ||
		student.getGender() == "Nu"))
		return false;
	if (!(student.getDateOfBirth()).isValid())
		return false;
	this->studentRepo.Add(student);
	this->studentRepo.SaveDateToFile();
	return true;
}

bool StudentService::Delete(Student& student)
{
	this->studentRepo.Delete(student.getStudentID());
	this->studentRepo.SaveDateToFile();
	if (this->studentRepo.Search(student.getStudentID()) == nullptr)
		return true;
	else
		return false;
}
