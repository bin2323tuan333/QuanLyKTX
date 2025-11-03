#pragma once
#include "ContractData.h"
#include "StudentData.h"

class ContractService {
private:
    ContractData& contractData;
    StudentData& studentData;

public:
    ContractService(ContractData&, StudentData&);
    ~ContractService();

    //int Add(const Contract&);
    //LinkedList<Contract> GetAll();
    //int Update(const Contract&);
    //int Delete(const Contract&);

    //Contract* SearchByID(const int&);
    //LinkedList<Contract> GetContractsByStudentId(const int&);
};