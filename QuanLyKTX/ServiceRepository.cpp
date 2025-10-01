#include "ServiceRepository.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

ServiceRepository::ServiceRepository()
{
    this->p = nullptr;
    this->n = 0;
}
ServiceRepository::~ServiceRepository()
{
    delete[] this->p;
}

// Create
void ServiceRepository::Add(const Service& service)
{
    Service* temp = new Service[this->n + 1];
    for (int i = 0; i < this->n; i++)
    {
        *(temp + i) = *(this->p + i);
    }
    *(temp + this->n) = service;
    delete[] this->p;
    this->p = temp;
    (this->n)++;
}
void ServiceRepository::Insert(const Service& service, const int& index)
{
    if (index < 0 || index > this->n)
        return;

    Service* temp = new Service[this->n + 1];
    for (int i = 0; i < index; i++)
    {
        *(temp + i) = *(this->p + i);
    }
    *(temp + index) = service;
    for (int i = index; i < this->n; i++)
    {
        *(temp + i + 1) = *(this->p + i);
    }
    delete[] this->p;
    this->p = temp;
    (this->n)++;
}

// Read
void ServiceRepository::Show()
{
    for (int i = 0; i < this->n; i++)
    {
        (this->p + i)->show();
        cout << endl;
    }
}
int ServiceRepository::IndexOf(const int& serviceID)
{
    int index = -1;
    for (int i = 0; i < this->n; i++)
    {
        if (serviceID == (this->p + i)->getServiceID())
        {
            index = i;
            break;
        }
    }
    return index;
}
Service ServiceRepository::Search(const int& serviceID)
{
    int index = IndexOf(serviceID);
    if (index != -1)
    {
        return *(this->p + index);
    }
    return Service();
}

// Update
void ServiceRepository::Update(Service& service)
{
    int index = IndexOf(service.getServiceID());
    if (index == -1)
        return;

    (this->p + index)->setServiceID(service.getServiceID());
    (this->p + index)->setServiceName(service.getServiceName());
    (this->p + index)->setUnitPrice(service.getUnitPrice());
    (this->p + index)->setDescription(service.getDescription());
}

// Delete
void ServiceRepository::Delete(const int& serviceID)
{
    int index = IndexOf(serviceID);
    if (index == -1) return;

    Service* temp = new Service[this->n - 1];
    for (int i = 0; i < index; i++)
    {
        *(temp + i) = *(this->p + i);
    }
    for (int i = index; i < this->n - 1; i++)
    {
        *(temp + i) = *(this->p + i + 1);
    }
    delete[] this->p;
    this->p = temp;
    (this->n)--;
}



void ServiceRepository::LoadDataFromFile()
{
    string filename = "Account.txt";
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Khong the mo file " << filename << "!";
        return;
    }
    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        string token;

        Service temp;

        getline(ss, token, ';'); temp.setServiceID(stoi(token));
        getline(ss, token, ';'); temp.setServiceName(token);
        getline(ss, token, ';'); temp.setUnitPrice(stoi(token));
        getline(ss, token, ';'); temp.setDescription(token);

        this->Add(temp);
    }
    file.close();
}
void ServiceRepository::SaveDateToFile()
{
    string filename = "Account.txt";
    ofstream file(filename);

    if (!file.is_open()) {
        cout << "Khong the mo file: " << filename << "!";
        return;
    }

    for (int i = 0; i < this->n; i++)
    {
        file << (this->p + i)->getServiceID() << ";";
        file << (this->p + i)->getServiceName() << ";";
        file << (this->p + i)->getUnitPrice() << ";";
        file << (this->p + i)->getDescription() << "\n";
    }
    file.close();
}