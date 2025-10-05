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

    bool createContract(const int&, const int&, const int&);
    bool registerContract(const Contract&);
    bool extendContract(const int&, const int&);


    Contract getContractById(int);
    Contract getContractByStudentId(const int&);

    bool isValidRoom(const int&);
};