#pragma once
#include "LinkedList.h"


class Contract;
class IContractService
{
public:
    virtual ~IContractService();

    virtual int createContract(int, int, int) = 0;
    virtual int getIdAuto() = 0;
    virtual Contract* getContractById(int) = 0;

    virtual LinkedList<Contract*>* getContractsByStudent(int) = 0;
    virtual LinkedList<Contract*>* getAllContracts() = 0;
    virtual LinkedList<Contract*> getActiveContracts() = 0;
    virtual LinkedList<Contract*> getExpiredContracts() = 0;
};