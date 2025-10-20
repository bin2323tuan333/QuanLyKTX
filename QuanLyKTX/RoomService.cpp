#include "RoomService.h"

RoomService::RoomService(RoomRepository& roomRepo, StudentRepository& studentRepo, ContractRepository& contractRepo)
	:roomRepo(roomRepo), studentRepo(studentRepo), contractRepo(contractRepo)
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
void RoomService::getStudentInRoom(Student*& studentList, int& count, const int& roomID)
{
	count = 0;
	Contract* allContracts = this->contractRepo.getAll();
	int contractSize = this->contractRepo.getSize();

	for (int i = 0; i < contractSize; i++)
	{
		if ((allContracts + i)->getRoomID() == roomID)
		{
			count++;
		}
	}

	if (count == 0)
	{
		studentList = nullptr;
		return;
	}

	studentList = new Student[count];
	int currentIndex = 0;

	for (int i = 0; i < contractSize; i++)
	{
		if ((allContracts + i)->getRoomID() == roomID)
		{
			int studentID = (allContracts + i)->getStudentID();
			Student* student = studentRepo.Search(studentID);
			if (student != nullptr)
				*(studentList + currentIndex++) = *student;
		}
	}
}