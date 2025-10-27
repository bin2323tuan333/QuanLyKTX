#include "EmployeeRepository.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

EmployeeRepository::EmployeeRepository(const string& fileName)
    :fileName(fileName)
{
    this->loadData();
}
EmployeeRepository::~EmployeeRepository()
{
    this->saveData();
}


void EmployeeRepository::loadData()
{
    ifstream file(this->fileName);
    if (!file.is_open())
        return;
    string line;

    while (getline(file, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string token;
        Employee temp;

        getline(ss, token, ';'); temp.setEmployeeID(stoi(token));
        getline(ss, token, ';'); temp.setFullName(token);
        getline(ss, token, ';'); 
        int d, m, y;
        char sep1, sep2;
        stringstream dateStream(token);
        dateStream >> d >> sep1 >> m >> sep2 >> y;
        temp.setDateOfBirth(Date(d, m, y));
        getline(ss, token, ';'); temp.setGender(token);
        getline(ss, token, ';'); temp.setPosition(token);
        getline(ss, token, ';'); temp.setPhoneNumber(token);
        getline(ss, token, ';'); temp.setEmail(token);

        this->list.add(temp);
    }
    file.close();
}
void EmployeeRepository::saveData()
{
    ofstream file(this->fileName);
    if (!file.is_open()) 
        return;
    
    for (ListNode<Employee>* p = this->list.getHead(); p != nullptr; p = p->next)
    {
        file << p->value.getEmployeeID() << ";";
        file << p->value.getFullName() << ";";
        file << p->value.getDateOfBirth() << ";";
        file << p->value.getGender() << ";";
        file << p->value.getPosition() << ";";
        file << p->value.getPhoneNumber() << ";";
        file << p->value.getEmail() << "\n";
    }
    file.close();
}

void EmployeeRepository::Add(const Employee& employee)
{
    this->list.add(employee);
}

void EmployeeRepository::Delete(const Employee& employee)
{
    Employee* temp = this->GetById(employee.getEmployeeID());
    if (temp == nullptr) return;
    this->list.remove(*temp);
}
void EmployeeRepository::Update(const Employee& employee)
{
    Employee* temp = this->GetById(employee.getEmployeeID());
    *temp = employee;
}
LinkedList<Employee> EmployeeRepository::GetAll()
{
    return this->list;
}
Employee* EmployeeRepository::GetById(const int& employeeID)
{
    for (ListNode<Employee>* p = this->list.getHead(); p != nullptr; p = p->next)
    {
        if (p->value.getEmployeeID() == employeeID)
            return &(p->value);
    }
    return nullptr;
}


int EmployeeRepository::GetSize()
{
    return this->list.getSize();
}