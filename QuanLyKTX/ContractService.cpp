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


LinkedList<IContract*>* ContractService::getAllContracts()
{
	return DB::Instance()->getAllContracts();
}

LinkedList<IContract*> ContractService::getActiveContracts()
{
	LinkedList<IContract*> tempList;
	for (ListNode<IContract*>* p = DB::Instance()->getAllContracts()->getHead(); p != nullptr; p = p->next)
	{
		if (p->value->isActive()) tempList.add(p->value);
	}
	return tempList;
}
LinkedList<IContract*> ContractService::getExpiredContracts()
{
	LinkedList<IContract*> tempList;
	for (ListNode<IContract*>* p = DB::Instance()->getAllContracts()->getHead(); p != nullptr; p = p->next)
	{
		if (!p->value->isActive()) tempList.add(p->value);
	}
	return tempList;
}
IContract* ContractService::getContractById(int contractId)
{
	return DB::Instance()->getContractByContractId(contractId);
}
LinkedList<IContract*>* ContractService::getContractsByStudent(int studentId)
{
	return DB::Instance()->getStudentByStudentId(studentId)->getContracts();
}
int ContractService::createContract(int studentId, int roomId, int cycle)
{
	IStudent* student = DB::Instance()->getStudentByStudentId(studentId);
	IRoom* room = DB::Instance()->getRoomByRoomId(roomId);
	if (student == nullptr || room == nullptr)
		return 0;
	LinkedList<IContract*>* list = student->getContracts();

	if (room->getCurrentOccupancy() == room->getCapacity())
		return 2;
	string checkGender = student->getGender() ? "Nam" : "Nu";
	if (checkGender != room->getRoomType())
		return 2;
	Contract contract;
	contract.setContractId(this->getIdAuto());
	contract.setStudentId(studentId);
	contract.setRoomId(roomId);
	bool check = true;
	for (ListNode<IContract*>* p = list->getHead(); p != nullptr; p = p->next)
	{
		if (p->value->isActive())
		{
			contract.setStartDate(p->value->getEndDate());
			check = false;
			break;
		}
	}
	if (check)
		contract.setStartDate(Date::getCurrentDay());
	contract.setEndDate(Date::increaseDate(contract.getStartDate(), cycle));
	DB::Instance()->addContract(contract);
	return 1;
}
int ContractService::getIdAuto()
{
	int maxId = 0;
	for (ListNode<IContract*>* p = DB::Instance()->getAllContracts()->getHead(); p != nullptr; p = p->next)
	{
		if (p->value->getContractId() > maxId) maxId = p->value->getContractId();
	}
	return ++maxId;
}