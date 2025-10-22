#include "Invoice.h"


Invoice::Invoice(const int& invoiceID, const int& studentID, const int& employeeID, const int& month, const int& year, const int& roomFee,
	const int& internetFee, const int& electricFee, const int& waterFee, const int& totalAmount, const Date& createdDate)
	: invoiceID(invoiceID), studentID(studentID), employeeID(employeeID), month(month), year(year), roomFee(roomFee),
	internetFee(internetFee), electricFee(electricFee), waterFee(waterFee), totalAmount(totalAmount), createdDate(createdDate)
{
}
Invoice::Invoice(const Invoice& iv)
	:invoiceID(iv.invoiceID), studentID(iv.studentID), employeeID(iv.employeeID), month(iv.month), year(iv.year), roomFee(iv.roomFee),
	internetFee(iv.internetFee), electricFee(iv.electricFee), waterFee(iv.waterFee), totalAmount(iv.totalAmount), createdDate(iv.createdDate)
{
}
Invoice::~Invoice()
{
}

// Getter & Setter implementations
int Invoice::getInvoiceID() {
	return this->invoiceID;
}

void Invoice::setInvoiceID(const int& id)
{
	this->invoiceID = id;
}

int Invoice::getStudentID()
{
	return this->studentID;
}

void Invoice::setStudentID(const int& id)
{
	this->studentID = id;
}

int Invoice::getEmployeeID()
{
	return this->employeeID;
}

void Invoice::setEmployeeID(const int& id)
{
	this->employeeID = id;
}

int Invoice::getMonth()
{
	return this->month;
}

void Invoice::setMonth(const int& m)
{
	this->month = m;
}

int Invoice::getYear()
{
	return this->year;
}

void Invoice::setYear(const int& y)
{
	this->year = y;
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

	this->invoiceID = other.invoiceID;
	this->studentID = other.studentID;
	this->employeeID = other.employeeID;
	this->month = other.month;
	this->year = other.year;
	this->roomFee = other.roomFee;
	this->internetFee = other.internetFee;
	this->electricFee = other.electricFee;
	this->waterFee = other.waterFee;
	this->totalAmount = other.totalAmount;
	this->createdDate = other.createdDate;
	return *this;
}
bool Invoice::operator==(const Invoice& other)
{
	return(this->invoiceID == other.invoiceID &&
		this->studentID == other.studentID &&
		this->employeeID == other.employeeID &&
		this->month == other.month &&
		this->year == other.year &&
		this->roomFee == other.roomFee &&
		this->internetFee == other.internetFee &&
		this->electricFee == other.electricFee &&
		this->waterFee == other.waterFee &&
		this->totalAmount == other.totalAmount &&
		this->createdDate == other.createdDate);
}