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
    int currentOccupancy;
    int floor;
    string building;
    bool isActive;

    LinkedList<Contract*> contracts;
public:
    // Constructor, Copy constructor, Destructor
    Room(
        const int& = 0, 
        const string & = "", 
        const string & = "", 
        const int& = 0, 
        const int& = 0, 
        const int& = 0, 
        const string& = "",
        const bool& = true
    );
    Room(const Room&);
    ~Room();

    void AddContract(Contract*);
    LinkedList<Contract*>* getContracts();
    bool isAvailable();
    bool isVacant();

    // Getter & Setter
    int getRoomId() const;
    void setRoomId(const int&);

    string getRoomName();
    void setRoomName(const string&);

    string getRoomType();
    void setRoomType(const string&);

    int getCapacity();
    void setCapacity(const int&);

    int getCurrentOccupancy();
    void setCurrentOccupancy(const int&);

    int getFloor();
    void setFloor(const int&);

    string getBuilding();
    void setBuilding(const string&);

    bool getIsActive();
    void setIsActive(const bool&);


    Room& operator=(const Room&);
    bool operator==(const Room&);
    bool operator!=(const Room&);
};
