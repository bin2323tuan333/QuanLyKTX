#include "ContractRepository.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

ContractRepository::ContractRepository()
{
    this->p = nullptr;
    this->n = 0;
}
ContractRepository::~ContractRepository()
{
    delete[] this->p;
}

void ContractRepository::Add(const Contract& contract)
{
    Contract* temp = new Contract[this->n + 1];
    for (int i = 0; i < this->n; i++)
    {
        *(temp + i) = *(this->p + i);
    }
    *(temp + this->n) = contract;
    delete[] this->p;
    this->p = temp;
    (this->n)++;
}
void ContractRepository::Insert(const Contract& contract, const int& index)
{
    if (index < 0 || index > this->n)
        return;

    Contract* temp = new Contract[this->n + 1];
    for (int i = 0; i < index; i++)
    {
        *(temp + i) = *(this->p + i);
    }
    *(temp + index) = contract;
    for (int i = index; i < this->n; i++)
    {
        *(temp + i + 1) = *(this->p + i);
    }
    delete[] this->p;
    this->p = temp;
    (this->n)++;
}


int ContractRepository::IndexOf(const int& contractID)
{
    int index = -1;
    for (int i = 0; i < this->n; i++)
    {
        if (contractID == (this->p + i)->getContractID())
        {
            index = i;
            break;
        }
    }
    return index;
}
Contract* ContractRepository::Search(const int& contractID)
{
    int index = IndexOf(contractID);
    if (index != -1)
    {
        return (this->p + index);
    }
    return nullptr;
}
Contract* ContractRepository::getAll()
{
    return this->p;
}
int ContractRepository::getSize()
{
    return this->n;
}

void ContractRepository::Update(Contract& contract)
{
    int index = IndexOf(contract.getContractID());
    if (index == -1)
        return;

    (this->p + index)->setContractID(contract.getContractID());
    (this->p + index)->setRoomID(contract.getRoomID());
    (this->p + index)->setStudentID(contract.getStudentID());
    (this->p + index)->setDuration(contract.getDuration());
    (this->p + index)->setRegistrationDate(contract.getRegistrationDate());
    
}

void ContractRepository::Delete(const int& contractID)
{
    int index = IndexOf(contractID);
    if (index == -1) return;

    Contract* temp = new Contract[this->n - 1];
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

void ContractRepository::LoadDataFromFile()
{
    string filename = "Contract.txt";
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

        Contract temp;

        getline(ss, token, ';'); temp.setContractID(stoi(token));
        getline(ss, token, ';'); temp.setDuration(stoi(token));
        getline(ss, token, ';'); 
        int d, m, y;
        char sep1, sep2;
        stringstream dateStream(token);
        dateStream >> d >> sep1 >> m >> sep2 >> y;
        temp.setRegistrationDate(Date(d, m, y));
        getline(ss, token, ';'); temp.setRoomID(stoi(token));
        getline(ss, token, ';'); temp.setStudentID(stoi(token));

        this->Add(temp);
    }
    file.close();
}
void ContractRepository::SaveDateToFile()
{
    string filename = "Contract.txt";
    ofstream file(filename);

    if (!file.is_open()) {
        cout << "Khong the mo file: " << filename << "!";
        return;
    }

    for (int i = 0; i < this->n; i++)
    {
        file << (this->p + i)->getContractID() << ";";
        file << (this->p + i)->getDuration() << ";";
        file << (this->p + i)->getRegistrationDate() << ";";
        file << (this->p + i)->getRoomID() << ";";
        file << (this->p + i)->getStudentID() << "\n";
    }
    file.close();
}