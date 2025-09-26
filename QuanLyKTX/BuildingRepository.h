#pragma once
#include "Building.h"




class BuildingRepository
{
private:
    Building* p;
    int n;

public:
    BuildingRepository();
    ~BuildingRepository();

    // Create
    void Add(const Building&);
    void Insert(const Building&, const int&);

    // Read
    void Show();
    int IndexOf(const int&);
    Building Search(const int&);

    // Update
    void Update(const int&);

    // Delete
    void Delete(const int&);


    void LoadDataFromFile();
    void SaveDateToFile();
};
