#pragma once
#include <string>
#include "LinkedList.h"
#include "Contract.h"
using namespace std;

class IRoom {
public:
    virtual ~IRoom() = default;

    virtual void AddContract(Contract*) = 0;
    virtual LinkedList<Contract*>* getContracts() = 0;
    virtual bool isAvailable() = 0;
    virtual bool isVacant() = 0;
    virtual int getCurrentOccupancy() const = 0;


    virtual int getRoomId() const = 0;
    virtual void setRoomId(const int&) = 0;
    virtual string getRoomName() const = 0;
    virtual void setRoomName(const string&) = 0;
    virtual string getRoomType() const = 0;
    virtual void setRoomType(const string&) = 0;
    virtual int getCapacity() const = 0;
    virtual void setCapacity(const int&) = 0;
    virtual int getFloor() const = 0;
    virtual void setFloor(const int&) = 0;
    virtual string getBuilding() const = 0;
    virtual void setBuilding(const string&) = 0;
    virtual bool getIsActive() const = 0;
    virtual void setIsActive(const bool&) = 0;
};


IRoom::~IRoom()
{
}