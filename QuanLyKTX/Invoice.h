#pragma once
#include "Date.h"

class Contract;
class Invoice
{
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
    int getTotalAmount() const;


    int getInvoiceId() const;
    void setInvoiceId(const int&);
    int getContractId() const;
    void setContractId(const int&);
    int getRoomFee() const;
    void setRoomFee(const int&);
    int getInternetFee() const;
    void setInternetFee(const int&);
    int getElectricFee() const;
    void setElectricFee(const int&);
    int getWaterFee() const;
    void setWaterFee(const int&);
    Date getCreatedDate() const;
    void setCreatedDate(const Date&);
    bool getIsPaid() const;
    void setIsPaid(const bool&);
    Invoice& operator=(const Invoice&);
    bool operator==(const Invoice&);
    bool operator!=(const Invoice&);
};
