#pragma once
#include "RoomRepository.h"
#include "StudentRepository.h"
#include "ContractRepository.h"


class RoomService {
private:
    RoomRepository& roomRepo;
    StudentRepository& studentRepo;
    ContractRepository& contractRepo;
public:
    RoomService(RoomRepository&, StudentRepository&, ContractRepository&);
    ~RoomService();


    int Add(const Room&);
    Room* SearchByID(const int&);
    LinkedList<Room> GetAll();
    LinkedList<Student> GetStudentsInRoom(const int&);
    int Update(const Room&);
    int Delete(const Room&);
};