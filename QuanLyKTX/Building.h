#pragma once
#include <string>
using namespace std;




class Building {
private:
    int buildingID;
    string buildingName;
    int numberOfRooms;

public:
    Building(const int& = 0, const string& = "", const int& = 0);
    Building(const Building&);
    ~Building();

    // Getter & Setter
    int getBuildingID();
    void setBuildingID(const int&);

    string getBuildingName();
    void setBuildingName(const string&);

    int getNumberOfRooms();
    void setNumberOfRooms(const int&);


    void show();
};
