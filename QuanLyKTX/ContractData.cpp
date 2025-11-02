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
		getline(ss, token, ';'); contract->setStartDate(Date::stringToDate(token));
		getline(ss, token, ';'); contract->setEndDate(Date::stringToDate(token));
		this->list.add(contract);
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
		file << p->value->getStartDate() << ";";
		file << p->value->getEndDate() << endl;
	}
	file.close();
}

//void ContractData::Add(const Contract& contract)
//{
//
//}
//
//void ContractData::Delete(const Contract& contract)
//{
//
//}
//void ContractData::Update(const Contract& contract)
//{
//
//}
//LinkedList<Contract> ContractData::GetAll()
//{
//}
//Contract* ContractData::GetById(const int& contractID)
//{
//
//}
//Contract* ContractData::GetByStudentID(const int& studentID)
//{
//
//}
//LinkedList<int> ContractData::GetStudentIdsByRoomId(const int& roomID)
//{
//
//}
//LinkedList<Contract> ContractData::GetContractsByStudentId(const int& studentID)
//{
//
//}
//
//int ContractData::GetSize()
//{
//	return this->list.getSize();
//}