#pragma once
#include "Contract.h"
#include "LinkedList.h"
#include "HashTable.h"


class ContractData
{
private:
	string fileName;
	LinkedList<Contract*> list;
	HashTable<int, Contract*> mapContractId;

public:
	ContractData(const string&);
	~ContractData();

	void loadData();
	void saveData();
	LinkedList<Contract*>* getList();

	void Add(const Contract&);
	void Update(const Contract&);
	void Delete(const Contract&);
	Contract* GetByContractId(const int&);
	Contract* GetByStudentID(const int&);
	//LinkedList<int> GetStudentIdsByRoomId(const int&);
	//LinkedList<Contract> GetContractsByStudentId(const int&);

	int GetSize();
};

