#pragma once
#include <string>
using namespace std;




class Room {
private:
    int roomID;
    string roomName, roomType;
    int capacity;
    int currentOccupancy;
    int floor;
    string building;
    bool isActive;
    
public:
    // Constructor, Copy constructor, Destructor
    Room(const int& = 0, const string & = "", const string & = "", const int& = 0, const int& = 0, const int& = 0, const string& = "");
    Room(const Room&);
    ~Room();

    // Getter & Setter
    int getRoomID();
    void setRoomID(const int&);

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
};
