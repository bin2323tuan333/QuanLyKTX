#pragma once
#include "IRoom.h"
#include "LinkedList.h"

class IRoomService
{
public:
    virtual ~IRoomService();

    virtual IRoom* getRoomById(int) = 0;
    virtual IRoom* getRoomByStudentId(int) = 0;
    virtual LinkedList<IRoom*>* getAllRooms() = 0;
    virtual int updateRoom(const int&, const IRoom&) = 0;
    virtual LinkedList<IRoom*> getAvailableRooms() = 0;
    virtual LinkedList<IRoom*> getVacantRooms() = 0;
};