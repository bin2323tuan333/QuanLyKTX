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
	LinkedList<Contract> GetAll();
	Contract* GetById(const int&);
	Contract* GetByStudentID(const int&);
	LinkedList<int> GetStudentIdsByRoomId(const int&);
	LinkedList<Contract> GetContractsByStudentId(const int&);

	int GetSize();
};

