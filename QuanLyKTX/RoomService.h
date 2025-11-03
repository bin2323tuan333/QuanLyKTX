#pragma once
#include "RoomData.h"
#include "StudentData.h"
#include "ContractData.h"


class RoomService {
private:
    RoomData& roomData;
    StudentData& studentData;
    ContractData& contractData;
public:
    RoomService(RoomData&, StudentData&, ContractData&);
    ~RoomService();


    int Add(const Room&);
    Room* SearchByID(const int&);
    LinkedList<Room*>* GetAll();
    //LinkedList<Student*> GetStudentsInRoom(const int&);
    int Update(const Room&);
    int Delete(const Room&);
};