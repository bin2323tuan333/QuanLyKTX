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
Room* RoomService::getRoomByStudentId(int studentId)
{
	Student* student = DB::Instance()->getStudentByStudentId(studentId);
	Contract* contract = nullptr;
	for (ListNode<Contract*>* p = student->getContracts()->getHead(); p != nullptr; p = p->next)
	{
		if (p->value->isActive()) return p->value->getRoom();
	}
	return nullptr;
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

int RoomService::updateRoom(const int& id, const Room& updatedRoom)
{
	Room* room = DB::Instance()->getRoomByRoomId(id);
	if (room->getCurrentOccupancy() != 0)
	{
		if (updatedRoom.getRoomType() != room->getRoomType() || updatedRoom.getIsActive() != room->getIsActive())
			return 2;
	}
	if (room->getCapacity() != updatedRoom.getCapacity() && room->getCurrentOccupancy() > updatedRoom.getCapacity())
		return 2;
	DB::Instance()->updateRoom(updatedRoom);
	return 1;
}