#include "RoomService.h"

RoomService::RoomService(RoomRepository& roomRepo, StudentRepository& studentRepo)
	:roomRepo(roomRepo), studentRepo(studentRepo)
{
}

RoomService::~RoomService()
{
}


void RoomService::getAllRoom(Room*& roomList, int& size)
{
	roomList = this->roomRepo.getAll();
	size = this->roomRepo.getSize();
}

Room* RoomService::getRoomById(const int& roomID)
{
	return this->roomRepo.Search(roomID);
}