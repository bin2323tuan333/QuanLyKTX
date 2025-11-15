#pragma once
#include "LinkedList.h"

class Room;
class IRoomService
{
public:
    virtual ~IRoomService();

    virtual Room* getRoomById(int) = 0;
    virtual Room* getRoomByStudentId(int) = 0;
    virtual LinkedList<Room*>* getAllRooms() = 0;
    virtual int updateRoom(const int&, const Room&) = 0;
    virtual LinkedList<Room*> getAvailableRooms() = 0;
    virtual LinkedList<Room*> getVacantRooms() = 0;
};