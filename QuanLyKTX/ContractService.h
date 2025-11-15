#pragma once
#include "IContractService.h"
#include "DB.h"


class Contract;
class ContractService : public IContractService
{
private:
    DB* database;
public:
	ContractService();
	~ContractService();

    int createContract(int, int, int) override;
    Contract* getContractById(int) override;
    LinkedList<Contract*>* getContractsByStudent(int) override;
    int getIdAuto() override;
    
    LinkedList<Contract*>* getAllContracts() override;
    LinkedList<Contract*> getActiveContracts() override;
    LinkedList<Contract*> getExpiredContracts() override;
};

