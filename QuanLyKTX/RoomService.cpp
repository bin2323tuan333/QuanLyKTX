#include "RoomService.h"

RoomService::RoomService(RoomData& roomData, StudentData& studentData, ContractData& contractData)
	:roomData(roomData), studentData(studentData), contractData(contractData)
{
}

RoomService::~RoomService()
{
}


int RoomService::Add(const Room& temp)
{
	this->roomData.Add(temp);
	return 1;
}
Room* RoomService::SearchByID(const int& id)
{
	return this->roomData.GetByRoomId(id);
}
LinkedList<Room*>* RoomService::GetAll()
{
	return this->roomData.getList();
}
//LinkedList<Student> RoomService::GetStudentsInRoom(const int& roomId)
//{
//	LinkedList<int> studentIds = this->contractRepo.GetStudentIdsByRoomId(roomId);
//	LinkedList<Student> students;
//	for (ListNode<int>* p = studentIds.getHead(); p != nullptr; p = p->next)
//	{
//		students.add(*this->studentRepo.GetById(p->value));
//	}
//	return students;
//}
int RoomService::Update(const Room& temp)
{
	this->roomData.Update(temp);
	return 1;
}
int RoomService::Delete(const Room& temp)
{
	this->roomData.Delete(temp);
	return 1;
}