#pragma once
#include "Room.h"
#include "LinkedList.h"
#include "HashTable.h"


class RoomData
{
private:
    string fileName;
    LinkedList<Room*> list;
    HashTable<int, Room*> mapRoomId;

public:
    RoomData(const string&);
    ~RoomData();

    void loadData();
    void saveData();
    LinkedList<Room*>* getList();

    void Add(const Room&);
    void Update(const Room&);
    void Delete(const Room&);
    Room* GetByRoomId(const int&);

    int GetSize();
};
