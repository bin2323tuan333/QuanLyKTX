#include "RoomService.h"
#include "Student.h"
#include "Contract.h"

RoomService::RoomService()
{
	this->database = DB::Instance();
}

RoomService::~RoomService()
{
}

LinkedList<IRoom*>* RoomService::getAllRooms()
{
	return DB::Instance()->getAllRooms();
}
IRoom* RoomService::getRoomByStudentId(int studentId)
{
	IStudent* student = DB::Instance()->getStudentByStudentId(studentId);
	IContract* contract = nullptr;
	for (ListNode<IContract*>* p = student->getContracts()->getHead(); p != nullptr; p = p->next)
	{
		if (p->value->isActive()) return p->value->getRoom();
	}
	return nullptr;
}
LinkedList<IRoom*> RoomService::getAvailableRooms()
{
	LinkedList<IRoom*> tempList;
	for (ListNode<IRoom*>* p = DB::Instance()->getAllRooms()->getHead(); p != nullptr; p = p->next)
	{
		if (p->value->isAvailable()) tempList.add(p->value);
	}
	return tempList;
}
LinkedList<IRoom*> RoomService::getVacantRooms()
{
	LinkedList<IRoom*> tempList;
	for (ListNode<IRoom*>* p = DB::Instance()->getAllRooms()->getHead(); p != nullptr; p = p->next)
	{
		if (p->value->isVacant()) tempList.add(p->value);
	}
	return tempList;
}
IRoom* RoomService::getRoomById(int roomId)
{
	return DB::Instance()->getRoomByRoomId(roomId);
}

int RoomService::updateRoom(const int& id, const IRoom& updatedRoom)
{
	IRoom* room = DB::Instance()->getRoomByRoomId(id);
	if (room->getCurrentOccupancy() != 0)
	{
		if (updatedRoom.getRoomType() != room->getRoomType() || updatedRoom.getIsActive() != room->getIsActive())
			return 2;
	}
	if (room->getCapacity() != updatedRoom.getCapacity() && room->getCurrentOccupancy() > updatedRoom.getCapacity())
		return 2;
	room->setBuilding(updatedRoom.getBuilding());
	room->setCapacity(updatedRoom.getCapacity());
	room->setFloor(updatedRoom.getFloor());
	room->setIsActive(updatedRoom.getIsActive());
	room->setRoomName(updatedRoom.getRoomName());
	room->setRoomType(updatedRoom.getRoomType());
	return 1;
}