#pragma once
#include "Contract.h"
#include "LinkedList.h"


class ContractRepository
{
private:
	string fileName;
	LinkedList<Contract> list;

public:
	ContractRepository(const string&);
	~ContractRepository();

	void loadData();
	void saveData();

	void Add(const Contract&);
	void Update(const Contract&);
	void Delete(const Contract&);
	Contract* GetById(const int&);
	LinkedList<Contract> GetAll();

	int GetSize();
};

