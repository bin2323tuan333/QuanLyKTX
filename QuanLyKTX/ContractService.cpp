#include "ContractService.h"
#include "DB.h"
#include "Room.h"
#include "Student.h"
#include "Contract.h"

ContractService::ContractService()
{
	this->database = DB::Instance();
}

ContractService::~ContractService()
{
}


LinkedList<Contract*>* ContractService::getAllContracts()
{
	return DB::Instance()->getAllContracts();
}

LinkedList<Contract*> ContractService::getActiveContracts()
{
	LinkedList<Contract*> tempList;
	for (ListNode<Contract*>* p = DB::Instance()->getAllContracts()->getHead(); p != nullptr; p = p->next)
	{
		if (p->value->isActive()) tempList.add(p->value);
	}
	return tempList;
}
LinkedList<Contract*> ContractService::getExpiredContracts()
{
	LinkedList<Contract*> tempList;
	for (ListNode<Contract*>* p = DB::Instance()->getAllContracts()->getHead(); p != nullptr; p = p->next)
	{
		if (!p->value->isActive()) tempList.add(p->value);
	}
	return tempList;
}
Contract* ContractService::getContractById(int contractId)
{
	return DB::Instance()->getContractByContractId(contractId);
}
LinkedList<Contract*>* ContractService::getContractsByStudent(int studentId)
{
	Student* student = DB::Instance()->getStudentByStudentId(studentId);
	if (student == nullptr)
		return nullptr;
	return student->getContracts();
}
int ContractService::createContract(int studentId, int roomId, int cycle)
{
	Student* student = DB::Instance()->getStudentByStudentId(studentId);
	Room* room = DB::Instance()->getRoomByRoomId(roomId);
	if (student == nullptr || room == nullptr)
		return 0;
	LinkedList<Contract*>* list = student->getContracts();
	if (room->getCurrentOccupancy() == room->getCapacity())
		return 2;
	string checkGender = student->getGender() ? "Nam" : "Nu";
	if (checkGender != room->getRoomType())
		return 2;
	Contract* contract = new Contract();
	contract->setContractId(this->getIdAuto());
	contract->setStudentId(studentId);
	contract->setRoomId(roomId);
	bool check = true;
	for (ListNode<Contract*>* p = list->getHead(); p != nullptr; p = p->next)
	{
		if (p->value->isActive())
		{
			contract->setStartDate(p->value->getEndDate());
			check = false;
			break;
		}
	}
	if (check)
		contract->setStartDate(Date::getCurrentDay());
	contract->setEndDate(Date::increaseDate(contract->getStartDate(), cycle));
	DB::Instance()->addContract(*contract);
	delete contract;
	return 1;
}
int ContractService::getIdAuto()
{
	int maxId = 0;
	for (ListNode<Contract*>* p = DB::Instance()->getAllContracts()->getHead(); p != nullptr; p = p->next)
	{
		if (p->value->getContractId() > maxId) maxId = p->value->getContractId();
	}
	return ++maxId;
}