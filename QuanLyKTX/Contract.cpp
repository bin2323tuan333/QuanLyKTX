#include <iostream>
#include "Contract.h"

// Constructor
Contract::Contract(const int& contractId, const int& studentId, const int& roomId, const Date& startDate,
	const Date& endDate, Student* student, Room* room)
	: contractId(contractId), studentId(studentId), roomId(roomId), startDate(endDate), endDate(endDate), student(student), room(room)
{
}
Contract::Contract(const Contract& c)
	: contractId(c.contractId), studentId(c.studentId), roomId(c.roomId), startDate(c.endDate), endDate(c.endDate), student(c.student), room(c.room)
{
}
Contract::~Contract()
{
}


void Contract::AddStudent(Student* student)
{
	this->student = student;
	student->AddContract(this);
}
void Contract::AddRoom(Room* room)
{
	this->room = room;
	room->AddContract(this);
}
void Contract::AddInvoice(Invoice* invoice)
{
	this->invoices.add(invoice);
}
Student* Contract::getStudent()
{
	return this->student;
}
Room* Contract::getRoom()
{
	return this->room;
}
LinkedList<Invoice*>* Contract::getInvoices()
{
	return &this->invoices;
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
int Contract::getStudentId() const
{
	return this->studentId;
}
void Contract::setStudentId(const int& studentId)
{
	this->studentId = studentId;
}
int Contract::getRoomId() const
{
	return this->roomId;
}
void Contract::setRoomId(const int& roomId)
{
	this->roomId = roomId;
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
	this->studentId = other.studentId;
	this->roomId = other.roomId;
	this->startDate = other.startDate;
	this->endDate = other.endDate;
	this->student = other.student;
	this->room = other.room;
	return *this;
}

bool Contract::operator==(const Contract& other)
{
	return(this->contractId == other.contractId &&
		this->studentId == other.studentId &&
		this->roomId == other.roomId &&
		this->startDate == other.startDate &&
		this->endDate == other.endDate &&
		this->student == other.student &&
		this->room == other.room);
}
bool Contract::operator!=(const Contract& other)
{
	return(this->contractId != other.contractId ||
		this->studentId != other.studentId ||
		this->roomId != other.roomId ||
		this->startDate != other.startDate ||
		this->endDate != other.endDate ||
		this->student != other.student ||
		this->room != other.room);
}