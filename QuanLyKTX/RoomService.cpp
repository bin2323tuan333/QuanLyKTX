#include "RoomService.h"

RoomService::RoomService()
{
	this->database = DB::Instance();
}

RoomService::~RoomService()
{
}

LinkedList<Room*>* RoomService::getAllRooms()
{
	return DB::Instance()->getAllRooms();
}
LinkedList<Room*> RoomService::getAvailableRooms()
{
	LinkedList<Room*> tempList;
	for (ListNode<Room*>* p = DB::Instance()->getAllRooms()->getHead(); p != nullptr; p = p->next)
	{
		if (p->value->isAvailable()) tempList.add(p->value);
	}
	return tempList;
}
LinkedList<Room*> RoomService::getVacantRooms()
{
	LinkedList<Room*> tempList;
	for (ListNode<Room*>* p = DB::Instance()->getAllRooms()->getHead(); p != nullptr; p = p->next)
	{
		if (p->value->isVacant()) tempList.add(p->value);
	}
	return tempList;
}
Room* RoomService::getRoomById(int roomId)
{
	return DB::Instance()->getRoomByRoomId(roomId);
}

int RoomService::updateRoom(const Room& updatedRoom)
{
	// check logic
	DB::Instance()->updateRoom(updatedRoom);
	return 1;
}