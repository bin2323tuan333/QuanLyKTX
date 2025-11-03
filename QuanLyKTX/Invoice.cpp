#include "Invoice.h"


Invoice::Invoice(const int& invoiceId, const int& roomFee, const int& internetFee, const int& electricFee,
	const int& waterFee, const int& totalAmount, const Date & createDate, Contract* contract, Employee* employee)
	: invoiceId(invoiceId), roomFee(roomFee), internetFee(internetFee), electricFee(electricFee), waterFee(waterFee), totalAmount(totalAmount), 
	createdDate(createdDate), contract(contract), employee(employee)
{
}
Invoice::Invoice(const Invoice& iv)
	:invoiceId(iv.invoiceId), roomFee(iv.roomFee), internetFee(iv.internetFee), electricFee(iv.electricFee), waterFee(iv.waterFee), totalAmount(iv.totalAmount),
	createdDate(iv.createdDate), contract(iv.contract), employee(iv.employee)
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
void Invoice::AddEmployee(Employee* employee)
{
	this->employee = employee;
}
Contract* Invoice::getContract()
{
	return this->contract;
}
Employee* Invoice::getEmployee()
{
	return this->employee;
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
int Invoice::getEmployeeId() const
{
	return this->employeeId;
}

void Invoice::setEmployeeId(const int& id)
{
	this->employeeId = id;
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
	return this->totalAmount;
}
void Invoice::setTotalAmount(const int& amount)
{
	this->totalAmount = amount;
}
Date Invoice::getCreatedDate()
{
	return this->createdDate;
}
void Invoice::setCreatedDate(const Date& date)
{
	this->createdDate = date;
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
	this->totalAmount = other.totalAmount;
	this->createdDate = other.createdDate;
	this->contract = other.contract;
	this->employee = other.employee;
	return *this;
}
bool Invoice::operator==(const Invoice& other)
{
	return(this->invoiceId == other.invoiceId &&
		this->roomFee == other.roomFee &&
		this->internetFee == other.internetFee &&
		this->electricFee == other.electricFee &&
		this->waterFee == other.waterFee &&
		this->totalAmount == other.totalAmount &&
		this->createdDate == other.createdDate &&
		this->contract == other.contract &&
		this->employee == other.employee);
}
bool Invoice::operator!=(const Invoice& other)
{
	return(this->invoiceId != other.invoiceId ||
		this->roomFee != other.roomFee ||
		this->internetFee != other.internetFee ||
		this->electricFee != other.electricFee ||
		this->waterFee != other.waterFee ||
		this->totalAmount != other.totalAmount ||
		this->createdDate != other.createdDate ||
		this->contract != other.contract ||
		this->employee != other.employee);
}