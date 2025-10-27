#include "ContractRepository.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

ContractRepository::ContractRepository(const string& fileName)
	:fileName(fileName)
{
	this->loadData();

}
ContractRepository::~ContractRepository()
{
	this->saveData();
}


void ContractRepository::loadData()
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
		Contract temp;

		getline(ss, token, ';'); temp.setContractID(stoi(token));
		getline(ss, token, ';'); temp.setDuration(stoi(token));

		int d, m, y;
		char sep1, sep2;
		getline(ss, token, ';');
		stringstream dateStream(token);
		dateStream >> d >> sep1 >> m >> sep2 >> y;
		temp.setStartDate(Date(d, m, y));

		getline(ss, token, ';');
		stringstream date(token);
		date >> d >> sep1 >> m >> sep2 >> y;
		temp.setEndDate(Date(d, m, y));

		getline(ss, token, ';'); temp.setRoomID(stoi(token));
		getline(ss, token, ';'); temp.setStudentID(stoi(token));

		this->list.add(temp);
	}
	file.close();
}
void ContractRepository::saveData()
{
	ofstream file(this->fileName);
	if (!file.is_open())
		return;

	for (ListNode<Contract>* p = this->list.getHead(); p != nullptr; p = p->next)
	{
		file << p->value.getContractID() << ";";
		file << p->value.getDuration() << ";";
		file << p->value.getStartDate() << ";";
		file << p->value.getEndDate() << ";";
		file << p->value.getRoomID() << ";";  
		file << p->value.getStudentID() << "\n";
	}
	file.close();
}

void ContractRepository::Add(const Contract& contract)
{
	this->list.add(contract);
}

void ContractRepository::Delete(const Contract& contract)
{
	Contract* temp = this->GetById(contract.getContractID());
	if (temp == nullptr) return;
	this->list.remove(*temp);
}
void ContractRepository::Update(const Contract& contract)
{
	Contract* temp = this->GetById(contract.getContractID());
	*temp = contract;
}
LinkedList<Contract> ContractRepository::GetAll()
{
	return this->list;
}
Contract* ContractRepository::GetById(const int& contractID)
{
	for (ListNode<Contract>* p = this->list.getHead(); p != nullptr; p = p->next)
	{
		if (p->value.getContractID() == contractID)
			return &(p->value);
	}
	return nullptr;
}
Contract* ContractRepository::GetByStudentID(const int& studentID)
{
	for (ListNode<Contract>* p = this->list.getHead(); p != nullptr; p = p->next)
	{
		if (p->value.getStudentID() == studentID)
			return &(p->value);
	}
	return nullptr;
}
LinkedList<int> ContractRepository::GetStudentIdsByRoomId(const int& roomID)
{
	LinkedList<int> list;
	for (ListNode<Contract>* p = this->list.getHead(); p != nullptr; p = p->next)
	{
		if (p->value.getRoomID() == roomID)
			list.add(p->value.getStudentID());
	}
	return list;
}

int ContractRepository::GetSize()
{
	return this->list.getSize();
}