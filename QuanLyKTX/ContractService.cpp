#include "ContractService.h"

ContractService::ContractService(ContractData& contractData, StudentData& studentData)
	:contractData(contractData), studentData(studentData)
{
}

ContractService::~ContractService()
{
}


int ContractService::Add(const Contract& temp)
{
	this->contractData.Add(temp);
	return 1;
}
Contract* ContractService::SearchByID(const int& id)
{
	return this->contractData.GetByContractId(id);
}
//LinkedList<Contract> ContractService::GetContractsByStudentId(const int& id)
//{
//	return this->contractData.GetContractsByStudentId(id);
//}
LinkedList<Contract*>* ContractService::GetAll()
{
	return this->contractData.getList();
}
int ContractService::Update(const Contract& temp)
{
	this->contractData.Update(temp);
	return 1;
}
int ContractService::Delete(const Contract& temp)
{
	this->contractData.Delete(temp);
	return 1;
}