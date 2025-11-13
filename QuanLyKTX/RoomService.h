#pragma once
#include "IRoomService.h"
#include "DB.h"

class RoomService : public IRoomService
{
private:
	DB* database;

public:
	RoomService();
	~RoomService();


	IRoom* getRoomById(int) override;
	IRoom* getRoomByStudentId(int) override;
	LinkedList<IRoom*>* getAllRooms() override;
	int updateRoom(const int&, const IRoom&) override;

	LinkedList<IRoom*> getAvailableRooms() override;
	LinkedList<IRoom*> getVacantRooms() override;
};

