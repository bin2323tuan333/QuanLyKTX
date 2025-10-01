#include "BuildingRepository.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

BuildingRepository::BuildingRepository()
{
    this->p = nullptr;
    this->n = 0;
}
BuildingRepository::~BuildingRepository()
{
    delete[] this->p;
}

void BuildingRepository::Add(const Building& building)
{
    Building* temp = new Building[this->n + 1];
    for (int i = 0; i < this->n; i++)
    {
        *(temp + i) = *(this->p + i);
    }
    *(temp + this->n) = building;
    delete[] this->p;
    this->p = temp;
    (this->n)++;
}
void BuildingRepository::Insert(const Building& building, const int& index)
{
    if (index < 0 || index > this->n)
        return;

    Building* temp = new Building[this->n + 1];
    for (int i = 0; i < index; i++)
    {
        *(temp + i) = *(this->p + i);
    }
    *(temp + index) = building;
    for (int i = index; i < this->n; i++)
    {
        *(temp + i + 1) = *(this->p + i);
    }
    delete[] this->p;
    this->p = temp;
    (this->n)++;
}

void BuildingRepository::Show()
{
    for (int i = 0; i < this->n; i++)
    {
        (this->p + i)->show();
        cout << endl;
    }
}
int BuildingRepository::IndexOf(const int& buildingID)
{
    int index = -1;
    for (int i = 0; i < this->n; i++)
    {
        if (buildingID == (this->p + i)->getBuildingID())
        {
            index = i;
            break;
        }
    }
    return index;
}
Building BuildingRepository::Search(const int& buildingID)
{
    int index = IndexOf(buildingID);
    if (index != -1)
    {
        return *(this->p + index);
    }
    return Building();
}

void BuildingRepository::Update(Building& building)
{
    int index = IndexOf(building.getBuildingID());
    if (index == -1)
        return;

    (this->p + index)->setBuildingName(building.getBuildingName());
    (this->p + index)->setNumberOfRooms(building.getNumberOfRooms());
}

void BuildingRepository::Delete(const int& buildingID)
{
    int index = IndexOf(buildingID);
    if (index == -1) return;

    Building* temp = new Building[this->n - 1];
    for (int i = 0; i < index; i++)
    {
        *(temp + i) = *(this->p + i);
    }
    for (int i = index; i < this->n - 1; i++)
    {
        *(temp + i) = *(this->p + i + 1);
    }
    delete[] this->p;
    this->p = temp;
    (this->n)--;
}


void BuildingRepository::LoadDataFromFile()
{
    string filename = "Building.txt";
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Khong the mo file " << filename << "!";
        return;
    }
    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        string token;

        Building temp;

        getline(ss, token, ';'); temp.setBuildingID(stoi(token));
        getline(ss, token, ';'); temp.setBuildingName(token);
        getline(ss, token, ';'); temp.setNumberOfRooms(stoi(token));
        this->Add(temp);
    }
    file.close();
}
void BuildingRepository::SaveDateToFile()
{
    string filename = "Building.txt";
    ofstream file(filename);

    if (!file.is_open()) {
        cout << "Khong the mo file: " << filename << "!";
        return;
    }

    for (int i = 0; i < this->n; i++)
    {
        file << (this->p + i)->getBuildingID() << ";";
        file << (this->p + i)->getBuildingName() << ";";
        file << (this->p + i)->getNumberOfRooms() << "\n";
    }
    file.close();
}