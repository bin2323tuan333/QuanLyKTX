#pragma once
#include "RoomRepository.h"
#include "StudentRepository.h"

class RoomService {
private:
    RoomRepository& roomRepo;
    StudentRepository& studentRepo;

public:
    RoomService(RoomRepository&, StudentRepository&);
    ~RoomService();


    Room* getAll();
    /*bool addRoom(const Room&);
    bool updateRoom(const Room&);
    bool deleteRoom(int);

    Room getRoomById(int);

    bool assignStudentToRoom(int, const string&);
    bool removeStudentFromRoom(int, const string&);

    int getRoomCapacity(int);
    int getCurrentOccupancy(int);
    bool isRoomAvailable(int);*/
};