#pragma once
#include "DB.h"

class RoomService
{

private:
	DB* database;
public:
	RoomService();
	~RoomService();

	//Room* createRoom(const std::string& roomNumber, const std::string& building,
	//	int floor, int capacity, const std::string& type,
	//	double pricePerMonth, const std::string& status);
	Room* getRoomById(int);
	LinkedList<Room*>* getAllRooms();
	int updateRoom(const Room&);


	LinkedList<Room*> getAvailableRooms();
	LinkedList<Room*> getVacantRooms();



};

