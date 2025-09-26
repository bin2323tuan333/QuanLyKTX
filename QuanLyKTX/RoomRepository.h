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
    void Show();
    int IndexOf(const int&);
    Room Search(const int&);

    // Update
    void Update(const int&);

    // Delete
    void Delete(const int&);

    void LoadDataFromFile();
    void SaveDateToFile();
};
