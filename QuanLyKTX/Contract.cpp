#include <iostream>
#include "Contract.h"

// Constructor
Contract::Contract(const int& contractId, const Date& startDate,
	const Date& endDate, Student* student, Room* room)
	: contractId(contractId), startDate(endDate), endDate(endDate), student(student), room(room)
{
}
Contract::Contract(const Contract& c)
	: contractId(c.contractId), startDate(c.endDate), endDate(c.endDate), student(c.student), room(c.room)
{
}
Contract::~Contract()
{
}


void Contract::AddStudent(Student* student)
{
	this->student = student;
}
void Contract::AddRoom(Room* room)
{
	this->room = room;
}
void Contract::AddInvoice(Invoice* invoice)
{
	this->invoices.add(invoice);
}



// Getter & Setter
int Contract::getContractId() const
{
	return this->contractId;
}
void Contract::setContractId(const int& contractId)
{
	this->contractId = contractId;
}
Date Contract::getStartDate()
{
	return this->startDate;
}
void Contract::setStartDate(const Date& startDate)
{
	this->startDate = startDate;
}
Date Contract::getEndDate()
{
	return this->endDate;
}
void Contract::setEndDate(const Date& endDate)
{
	this->endDate = endDate;
}

bool Contract::isActive()
{
	return Date::getCurrentDay() <= this->endDate;
}

Contract& Contract::operator=(const Contract& other)
{
	if (this == &other)
		return *this;

	this->contractId = other.contractId;
	this->startDate = other.startDate;
	this->endDate = other.endDate;
	this->student = other.student;
	this->room = other.room;
	return *this;
}

bool Contract::operator==(const Contract& other)
{
	return(this->contractId == other.contractId &&
		this->startDate == other.startDate &&
		this->endDate == other.endDate &&
		this->student == other.student &&
		this->room == other.room);
}
bool Contract::operator!=(const Contract& other)
{
	return(this->contractId != other.contractId ||
		this->startDate != other.startDate ||
		this->endDate != other.endDate ||
		this->student != other.student ||
		this->room != other.room);
}