#include "RoomService.h"

RoomService::RoomService(RoomRepository& roomRepo, StudentRepository& studentRepo)
	:roomRepo(roomRepo), studentRepo(studentRepo)
{
}

RoomService::~RoomService()
{
}
