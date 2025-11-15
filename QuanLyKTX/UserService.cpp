#include "UserService.h"
#include "ContractService.h"
#include "AuthService.h"
#include "Student.h"
#include "Contract.h"
#include "Invoice.h"
#include "Account.h"

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
	Student* student = DB::Instance()->getStudentByStudentId(studentId);
	if (student == nullptr) return nullptr;
	return student;
}

int UserService::createStudent(Student& student)
{
	if (student.getStudentId() == 0)
		return 2;
	if (DB::Instance()->getStudentByStudentId(student.getStudentId()) != nullptr)
		return 0;
	DB::Instance()->addStudent(student);
	Student* stu = DB::Instance()->getStudentByStudentId(student.getStudentId());
	AuthService auth;
	auth.genAccount(stu);
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
		{
			p->value->setStudentId(updatedStudent.getStudentId());
		}
		Account* account = student->getAccount();
		account->setUsername(to_string(updatedStudent.getStudentId()));
	}
	student->setUserId(updatedStudent.getUserId());
	student->setClassName(updatedStudent.getClassName());
	student->setDateOfBirth(updatedStudent.getDateOfBirth());
	student->setEmail(updatedStudent.getEmail());
	student->setFaculty(updatedStudent.getFaculty());
	student->setFullName(updatedStudent.getFullName());
	student->setGender(updatedStudent.getGender());
	student->setPhoneNumber(updatedStudent.getPhoneNumber());
	student->setStudentId(updatedStudent.getStudentId());
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