#include "EmployeeRepository.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

EmployeeRepository::EmployeeRepository()
{
    this->p = nullptr;
    this->n = 0;
    LoadDataFromFile();
}
EmployeeRepository::~EmployeeRepository()
{
    delete[] this->p;
}

void EmployeeRepository::Add(const Employee& employee)
{
    Employee* temp = new Employee[this->n + 1];
    for (int i = 0; i < this->n; i++)
    {
        *(temp + i) = *(this->p + i);
    }
    *(temp + this->n) = employee;
    delete[] this->p;
    this->p = temp;
    (this->n)++;
}
void EmployeeRepository::Insert(const Employee& employee, const int& index)
{
    if (index < 0 || index > this->n)
        return;

    Employee* temp = new Employee[this->n + 1];
    for (int i = 0; i < index; i++)
    {
        *(temp + i) = *(this->p + i);
    }
    *(temp + index) = employee;
    for (int i = index; i < this->n; i++)
    {
        *(temp + i + 1) = *(this->p + i);
    }
    delete[] this->p;
    this->p = temp;
    (this->n)++;
}


int EmployeeRepository::IndexOf(const int& employeeID)
{
    int index = -1;
    for (int i = 0; i < this->n; i++)
    {
        if (employeeID == (this->p + i)->getEmployeeID())
        {
            index = i;
            break;
        }
    }
    return index;
}
Employee& EmployeeRepository::Search(const int& employeeID)
{
    int index = IndexOf(employeeID);
    if (index != -1)
    {
        return *(this->p + index);
    }
    
}

void EmployeeRepository::Update(Employee& employee)
{
    int index = IndexOf(employee.getEmployeeID());
    if (index == -1)
        return;

    (this->p + index)->setEmployeeID(employee.getEmployeeID());
    (this->p + index)->setFullName(employee.getFullName());
    (this->p + index)->setDateOfBirth(employee.getDateOfBirth());
    (this->p + index)->setEmail(employee.getEmail());
    (this->p + index)->setGender(employee.getGender());
    (this->p + index)->setPhoneNumber(employee.getPhoneNumber());
    (this->p + index)->setPosition(employee.getPosition());
}

void EmployeeRepository::Delete(const int& employeeID)
{
    int index = IndexOf(employeeID);
    if (index == -1) return;

    Employee* temp = new Employee[this->n - 1];
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


void EmployeeRepository::LoadDataFromFile()
{
    string filename = "Employee.txt";
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

        this->Add(temp);
    }
    file.close();
}
void EmployeeRepository::SaveDateToFile()
{
    string filename = "Employee.txt";
    ofstream file(filename);

    if (!file.is_open()) {
        cout << "Khong the mo file: " << filename << "!";
        return;
    }

    for (int i = 0; i < this->n; i++)
    {
        file << (this->p + i)->getEmployeeID() << ";";
        file << (this->p + i)->getFullName() << ";";
        file << (this->p + i)->getDateOfBirth() << ";";
        file << (this->p + i)->getGender() << ";";
        file << (this->p + i)->getPosition() << ";";
        file << (this->p + i)->getPhoneNumber() << ";";
        file << (this->p + i)->getEmail() << "\n";
    }
    file.close();
}