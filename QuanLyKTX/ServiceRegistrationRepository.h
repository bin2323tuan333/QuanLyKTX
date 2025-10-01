#pragma once
#include "ServiceRegistration.h"




class ServiceRegistrationRepository
{
private:
    ServiceRegistration* p;
    int n;

public:
    ServiceRegistrationRepository();
    ~ServiceRegistrationRepository();

    // Create
    void Add(const ServiceRegistration&);
    void Insert(const ServiceRegistration&, const int&);

    // Read
    void Show();
    int IndexOf(const int&, const int&);
    ServiceRegistration Search(const int&, const int&);

    // Update
    void Update(ServiceRegistration&);

    // Delete
    void Delete(const int&, const int&);


    void LoadDataFromFile();
    void SaveDateToFile();
};
