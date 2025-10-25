#include <iostream>
#include "Contract.h"

// Constructor
Contract::Contract(const int& contractID, const int& studentID, const int& roomID, const Date& startDate, const Date& endDate, const int& duration)
	: contractID(contractID), studentID(studentID), roomID(roomID), startDate(endDate), endDate(endDate), duration(duration)
{
}
Contract::Contract(const Contract& c)
	: contractID(c.contractID), startDate(c.startDate), endDate(c.endDate), duration(c.duration), studentID(c.studentID), roomID(c.roomID)
{
}
Contract::~Contract()
{
}



// Getter & Setter
int Contract::getContractID() const
{
	return this->contractID;
}
void Contract::setContractID(const int& contractID)
{
	this->contractID = contractID;
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

int Contract::getDuration()
{
	return this->duration;
}
void Contract::setDuration(const int& duration)
{
	this->duration = duration;
}

int Contract::getStudentID()
{
	return this->studentID;
}
void Contract::setStudentID(const int& studentID)
{
	this->studentID = studentID;
}

int Contract::getRoomID()
{
	return this->roomID;
}
void Contract::setRoomID(const int& roomID)
{
	this->roomID = roomID;
}

Contract& Contract::operator=(const Contract& other)
{
	if (this == &other)
		return *this;

	this->contractID = other.contractID;
	this->studentID = other.studentID;
	this->roomID = other.roomID;
	this->startDate = other.startDate;
	this->endDate = other.endDate;
	this->duration = other.duration;

	return *this;
}

bool Contract::operator==(const Contract& other)
{
	return(this->contractID == other.contractID &&
		this->studentID == other.studentID &&
		this->roomID == other.roomID &&
		this->startDate == other.startDate &&
		this->endDate == other.endDate &&
		this->duration == other.duration);
}