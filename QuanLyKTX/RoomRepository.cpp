#include "RoomRepository.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

RoomRepository::RoomRepository()
{
	this->p = nullptr;
	this->n = 0;
	LoadDataFromFile();
}
RoomRepository::~RoomRepository()
{
	SaveDateToFile();
	delete[] this->p;
}

// Create
void RoomRepository::Add(const Room& room)
{
	Room* temp = new Room[this->n + 1];
	for (int i = 0; i < this->n; i++)
	{
		*(temp + i) = *(this->p + i);
	}
	*(temp + this->n) = room;
	delete[] this->p;
	this->p = temp;
	(this->n)++;
}
void RoomRepository::Insert(const Room& room, const int& index)
{
	if (index<0 || index > this->n)
		return;

	Room* temp = new Room[this->n + 1];
	for (int i = 0; i < index; i++)
	{
		*(temp + i) = *(this->p + i);
	}
	*(temp + index) = room;
	for (int i = index; i < this->n; i++)
	{
		*(temp + i + 1) = *(this->p + i);
	}
	delete[] this->p;
	this->p = temp;
	(this->n)++;
}

// Read
int RoomRepository::IndexOf(const int& roomID)
{
	int index = -1;
	for (int i = 0; i < this->n; i++)
	{
		if (roomID == (this->p + i)->getRoomID())
		{
			index = i;
			break;
		}
	}
	return index;
}
Room* RoomRepository::Search(const int& roomID)
{
	int index = IndexOf(roomID);
	if (index != -1)
	{
		return (this->p + index);
	}
	return nullptr;
}

Room* RoomRepository::getAll()
{
	return this->p;
}
int RoomRepository::getSize()
{
	return this->n;
}

// Update
void RoomRepository::Update(Room& room)
{
    int index = IndexOf(room.getRoomID());
    if (index == -1)
        return;

    (this->p + index)->setRoomID(room.getRoomID());
    (this->p + index)->setRoomName(room.getRoomName());
    (this->p + index)->setRoomType(room.getRoomType());
    (this->p + index)->setCapacity(room.getCapacity());
    (this->p + index)->setCurrentOccupancy(room.getCurrentOccupancy());
    (this->p + index)->setFloor(room.getFloor());
    (this->p + index)->setBuilding(room.getBuilding());
}


// Delete
void RoomRepository::Delete(const int& roomID)
{
	int index = IndexOf(roomID);
	Room* temp = new Room[this->n - 1];
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



void RoomRepository::LoadDataFromFile()
{
	string filename = "Room.txt";
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

		Room temp;

		getline(ss, token, ';'); temp.setRoomID(stoi(token));
		getline(ss, token, ';'); temp.setRoomName(token);
		getline(ss, token, ';'); temp.setRoomType(token);
		getline(ss, token, ';'); temp.setCapacity(stoi(token));
		getline(ss, token, ';'); temp.setCurrentOccupancy(stoi(token));
		getline(ss, token, ';'); temp.setFloor(stoi(token));
		getline(ss, token, ';'); temp.setBuilding(token);
		getline(ss, token, ';'); temp.setIsActive(stoi(token));

		this->Add(temp);
	}
	file.close();
}
void RoomRepository::SaveDateToFile()
{
	string filename = "Room.txt";
	ofstream file(filename);

	if (!file.is_open()) {
		cout << "Khong the mo file: " << filename << "!";
		return;
	}

	for (int i = 0; i < this->n; i++)
	{
		file << (this->p + i)->getRoomID() << ";";
		file << (this->p + i)->getRoomName() << ";";
		file << (this->p + i)->getRoomType() << ";";
		file << (this->p + i)->getCapacity() << ";";
		file << (this->p + i)->getCurrentOccupancy() << ";";
		file << (this->p + i)->getFloor() << ";";
		file << (this->p + i)->getBuilding() << ";";
		file << (this->p + i)->getIsActive() << "\n";
	}
	file.close();
}