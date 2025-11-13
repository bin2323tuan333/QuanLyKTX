#pragma once
#include "IContractService.h"
#include "DB.h"

class ContractService : public IContractService
{
private:
    DB* database;
public:
	ContractService();
	~ContractService();

    int createContract(int, int, int) override;
    IContract* getContractById(int) override;
    LinkedList<IContract*>* getContractsByStudent(int) override;
    int getIdAuto() override;
    
    LinkedList<IContract*>* getAllContracts() override;
    LinkedList<IContract*> getActiveContracts() override;
    LinkedList<IContract*> getExpiredContracts() override;
};

