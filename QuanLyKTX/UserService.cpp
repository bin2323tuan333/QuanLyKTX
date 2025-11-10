#include "UserService.h"
#include "ContractService.h"
#include "AuthService.h"

UserService::UserService()
{
	this->database = DB::Instance();
}
UserService::~UserService()
{
}

LinkedList<Student*>* UserService::getAllStudents()
{
	return DB::Instance()->getAllStudents();
}
Student* UserService::getStudentById(const int& studentId)
{
	return DB::Instance()->getStudentByStudentId(studentId);
}

int UserService::createStudent(Student& student)
{
	// .. Logic
	if (DB::Instance()->getStudentByStudentId(student.getStudentId()) != nullptr)
		return 0;
	DB::Instance()->addStudent(student);
	AuthService auth;
	auth.genAccount(DB::Instance()->getStudentByStudentId(student.getStudentId()));
	return 1;
}

LinkedList<Student*> UserService::getStudentsWithoutRoom()
{
	LinkedList<Student*> tempList;
	for (ListNode<Student*>* p = DB::Instance()->getAllStudents()->getHead(); p != nullptr; p = p->next)
		if (!p->value->hasActiveContract())
			tempList.add(p->value);
	return tempList;
}

int UserService::updateStudent(int studentId, const Student& updatedStudent)
{
	// check logic.
	Student* student = DB::Instance()->getStudentByStudentId(studentId);
	if (studentId != updatedStudent.getStudentId())
	{
		LinkedList<Contract*>* list = student->getContracts();
		for (ListNode<Contract*>* p = list->getHead(); p != nullptr; p = p->next)
			p->value->setStudentId(studentId);
	}
	DB::Instance()->updateStudent(updatedStudent);
	return 1;
}

bool UserService::deleteStudent(int studentId)
{
	Student* student = DB::Instance()->getStudentByStudentId(studentId);
	if (student == nullptr) return false;
	DB::Instance()->deleteStudent(*student);
	return true;
}