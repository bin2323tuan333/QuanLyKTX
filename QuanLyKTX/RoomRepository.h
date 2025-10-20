#pragma once
#include "Room.h"




class RoomRepository
{
private:
    Room* p;
    int n;

public:
    RoomRepository();
    ~RoomRepository();

    // Create
    void Add(const Room&);
    void Insert(const Room&, const int&);

    // Read
    int IndexOf(const int&);
    Room Search(const int&);
    Room* getAll();

    // Update
    void Update(Room&);

    // Delete
    void Delete(const int&);

    void LoadDataFromFile();
    void SaveDateToFile();
};
