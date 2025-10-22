#include "ContractService.h"

ContractService::ContractService(ContractRepository& contractRepo, StudentRepository& studentRepo)
	:contractRepo(contractRepo), studentRepo(studentRepo)
{
}

ContractService::~ContractService()
{
}

bool ContractService::createContract(const int&, const int&, const int&)
{
	return false;
}

Contract* ContractService::getContractByStudentId(const int& studentID)
{
	return this->contractRepo.Search(studentID);
}
