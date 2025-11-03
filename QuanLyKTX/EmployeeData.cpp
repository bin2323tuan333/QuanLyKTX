#include "EmployeeData.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

EmployeeData::EmployeeData(const string& fileName)
    :fileName(fileName)
{
    this->loadData();
}
EmployeeData::~EmployeeData()
{
    this->saveData();
}


void EmployeeData::loadData()
{
    ifstream file(this->fileName);
    if (!file.is_open())
        return;
    string line;

    while (getline(file, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string token;
        Employee* employee = new Employee();
        getline(ss, token, ';'); employee->setEmployeeId(stoi(token));
        getline(ss, token, ';'); employee->setUserId(stoi(token));
        getline(ss, token, ';'); employee->setFullName(token);
        getline(ss, token, ';'); employee->setGender(token == "1" ? true : false);
        getline(ss, token, ';'); employee->setDateOfBirth(Date::stringToDate(token));
        getline(ss, token, ';'); employee->setPhoneNumber(token);
        getline(ss, token, ';'); employee->setEmail(token);
        getline(ss, token, ';'); employee->setRole(token);
        getline(ss, token, ';'); employee->setSalary(stoi(token));

        this->list.add(employee);
        this->mapEmployeeId.insert(employee->getEmployeeId(), employee);
    }
    file.close();
}
void EmployeeData::saveData()
{
    ofstream file(this->fileName);
    if (!file.is_open()) 
        return;
    
    for (ListNode<Employee*>* p = this->list.getHead(); p != nullptr; p = p->next)
    {
        file << p->value->getEmployeeId() << ";";
        file << p->value->getUserId() << ";";
        file << p->value->getFullName() << ";";
        file << (p->value->getGender() == true ? "1" : "0") << ";";
        file << p->value->getDateOfBirth() << ";";
        file << p->value->getPhoneNumber() << ";";
        file << p->value->getEmail() << ";";
        file << p->value->getRole() << ";";
        file << p->value->getSalary() << endl;
    }
    file.close();
}
LinkedList<Employee*>* EmployeeData::getList()
{
    return &(this->list);
}
void EmployeeData::Add(const Employee& employee)
{
    Employee* employeeToAdd = new Employee(employee);
    this->list.add(employeeToAdd);
    this->mapEmployeeId.insert(employeeToAdd->getEmployeeId(), employeeToAdd);
}

void EmployeeData::Delete(const Employee& employee)
{
    Employee* employeeToDelete = GetByEmployeeId(employee.getEmployeeId());
    if (employeeToDelete == nullptr)
        return;
    this->list.remove(employeeToDelete);
    this->mapEmployeeId.remove(employeeToDelete->getEmployeeId());
    delete employeeToDelete;
}
void EmployeeData::Update(const Employee& employee)
{
    Employee* employeeToUpdate = GetByEmployeeId(employee.getEmployeeId());
    if (employeeToUpdate == nullptr)
        return;
    *employeeToUpdate = employee;
}

Employee* EmployeeData::GetByEmployeeId(const int& employeeID)
{
    Employee** result = this->mapEmployeeId.search(employeeID);
    if (result != nullptr) {
        return *result;
    }
    return nullptr;
}


int EmployeeData::GetSize()
{
    return this->list.getSize();
}