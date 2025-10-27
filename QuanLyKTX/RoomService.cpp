#include "RoomService.h"

RoomService::RoomService(RoomRepository& roomRepo, StudentRepository& studentRepo, ContractRepository& contractRepo)
	:roomRepo(roomRepo), studentRepo(studentRepo), contractRepo(contractRepo)
{
}

RoomService::~RoomService()
{
}


int RoomService::Add(const Room& temp)
{
	this->roomRepo.Add(temp);
	return 1;
}
Room* RoomService::SearchByID(const int& id)
{
	return this->roomRepo.GetById(id);
}
LinkedList<Room> RoomService::GetAll()
{
	return this->roomRepo.GetAll();
}
LinkedList<Student> RoomService::GetStudentsInRoom(const int& roomId)
{
	LinkedList<int> studentIds = this->contractRepo.GetStudentIdsByRoomId(roomId);
	LinkedList<Student> students;
	for (ListNode<int>* p = studentIds.getHead(); p != nullptr; p = p->next)
	{
		students.add(*this->studentRepo.GetById(p->value));
	}
	return students;
}
int RoomService::Update(const Room& temp)
{
	this->roomRepo.Update(temp);
	return 1;
}
int RoomService::Delete(const Room& temp)
{
	this->roomRepo.Delete(temp);
	return 1;
}