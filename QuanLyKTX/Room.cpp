#include "Room.h"
#include <iostream>

// Constructor
Room::Room(const int& roomID, const string& roomName, const string& roomType,
    const int& capacity, const int& currentOccupancy, const int& floor, const string& building)
    : roomID(roomID), roomName(roomName), roomType(roomType),
    capacity(capacity), currentOccupancy(currentOccupancy), floor(floor), building(building) 
{
}
Room::Room(const Room& r)
    : roomID(r.roomID), roomName(r.roomName), roomType(r.roomType),
    capacity(r.capacity), currentOccupancy(r.currentOccupancy), floor(r.floor), building(r.building)
{
}
Room::~Room() 
{
}




// Getter & Setter
int Room::getRoomID() 
{
    return this->roomID;
}
void Room::setRoomID(const int& roomID) 
{
    this->roomID = roomID;
}
string Room::getRoomName() 
{
    return this->roomName;
}
void Room::setRoomName(const string& roomName) 
{
    this->roomName = roomName;
}
string Room::getRoomType() 
{
    return this->roomType;
}
void Room::setRoomType(const string& roomType) 
{
    this->roomType = roomType;
}
int Room::getCapacity() 
{
    return this->capacity;
}
void Room::setCapacity(const int& capacity) 
{
    this->capacity = capacity;
}
int Room::getCurrentOccupancy() 
{
    return this->currentOccupancy;
}
void Room::setCurrentOccupancy(const int& currentOccupancy) 
{
    this->currentOccupancy = currentOccupancy;
}
int Room::getFloor()
{
    return this->floor;
}
void Room::setFloor(const int& floor)
{
    this->floor = floor;
}
string Room::getBuilding() 
{
    return this->building;
}
void Room::setBuilding(const string& building)
{
    this->building = building;
}
int Room::getIsActive()
{
    return this->isActive;
}
void Room::setIsActive(const bool& isActive)
{
    this->isActive = isActive;
}