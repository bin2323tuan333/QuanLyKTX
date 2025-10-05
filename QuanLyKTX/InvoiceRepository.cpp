#include "InvoiceRepository.h"
#include <fstream>
#include <sstream>

InvoiceRepository::InvoiceRepository()
{
    this->p = nullptr;
    this->n = 0;
}
InvoiceRepository::~InvoiceRepository()
{
    delete[] this->p;
}

// Create
void InvoiceRepository::Add(const Invoice& invoice)
{
    Invoice* temp = new Invoice[this->n + 1];
    for (int i = 0; i < this->n; i++)
    {
        *(temp + i) = *(this->p + i);
    }
    *(temp + this->n) = invoice;
    delete[] this->p;
    this->p = temp;
    (this->n)++;
}
void InvoiceRepository::Insert(const Invoice& invoice, const int& index)
{
    if (index < 0 || index > this->n)
        return;

    Invoice* temp = new Invoice[this->n + 1];
    for (int i = 0; i < index; i++)
    {
        *(temp + i) = *(this->p + i);
    }
    *(temp + index) = invoice;
    for (int i = index; i < this->n; i++)
    {
        *(temp + i + 1) = *(this->p + i);
    }
    delete[] this->p;
    this->p = temp;
    (this->n)++;
}

// Read
int InvoiceRepository::IndexOf(const int& invoiceID)
{
    int index = -1;
    for (int i = 0; i < this->n; i++)
    {
        if (invoiceID == (this->p + i)->getInvoiceID())
        {
            index = i;
            break;
        }
    }
    return index;
}
Invoice InvoiceRepository::Search(const int& invoiceID)
{
    int index = IndexOf(invoiceID);
    if (index != -1)
    {
        return *(this->p + index);
    }
    return Invoice();
}
Invoice InvoiceRepository::SearchByStudentID(const int& studentID)
{
    int index = -1;
    for (int i = 0; i < this->n; i++)
    {
        if (studentID == (this->p + i)->getStudentID())
        {
            index = i;
            break;
        }
    }
    if (index == -1)
        return Invoice();
    return *(this->p + index);
}

// Update
void InvoiceRepository::Update(Invoice& invoice)
{
    int index = IndexOf(invoice.getInvoiceID());
    if (index == -1)
        return;

    (this->p + index)->setStudentID(invoice.getStudentID());
    (this->p + index)->setEmployeeID(invoice.getEmployeeID());
    (this->p + index)->setMonth(invoice.getMonth());
    (this->p + index)->setYear(invoice.getYear());
    (this->p + index)->setRoomFee(invoice.getRoomFee());
    (this->p + index)->setInternetFee(invoice.getInternetFee());
    (this->p + index)->setElectricFee(invoice.getElectricFee());
    (this->p + index)->setWaterFee(invoice.getWaterFee());
    (this->p + index)->setTotalAmount(invoice.getTotalAmount());
    (this->p + index)->setCreatedDate(invoice.getCreatedDate());
}

// Delete
void InvoiceRepository::Delete(const int& invoiceID)
{
    int index = IndexOf(invoiceID);
    if (index == -1) return;

    Invoice* temp = new Invoice[this->n - 1];
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



void InvoiceRepository::LoadDataFromFile()
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

        Invoice temp;

        getline(ss, token, ';'); temp.setInvoiceID(stoi(token));
        getline(ss, token, ';'); temp.setStudentID(stoi(token));
        getline(ss, token, ';'); temp.setEmployeeID(stoi(token));
        getline(ss, token, ';'); temp.setMonth(stoi(token));
        getline(ss, token, ';'); temp.setYear(stoi(token));
        getline(ss, token, ';'); temp.setRoomFee(stoi(token));
        getline(ss, token, ';'); temp.setInternetFee(stoi(token));
        getline(ss, token, ';'); temp.setElectricFee(stoi(token));
        getline(ss, token, ';'); temp.setWaterFee(stoi(token));
        getline(ss, token, ';'); temp.setTotalAmount(stoi(token));
        getline(ss, token, ';'); 
        int d, m, y;
        char sep1, sep2;
        stringstream dateStream(token);
        dateStream >> d >> sep1 >> m >> sep2 >> y;
        temp.setCreatedDate(Date(d, m, y));

        this->Add(temp);
    }
    file.close();
}
void InvoiceRepository::SaveDateToFile()
{
    string filename = "Account.txt";
    ofstream file(filename);

    if (!file.is_open()) {
        cout << "Khong the mo file: " << filename << "!";
        return;
    }

    for (int i = 0; i < this->n; i++)
    {
        file << (this->p + i)->getInvoiceID() << ";";
        file << (this->p + i)->getStudentID() << ";";
        file << (this->p + i)->getEmployeeID() << ";";
        file << (this->p + i)->getMonth() << ";";
        file << (this->p + i)->getYear() << ";";
        file << (this->p + i)->getRoomFee() << ";";
        file << (this->p + i)->getInternetFee() << ";";
        file << (this->p + i)->getElectricFee() << ";";
        file << (this->p + i)->getWaterFee() << ";";
        file << (this->p + i)->getTotalAmount() << ";";
        file << (this->p + i)->getCreatedDate() << "\n";
    }
    file.close();
}
