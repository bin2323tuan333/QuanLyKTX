#pragma once
#include "DB.h"

class ContractService
{
private:
    DB* database;
public:
	ContractService();
	~ContractService();

    /*Contract* createContract(int studentId, int roomId,
        const std::string& startDate, const std::string& endDate,
        double monthlyFee, const std::string& terms,
        double depositAmount);*/
    Contract* getContractById(int contractId);
    LinkedList<Contract*>* getContractsByStudent(int studentId);
    //Contract* getActiveContractByStudent(int studentId);
    
    //LinkedList<Contract*> getContractsByRoom(int roomId);
    LinkedList<Contract*>* getAllContracts();
    //bool updateContract(int contractId, const Contract& updatedContract);
    //bool deleteContract(int contractId);

    //// Contract status
    LinkedList<Contract*> getActiveContracts();
    LinkedList<Contract*> getExpiredContracts();
    //LinkedList<Contract*> getPendingContracts();
    //LinkedList<Contract*> getExpiringContracts(int daysAhead);

    //// Contract operations
    //bool approveContract(int contractId, int employeeId);
    //bool rejectContract(int contractId, int employeeId, const std::string& reason);
    //bool renewContract(int contractId, const std::string& newEndDate);
    //bool terminateContract(int contractId, const std::string& reason);
    //bool extendContract(int contractId, int additionalMonths);

    //// Deposit management
    //bool recordDeposit(int contractId, double amount, const std::string& paymentDate);
    //bool refundDeposit(int contractId, double amount, const std::string& reason);
    //double getDepositAmount(int contractId);

    //// Validation
    //bool canCreateContract(int studentId, int roomId);
    //bool hasActiveContract(int studentId);

    //// Notifications
    //LinkedList<Contract*> getContractsNeedingRenewal();
    //bool sendRenewalReminder(int contractId);
    //bool sendExpirationNotice(int contractId);

    //// Statistics & Reports
    //int getTotalActiveContracts();
    //int getTotalExpiredContracts();
    //double getTotalContractValue();
    //std::string generateContractReport(int contractId);
};

