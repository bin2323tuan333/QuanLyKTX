#pragma once
#include "LinkedList.h"


class IContract;
class IContractService
{
public:
    virtual ~IContractService();

    virtual int createContract(int, int, int) = 0;
    virtual int getIdAuto() = 0;
    virtual IContract* getContractById(int) = 0;

    virtual LinkedList<IContract*>* getContractsByStudent(int) = 0;
    virtual LinkedList<IContract*>* getAllContracts() = 0;
    virtual LinkedList<IContract*> getActiveContracts() = 0;
    virtual LinkedList<IContract*> getExpiredContracts() = 0;
};