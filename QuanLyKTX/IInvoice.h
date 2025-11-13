#pragma once
#include "Date.h"


class IContract;
class IInvoice {
public:
	virtual ~IInvoice();

	virtual void AddContract(IContract*) = 0;
	virtual IContract* getContract() = 0;

	virtual int getTotalAmount() const = 0;

	virtual int getInvoiceId() const = 0;
	virtual void setInvoiceId(const int&) = 0;
	virtual int getContractId() const = 0;
	virtual void setContractId(const int&) = 0;
	virtual int getRoomFee() const = 0;
	virtual void setRoomFee(const int&) = 0;
	virtual int getInternetFee() const = 0;
	virtual void setInternetFee(const int&) = 0;
	virtual int getElectricFee() const = 0;
	virtual void setElectricFee(const int&) = 0;
	virtual int getWaterFee() const = 0;
	virtual void setWaterFee(const int&) = 0;
	virtual Date getCreatedDate() const = 0;
	virtual void setCreatedDate(const Date&) = 0;
	virtual bool getIsPaid() const = 0;
	virtual void setIsPaid(const bool&) = 0;
};