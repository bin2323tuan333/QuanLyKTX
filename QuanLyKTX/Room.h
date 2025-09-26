#pragma once
#include <string>
using namespace std;




class Room {
private:
    int roomID;
    string roomName;
    string roomType;
    int capacity;
    int currentOccupancy;
    int buildingID;

public:
    // Constructor, Copy constructor, Destructor
    Room(const int& = 0, const string & = "", const string & = "", const int& = 0, const int& = 0, const int& = 0);
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

    int getBuildingID();
    void setBuildingID(const int&);



    void show();
};
