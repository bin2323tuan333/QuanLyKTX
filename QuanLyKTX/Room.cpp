#include "Room.h"
#include <iostream>

// Constructor
Room::Room(const int& roomID, const string& roomName, const string& roomType,
    const int& capacity, const int& currentOccupancy, const int& buildingID)
    : roomID(roomID), roomName(roomName), roomType(roomType),
    capacity(capacity), currentOccupancy(currentOccupancy), buildingID(buildingID) 
{
}
Room::Room(const Room& r)
    : roomID(r.roomID), roomName(r.roomName), roomType(r.roomType),
    capacity(r.capacity), currentOccupancy(r.currentOccupancy), buildingID(r.buildingID) 
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
int Room::getBuildingID() 
{
    return this->buildingID;
}
void Room::setBuildingID(const int& buildingID) 
{
    this->buildingID = buildingID;
}





void Room::show() {
    cout << this->roomID << " "
        << this->roomName << " "
        << this->roomType << " "
        << this->buildingID;
}
