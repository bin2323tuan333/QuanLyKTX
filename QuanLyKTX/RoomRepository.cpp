#include "RoomRepository.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

RoomRepository::RoomRepository(const string& fileName)
	:fileName(fileName)
{
	this->loadData();
}
RoomRepository::~RoomRepository()
{
	this->saveData();
}

void RoomRepository::loadData()
{
	ifstream file(this->fileName);
	if (!file.is_open())
		return;
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
		getline(ss, token); temp.setIsActive(stoi(token));

		this->list.add(temp);
	}
	file.close();
}
void RoomRepository::saveData()
{
	string filename = "Room.txt";
	ofstream file(filename);

	if (!file.is_open()) {
		cout << "Khong the mo file: " << filename << "!";
		return;
	}
	for (ListNode<Room>* p = this->list.getHead(); p != nullptr; p = p->next)
	{
		file << p->value.getRoomID() << ";";
		file << p->value.getRoomName() << ";";
		file << p->value.getRoomType() << ";";
		file << p->value.getCapacity() << ";";
		file << p->value.getCurrentOccupancy() << ";";
		file << p->value.getFloor() << ";";
		file << p->value.getBuilding() << ";";
		file << p->value.getIsActive() << "\n";
	}
	file.close();
}



void RoomRepository::Add(const Room& room)
{
	this->list.add(room);
}

void RoomRepository::Delete(const Room& room)
{
	Room* temp = this->GetById(room.getRoomID()); 
	if (temp == nullptr) return;
	this->list.remove(*temp);
}
void RoomRepository::Update(const Room& room)
{
	Room* temp = this->GetById(room.getRoomID());
	*temp = room;
}
LinkedList<Room> RoomRepository::GetAll()
{
	return this->list;
}
Room* RoomRepository::GetById(const int& roomID)
{
	for (ListNode<Room>* p = this->list.getHead(); p != nullptr; p = p->next)
	{
		if (p->value.getRoomID() == roomID)
			return &(p->value);
	}
	return nullptr;
}


int RoomRepository::GetSize()
{
	return this->list.getSize();
}