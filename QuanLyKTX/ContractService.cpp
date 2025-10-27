#include "ContractService.h"

ContractService::ContractService(ContractRepository& contractRepo, StudentRepository& studentRepo)
	:contractRepo(contractRepo), studentRepo(studentRepo)
{
}

ContractService::~ContractService()
{
}


int ContractService::Add(const Contract& temp)
{
	this->contractRepo.Add(temp);
	return 1;
}
Contract* ContractService::SearchByID(const int& id)
{
	return this->contractRepo.GetById(id);
}
Contract* ContractService::SearchByStudentID(const int& id)
{
	return this->contractRepo.GetByStudentID(id);
}
LinkedList<Contract> ContractService::GetAll()
{
	return this->contractRepo.GetAll();
}
int ContractService::Update(const Contract& temp)
{
	this->contractRepo.Update(temp);
	return 1;
}
int ContractService::Delete(const Contract& temp)
{
	this->contractRepo.Delete(temp);
	return 1;
}