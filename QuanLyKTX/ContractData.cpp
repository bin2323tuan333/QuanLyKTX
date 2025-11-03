#include "ContractData.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

ContractData::ContractData(const string& fileName)
	:fileName(fileName)
{
	this->loadData();

}
ContractData::~ContractData()
{
	this->saveData();
}


void ContractData::loadData()
{
	ifstream file(this->fileName);
	if (!file.is_open())
		return;
	string line;

	while (getline(file, line))
	{
		if (line.empty()) continue;
		stringstream ss(line);
		string token;
		Contract* contract = new Contract();
		getline(ss, token, ';'); contract->setContractId(stoi(token));
		getline(ss, token, ';'); contract->setStudentId(stoi(token));
		getline(ss, token, ';'); contract->setRoomId(stoi(token));
		getline(ss, token, ';'); contract->setStartDate(Date::stringToDate(token));
		getline(ss, token, ';'); contract->setEndDate(Date::stringToDate(token));
		this->list.add(contract);
		this->mapContractId.insert(contract->getContractId(), contract);
	}
	file.close();
}
void ContractData::saveData()
{
	ofstream file(this->fileName);
	if (!file.is_open())
		return;
	for (ListNode<Contract*>* p = this->list.getHead(); p != nullptr; p = p->next)
	{
		file << p->value->getContractId() << ";";
		file << p->value->getStudentId() << ";";
		file << p->value->getRoomId() << ";";
		file << p->value->getStartDate() << ";";
		file << p->value->getEndDate() << endl;
	}
	file.close();
}

LinkedList<Contract*>* ContractData::getList()
{
	return &(this->list);
}

void ContractData::Add(const Contract& contract)
{
	Contract* con = new Contract(contract);
	this->list.add(con);
	this->mapContractId.insert(con->getContractId(), con);
}
void ContractData::Delete(const Contract& contract)
{
	Contract* contractToDelete = GetByContractId(contract.getContractId());
	if (contractToDelete == nullptr)
		return;
	this->list.remove(contractToDelete);
	this->mapContractId.remove(contractToDelete->getContractId());
}
void ContractData::Update(const Contract& contract)
{
	Contract* contractToUpdate = GetByContractId(contract.getContractId());
	if (contractToUpdate == nullptr)
		return;
	*contractToUpdate = contract;
}
Contract* ContractData::GetByContractId(const int& contractID)
{
	Contract** contract = this->mapContractId.search(contractID);
	if (contract == nullptr) 
		return nullptr;
	return *contract;
}
Contract* ContractData::GetByStudentID(const int& studentID)
{
	for (ListNode<Contract*>* p = this->list.getHead(); p != nullptr; p = p->next)
	{
		if (p->value->getStudentId() == studentID) 
			return p->value;
	}
	return nullptr;
}
//LinkedList<int> ContractData::GetStudentIdsByRoomId(const int& roomID)
//{
//
//}
//LinkedList<Contract> ContractData::GetContractsByStudentId(const int& studentID)
//{
//
//}
//
int ContractData::GetSize()
{
	return this->list.getSize();
}