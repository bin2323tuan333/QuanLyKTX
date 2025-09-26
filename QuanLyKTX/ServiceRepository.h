#pragma once
#include "Service.h"




class ServiceRepository
{
private:
    Service* p;
    int n;

public:
    ServiceRepository();
    ~ServiceRepository();

    // Create
    void Add(const Service&);
    void Insert(const Service&, const int&);

    // Read
    void Show();
    int IndexOf(const int&);
    Service Search(const int&);

    // Update
    void Update(const int&);

    // Delete
    void Delete(const int&);

    void LoadDataFromFile();
    void SaveDateToFile();
};
