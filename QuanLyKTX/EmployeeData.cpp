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

        getline(ss, token, ';'); employee->setFullName(token);
        getline(ss, token, ';'); employee->setGender(token == "1" ? true : false);
        getline(ss, token, ';'); employee->setDateOfBirth(Date::stringToDate(token));
        getline(ss, token, ';'); employee->setPhoneNumber(token);
        getline(ss, token, ';'); employee->setEmail(token);
        getline(ss, token, ';'); employee->setUserId(stoi(token));
        getline(ss, token, ';'); employee->setEmployeeId(stoi(token));
        getline(ss, token, ';'); employee->setRole(token);
        getline(ss, token, ';'); employee->setSalary(stoi(token));

        this->list.add(employee);
        this->map.insert(employee->getEmployeeId(), employee);
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
        file << p->value->getFullName() << ";";
        file << (p->value->getGender() == true ? "1" : "0") << ";";
        file << p->value->getDateOfBirth() << ";";
        file << p->value->getPhoneNumber() << ";";
        file << p->value->getEmail() << ";";
        file << p->value->getUserId() << ";";
        file << p->value->getEmployeeId() << ";";
        file << p->value->getRole() << ";";
        file << p->value->getSalary() << endl;
    }
    file.close();
}

//void EmployeeData::Add(const Employee& employee)
//{
//}
//
//void EmployeeData::Delete(const Employee& employee)
//{
//
//}
//void EmployeeData::Update(const Employee& employee)
//{
//
//}
//LinkedList<Employee> EmployeeData::GetAll()
//{
//
//}
//Employee* EmployeeData::GetById(const int& employeeID)
//{
//
//}
//
//
//int EmployeeData::GetSize()
//{
//    return this->list.getSize();
//}