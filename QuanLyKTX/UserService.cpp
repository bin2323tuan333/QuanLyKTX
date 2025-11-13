#include "UserService.h"
#include "ContractService.h"
#include "AuthService.h"
#include "Student.h"
#include "Contract.h"
#include "Invoice.h"

UserService::UserService()
{
	this->database = DB::Instance();
}
UserService::~UserService()
{
}

LinkedList<IStudent*>* UserService::getAllStudents()
{
	return DB::Instance()->getAllStudents();
}
IStudent* UserService::getStudentById(const int& studentId)
{
	return DB::Instance()->getStudentByStudentId(studentId);
}

int UserService::createStudent(IStudent& student)
{
	// .. Logic
	if (DB::Instance()->getStudentByStudentId(student.getStudentId()) != nullptr)
		return 0;
	DB::Instance()->addStudent(student);
	AuthService auth;
	auth.genAccount(DB::Instance()->getStudentByStudentId(student.getStudentId()));
	return 1;
}

LinkedList<IStudent*> UserService::getStudentsWithoutRoom()
{
	LinkedList<IStudent*> tempList;
	for (ListNode<IStudent*>* p = DB::Instance()->getAllStudents()->getHead(); p != nullptr; p = p->next)
		if (!p->value->hasActiveContract())
			tempList.add(p->value);
	return tempList;
}

int UserService::updateStudent(int studentId, const IStudent& updatedStudent)
{	
	IStudent* student = DB::Instance()->getStudentByStudentId(studentId);
	if (student == nullptr) return 3;
	if (updatedStudent.getStudentId() <= 0 || updatedStudent.getFullName() == "") return 4;			// Du Lieu Khong Hop Le
	if (studentId != updatedStudent.getStudentId()) 
	{
		IStudent* existing = DB::Instance()->getStudentByStudentId(updatedStudent.getStudentId());
		if (existing != nullptr)  return 5;															// Id moi da ton tai
	}
	if (studentId != updatedStudent.getStudentId())
	{
		LinkedList<IContract*>* list = student->getContracts();
		for (ListNode<IContract*>* p = list->getHead(); p != nullptr; p = p->next)
			p->value->setStudentId(updatedStudent.getStudentId());
	}
	DB::Instance()->updateStudent(studentId, updatedStudent);
	return 1;
}

int UserService::deleteStudent(int studentId)
{
	IStudent* student = DB::Instance()->getStudentByStudentId(studentId);
	if (student == nullptr) return 0;
	LinkedList<IContract*>* contracts = student->getContracts();
	if (contracts != nullptr) 
	{
		for (ListNode<IContract*>* p = contracts->getHead(); p != nullptr; p = p->next) 
		{
			if (p->value != nullptr) 
			{
				IContract* contract = p->value;
				if (contract->isActive())  return 2;
				LinkedList<IInvoice*>* invoices = contract->getInvoices();
				if (invoices != nullptr) {
					for (ListNode<IInvoice*>* inv = invoices->getHead(); inv != nullptr; inv = inv->next) 
					{
						if (inv->value != nullptr && !inv->value->getIsPaid()) return 3;
					}
				}
			}
		}
	}
	DB::Instance()->deleteAccount(*student->getAccount());
	DB::Instance()->deleteStudent(*student);
	return 1;
}