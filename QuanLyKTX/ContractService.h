#pragma once
#include "ContractRepository.h"
#include "StudentRepository.h"

class ContractService {
private:
    ContractRepository& contractRepo;
    StudentRepository& studentRepo;

public:
    ContractService(ContractRepository&, StudentRepository&);
    ~ContractService();

    int Add(const Contract&);
    LinkedList<Contract> GetAll();
    int Update(const Contract&);
    int Delete(const Contract&);

    Contract* SearchByID(const int&);
    LinkedList<Contract> GetContractsByStudentId(const int&);
};