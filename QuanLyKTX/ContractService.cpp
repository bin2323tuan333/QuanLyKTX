#include "ContractService.h"
#include "DB.h"

ContractService::ContractService()
{
    this->database = DB::Instance();
}

ContractService::~ContractService()
{
}


LinkedList<Contract*>* ContractService::getAllContracts()
{
    return DB::Instance()->getAllContracts();
}

LinkedList<Contract*> ContractService::getActiveContracts()
{
    LinkedList<Contract*> tempList;
    for (ListNode<Contract*>* p = DB::Instance()->getAllContracts()->getHead(); p != nullptr; p = p->next)
    {
        if (p->value->isActive()) tempList.add(p->value);
    }
    return tempList;
}
LinkedList<Contract*> ContractService::getExpiredContracts()
{
    LinkedList<Contract*> tempList;
    for (ListNode<Contract*>* p = DB::Instance()->getAllContracts()->getHead(); p != nullptr; p = p->next)
    {
        if (!p->value->isActive()) tempList.add(p->value);
    }
    return tempList;
}
Contract* ContractService::getContractById(int contractId)
{
    return DB::Instance()->getContractByContractId(contractId);
}
LinkedList<Contract*>* ContractService::getContractsByStudent(int studentId)
{
    return DB::Instance()->getStudentByStudentId(studentId)->getContracts();
}