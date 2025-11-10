#include "Invoice.h"


Invoice::Invoice(const int& invoiceId, 
	const int& roomFee, 
	const int& internetFee, 
	const int& electricFee,
	const int& waterFee, 
	const Date & createDate, 
	const bool& paid,
	const int& contractId,
	Contract* contract)
	: invoiceId(invoiceId), roomFee(roomFee), internetFee(internetFee), electricFee(electricFee), waterFee(waterFee),
	createdDate(createdDate),isPaid(paid), contractId(contractId), contract(contract)
{
}
Invoice::Invoice(const Invoice& iv)
	: invoiceId(iv.invoiceId), roomFee(iv.roomFee), internetFee(iv.internetFee), electricFee(iv.electricFee), waterFee(iv.waterFee),
	createdDate(iv.createdDate), isPaid(iv.isPaid),contractId(iv.contractId), contract(iv.contract)
{
}
Invoice::~Invoice()
{
}

void Invoice::AddContract(Contract* contract)
{
	this->contract = contract;
	contract->AddInvoice(this);
}

Contract* Invoice::getContract()
{
	return this->contract;
}

// Getter & Setter implementations
int Invoice::getInvoiceId() const
{
	return this->invoiceId;
}
void Invoice::setInvoiceId(const int& id)
{
	this->invoiceId = id;
}
int Invoice::getContractId() const
{
	return this->contractId;
}
void Invoice::setContractId(const int& id)
{
	this->contractId = id;
}
int Invoice::getRoomFee()
{
	return this->roomFee;
}
void Invoice::setRoomFee(const int& fee)
{
	this->roomFee = fee;
}
int Invoice::getInternetFee()
{
	return this->internetFee;
}
void Invoice::setInternetFee(const int& fee)
{
	this->internetFee = fee;
}
int Invoice::getElectricFee()
{
	return this->electricFee;
}
void Invoice::setElectricFee(const int& fee)
{
	this->electricFee = fee;
}
int Invoice::getWaterFee()
{
	return this->waterFee;
}
void Invoice::setWaterFee(const int& fee)
{
	this->waterFee = fee;
}
int Invoice::getTotalAmount()
{
	return this->electricFee + this->waterFee + this->internetFee + this->roomFee;
}
Date Invoice::getCreatedDate()
{
	return this->createdDate;
}
void Invoice::setCreatedDate(const Date& date)
{
	this->createdDate = date;
}
bool Invoice::getisPaid()
{
	return this->isPaid;
}
void Invoice::setisPaid(const bool& paid)
{
	this->isPaid = paid;
}

Invoice& Invoice::operator=(const Invoice& other)
{
	if (this == &other)
		return *this;
	this->invoiceId = other.invoiceId;
	this->roomFee = other.roomFee;
	this->internetFee = other.internetFee;
	this->electricFee = other.electricFee;
	this->waterFee = other.waterFee;
	this->createdDate = other.createdDate;
	this->contract = other.contract;
	return *this;
}
bool Invoice::operator==(const Invoice& other)
{
	return(this->invoiceId == other.invoiceId &&
		this->roomFee == other.roomFee &&
		this->internetFee == other.internetFee &&
		this->electricFee == other.electricFee &&
		this->waterFee == other.waterFee &&
		this->createdDate == other.createdDate &&
		this->contract == other.contract);
}
bool Invoice::operator!=(const Invoice& other)
{
	return(this->invoiceId != other.invoiceId ||
		this->roomFee != other.roomFee ||
		this->internetFee != other.internetFee ||
		this->electricFee != other.electricFee ||
		this->waterFee != other.waterFee ||
		this->createdDate != other.createdDate ||
		this->contract != other.contract);
}