#include <iostream>
#include "Contract.h"

// Constructor
Contract::Contract(const int& contractID, const Date& registrationDate, const int& duration, const int& studentID, const int& roomID)
    : contractID(contractID), registrationDate(registrationDate), duration(duration), studentID(studentID), roomID(roomID) 
{
}
Contract::Contract(const Contract& c)
    : contractID(c.contractID), registrationDate(c.registrationDate), duration(c.duration), studentID(c.studentID), roomID(c.roomID) 
{
}
Contract::~Contract() 
{
}



// Getter & Setter
int Contract::getContractID() 
{
    return this->contractID;
}
void Contract::setContractID(const int& contractID) 
{
    this->contractID = contractID;
}
Date Contract::getRegistrationDate() 
{
    return this->registrationDate;
}
void Contract::setRegistrationDate(const Date& registrationDate) 
{
    this->registrationDate = registrationDate;
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




void Contract::show() 
{
    std::cout << this->contractID << " "
        << this->registrationDate << " "
        << this->duration << " "
        << this->studentID << " "
        << this->roomID;
}
