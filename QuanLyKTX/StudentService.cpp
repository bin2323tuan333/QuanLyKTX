#include "StudentService.h"

StudentService::StudentService(StudentData& studentData)
	:studentData(studentData)
{
}

StudentService::~StudentService()
{
}


//int StudentService::Add(const Student& temp)
//{
//	this->studentRepo.Add(temp);
//	return 1;
//}
//Student* StudentService::SearchByID(const int& id)
//{
//	return this->studentRepo.GetById(id);
//}
//LinkedList<Student> StudentService::GetAll()
//{
//	return this->studentRepo.GetAll();
//}
//int StudentService::Update(const Student& temp)
//{
//	this->studentRepo.Update(temp);
//	return 1;
//}
//int StudentService::Delete(const Student& temp)
//{
//	this->studentRepo.Delete(temp);
//	return 1;
//}
