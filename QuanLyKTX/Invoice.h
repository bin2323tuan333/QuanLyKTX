#pragma once
#include "IInvoice.h"

class IContract;
class Invoice : public virtual IInvoice
{
private:
    int invoiceId;
    int roomFee, internetFee, electricFee, waterFee;
    Date createdDate;
    bool isPaid;
    int contractId;
    IContract* contract;
public:
    Invoice(const int& = 0, const int& = 0, const int& = 0, const int& = 0, const int& = 0, const Date & = Date(), const bool& = false, const int& = 0, IContract* = nullptr);
    Invoice(const Invoice&);
    ~Invoice();

    void AddContract(IContract*) override;
    IContract* getContract() override;
    int getTotalAmount() const override;


    int getInvoiceId() const override;
    void setInvoiceId(const int&) override;
    int getContractId() const override;
    void setContractId(const int&) override;
    int getRoomFee() const override;
    void setRoomFee(const int&) override;
    int getInternetFee() const override;
    void setInternetFee(const int&) override;
    int getElectricFee() const override;
    void setElectricFee(const int&) override;
    int getWaterFee() const override;
    void setWaterFee(const int&) override;
    Date getCreatedDate() const override;
    void setCreatedDate(const Date&) override;
    bool getIsPaid() const override;
    void setIsPaid(const bool&) override;

    IInvoice* clone() const override;

    Invoice& operator=(const Invoice&);
    bool operator==(const Invoice&);
    bool operator!=(const Invoice&);
};
