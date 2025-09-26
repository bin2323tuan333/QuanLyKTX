#include <iostream>
#include "Building.h"


Building::Building(const int& buildingID, const string& buildingName, const int& numberOfRooms)
	: buildingID(buildingID), buildingName(buildingName), numberOfRooms(numberOfRooms)
{
}
Building::Building(const Building& t)
	: buildingID(t.buildingID), buildingName(t.buildingName), numberOfRooms(t.numberOfRooms)
{
}
Building::~Building() {
}


// Getter & Setter
int Building::getBuildingID() 
{
    return this->buildingID;
}
void Building::setBuildingID(const int& buildingID) 
{
    this->buildingID = buildingID;
}
string Building::getBuildingName() 
{
    return this->buildingName;
}
void Building::setBuildingName(const string& buildingName) 
{
    this->buildingName = buildingName;
}
int Building::getNumberOfRooms() 
{
    return this->numberOfRooms;
}
void Building::setNumberOfRooms(const int& numberOfRooms) 
{
    this->numberOfRooms = numberOfRooms;
}




void Building::show()
{
	cout << this->buildingID << " " << this->buildingName << " " << this->numberOfRooms << " ";
}