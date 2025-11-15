#pragma once
#include "IRoomService.h"
#include "DB.h"

class Room;
class RoomService : public IRoomService
{
private:
	DB* database;

public:
	RoomService();
	~RoomService();


	Room* getRoomById(int) override;
	Room* getRoomByStudentId(int) override;
	LinkedList<Room*>* getAllRooms() override;
	int updateRoom(const int&, const Room&) override;
	LinkedList<Room*> getAvailableRooms() override;
	LinkedList<Room*> getVacantRooms() override;
};

