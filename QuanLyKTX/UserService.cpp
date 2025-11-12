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
	Student* student = DB::Instance()->getStudentByStudentId(studentId);
	if (student == nullptr) return 3;
	if (updatedStudent.getStudentId() <= 0 || updatedStudent.getFullName() == "") return 4;			// Du Lieu Khong Hop Le
	if (studentId != updatedStudent.getStudentId()) 
	{
		Student* existing = DB::Instance()->getStudentByStudentId(updatedStudent.getStudentId());
		if (existing != nullptr)  return 5;															// Id moi da ton tai
	}
	if (studentId != updatedStudent.getStudentId())
	{
		LinkedList<Contract*>* list = student->getContracts();
		for (ListNode<Contract*>* p = list->getHead(); p != nullptr; p = p->next)
			p->value->setStudentId(updatedStudent.getStudentId());
	}
	DB::Instance()->updateStudent(studentId, updatedStudent);
	return 1;
}

int UserService::deleteStudent(int studentId)
{
	Student* student = DB::Instance()->getStudentByStudentId(studentId);
	if (student == nullptr) return 0;
	LinkedList<Contract*>* contracts = student->getContracts();
	if (contracts != nullptr) 
	{
		for (ListNode<Contract*>* p = contracts->getHead(); p != nullptr; p = p->next) 
		{
			if (p->value != nullptr) 
			{
				Contract* contract = p->value;
				if (contract->isActive())  return 2;
				LinkedList<Invoice*>* invoices = contract->getInvoices();
				if (invoices != nullptr) {
					for (ListNode<Invoice*>* inv = invoices->getHead(); inv != nullptr; inv = inv->next) 
					{
						if (inv->value != nullptr && !inv->value->getisPaid()) return 3;
					}
				}
			}
		}
	}
	DB::Instance()->deleteAccount(*student->getAccount());
	DB::Instance()->deleteStudent(*student);
	return 1;
}