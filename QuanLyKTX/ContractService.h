#pragma once
#include "DB.h"

class ContractService
{
private:
    DB* database;
public:
	ContractService();
	~ContractService();

    int createContract(int studentId, int roomId, int cycle);
    Contract* getContractById(int contractId);
    LinkedList<Contract*>* getContractsByStudent(int studentId);
    int getIdAuto();
    
    LinkedList<Contract*>* getAllContracts();
    LinkedList<Contract*> getActiveContracts();
    LinkedList<Contract*> getExpiredContracts();
};

