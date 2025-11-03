#include "RoomData.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

RoomData::RoomData(const string& fileName)
	:fileName(fileName)
{
	this->loadData();
}
RoomData::~RoomData()
{
	this->saveData();
}

void RoomData::loadData()
{
	ifstream file(this->fileName);
	if (!file.is_open())
		return;
	string line;

	while (getline(file, line)) {
		if (line.empty()) continue;
		stringstream ss(line);
		string token;
		Room* room = new Room();

		getline(ss, token, ';'); room->setRoomId(stoi(token));
		getline(ss, token, ';'); room->setRoomName(token);
		getline(ss, token, ';'); room->setRoomType(token);
		getline(ss, token, ';'); room->setCapacity(stoi(token));
		getline(ss, token, ';'); room->setCurrentOccupancy(stoi(token));
		getline(ss, token, ';'); room->setFloor(stoi(token));
		getline(ss, token, ';'); room->setBuilding(token);
		getline(ss, token, ';'); room->setIsActive(token == "1" ? true : false);
		this->list.add(room);
		this->mapRoomId.insert(room->getRoomId(), room);
	}
	file.close();
}
void RoomData::saveData()
{
	string filename = "Room.txt";
	ofstream file(filename);

	if (!file.is_open()) {
		cout << "Khong the mo file: " << filename << "!";
		return;
	}
	for (ListNode<Room*>* p = this->list.getHead(); p != nullptr; p = p->next)
	{
		file << p->value->getRoomId() << ";";
		file << p->value->getRoomName() << ";";
		file << p->value->getRoomType() << ";";
		file << p->value->getCapacity() << ";";
		file << p->value->getCurrentOccupancy() << ";";
		file << p->value->getFloor() << ";";
		file << p->value->getBuilding() << ";";
		file << (p->value->getIsActive() == true ? "1" : "0") << "\n";
	}
	file.close();
}

LinkedList<Room*>* RoomData::getList()
{
	return &(this->list);
}

void RoomData::Add(const Room& room)
{
	Room* newRoom = new Room(room);
	this->list.add(newRoom);
	this->mapRoomId.insert(newRoom->getRoomId(), newRoom);
}

void RoomData::Delete(const Room& room)
{
	Room* roomToDelete = GetByRoomId(room.getRoomId());
	if (roomToDelete == nullptr) return;
	this->list.remove(roomToDelete);
	this->mapRoomId.remove(roomToDelete->getRoomId());
	delete roomToDelete;
}
void RoomData::Update(const Room& room)
{
	Room* roomToUpdate = GetByRoomId(room.getRoomId());
	if (roomToUpdate == nullptr) return;
	*roomToUpdate = room;
}
Room* RoomData::GetByRoomId(const int& roomId)
{
	Room** room = this->mapRoomId.search(roomId);
	if (room == nullptr)
		return nullptr;
	return *room;
}
	
int RoomData::GetSize()
{
	return this->list.getSize();
}