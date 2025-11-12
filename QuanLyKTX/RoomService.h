#pragma once
#include "DB.h"

class RoomService
{

private:
	DB* database;
public:
	RoomService();
	~RoomService();


	Room* getRoomById(int);
	Room* getRoomByStudentId(int);
	LinkedList<Room*>* getAllRooms();
	int updateRoom(const int&, const Room&);

	LinkedList<Room*> getAvailableRooms();
	LinkedList<Room*> getVacantRooms();
};

