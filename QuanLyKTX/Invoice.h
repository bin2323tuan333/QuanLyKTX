#pragma once
#include "Date.h"
#include "Student.h"
#include "Employee.h"
#include <string>
using namespace std;

class Invoice {
private:
    int invoiceId;
    int roomFee, internetFee, electricFee, waterFee;
    Date createdDate;
    bool isPaid;
    int contractId;
    Contract* contract;
public:
    Invoice(const int& = 0, const int& = 0, const int& = 0, const int& = 0, const int& = 0, const Date & = Date(), const bool& = false, const int& = 0, Contract* = nullptr);
    Invoice(const Invoice&);
    ~Invoice();

    void AddContract(Contract*);
    Contract* getContract();
    int getInvoiceId() const;
    void setInvoiceId(const int&);
    int getContractId() const;
    void setContractId(const int&);
    int getEmployeeId() const;
    void setEmployeeId(const int&);
    int getRoomFee();
    void setRoomFee(const int&);
    int getInternetFee();
    void setInternetFee(const int&);
    int getElectricFee();
    void setElectricFee(const int&);
    int getWaterFee();
    void setWaterFee(const int&);
    int getTotalAmount();
    Date getCreatedDate();
    void setCreatedDate(const Date&);
    bool getisPaid();
    void setisPaid(const bool&);

    Invoice& operator=(const Invoice&);
    bool operator==(const Invoice&);
    bool operator!=(const Invoice&);
};
