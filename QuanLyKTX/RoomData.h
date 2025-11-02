#pragma once
#include "Room.h"
#include "LinkedList.h"


class RoomData
{
private:
    string fileName;
    LinkedList<Room*> list;

public:
    RoomData(const string&);
    ~RoomData();

    void loadData();
    void saveData();

    void Add(const Room&);
    void Update(const Room&);
    void Delete(const Room&);
    Room* GetById(const int&);
    LinkedList<Room> GetAll();

    int GetSize();
};
