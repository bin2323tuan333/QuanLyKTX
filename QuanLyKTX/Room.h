#pragma once
#include "LinkedList.h"
#include "Contract.h"
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
    string getRoomName();
    void setRoomName(const string&);
    string getRoomType() const;
    void setRoomType(const string&);
    int getCapacity() const;
    void setCapacity(const int&);
    int getCurrentOccupancy();
    int getFloor();
    void setFloor(const int&);
    string getBuilding();
    void setBuilding(const string&);
    bool getIsActive() const;
    void setIsActive(const bool&);

    Room& operator=(const Room&);
    bool operator==(const Room&);
    bool operator!=(const Room&);
};
