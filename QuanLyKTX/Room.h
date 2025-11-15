#pragma once
#include "LinkedList.h"
#include <string>
using namespace std;

class Contract;
class Room
{
private:
    int roomId;
    string roomName;
    string roomType;
    int capacity;
    int floor;
    string building;
    bool isActive;
    LinkedList<Contract*> contracts;
public:
    Room(const int& = 0, const string & = "", const string & = "", const int& = 0, const int& = 0, const string& = "", const bool& = true);
    Room(const Room&);
    ~Room();

    void AddContract(Contract*);
    LinkedList<Contract*>* getContracts();
    bool isAvailable();
    bool isVacant();

    int getRoomId() const;
    void setRoomId(const int&);
    string getRoomName() const;
    void setRoomName(const string&);
    string getRoomType() const;
    void setRoomType(const string&);
    int getCapacity() const;
    void setCapacity(const int&);
    int getFloor() const;
    void setFloor(const int&);
    string getBuilding() const;
    void setBuilding(const string&);
    bool getIsActive() const;
    void setIsActive(const bool&);
    int getCurrentOccupancy() const;
    Room& operator=(const Room&);
    bool operator==(const Room&);
    bool operator!=(const Room&);
};
