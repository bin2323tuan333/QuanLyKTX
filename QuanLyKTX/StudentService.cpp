#include "StudentService.h"

StudentService::StudentService(StudentData& studentData)
	:studentData(studentData)
{
}

StudentService::~StudentService()
{
}


int StudentService::Add(const Student& temp)
{
	this->studentData.Add(temp);
	return 1;
}
Student* StudentService::SearchByID(const int& id)
{
	return this->studentData.GetByStudentId(id);
}
LinkedList<Student*>* StudentService::GetAll()
{
	return this->studentData.getList();
}
int StudentService::Update(const Student& temp)
{
	this->studentData.Update(temp);
	return 1;
}
int StudentService::Delete(const Student& temp)
{
	this->studentData.Delete(temp);
	return 1;
}
