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


    void getAllRoom(Room*&, int&);
    Room* getRoomById(const int&);
    void getStudentInRoom(Student*&, int&, const int&);
    /*bool addRoom(const Room&);
    bool updateRoom(const Room&);
    bool deleteRoom(int);

    

    bool assignStudentToRoom(int, const string&);
    bool removeStudentFromRoom(int, const string&);

    int getRoomCapacity(int);
    int getCurrentOccupancy(int);
    bool isRoomAvailable(int);*/
};