#include "InvoiceRepository.h"
#include <fstream>
#include <sstream>

InvoiceRepository::InvoiceRepository(const string& fileName)
    :fileName(fileName)
{
}
InvoiceRepository::~InvoiceRepository()
{

}

void InvoiceRepository::loadData()
{
    string filename = "Invoice.txt";
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

        this->list.add(temp);
    }
    file.close();
}
void InvoiceRepository::saveData()
{
    string filename = "Invoice.txt";
    ofstream file(filename);

    if (!file.is_open()) {
        cout << "Khong the mo file: " << filename << "!";
        return;
    }
    for (ListNode<Invoice>* p = this->list.getHead(); p != nullptr; p = p->next)
    {
        file << p->value.getInvoiceID() << ";";
        file << p->value.getStudentID() << ";";
        file << p->value.getEmployeeID() << ";";
        file << p->value.getMonth() << ";";
        file << p->value.getYear() << ";";
        file << p->value.getRoomFee() << ";";
        file << p->value.getInternetFee() << ";";
        file << p->value.getElectricFee() << ";";
        file << p->value.getWaterFee() << ";";
        file << p->value.getTotalAmount() << ";";
        file << p->value.getCreatedDate() << "\n";
    }
    file.close();
}




void InvoiceRepository::Add(const Invoice& invoice)
{
    this->list.add(invoice);
    this->saveData();
}

void InvoiceRepository::Delete(const Invoice& invoice)
{
    Invoice* temp = this->GetById(invoice.getInvoiceID());
    if (temp == nullptr) return;
    this->list.remove(*temp);
    this->saveData();
}
void InvoiceRepository::Update(const Invoice& invoice)
{
    Invoice* temp = this->GetById(invoice.getInvoiceID());
    *temp = invoice;
}
LinkedList<Invoice> InvoiceRepository::GetAll()
{
    return this->list;
}
Invoice* InvoiceRepository::GetById(const int& invoiceID)
{
    for (ListNode<Invoice>* p = this->list.getHead(); p != nullptr; p = p->next)
    {
        if (p->value.getEmployeeID() == invoiceID)
            return &(p->value);
    }
    return nullptr;
}


int InvoiceRepository::GetSize()
{
    return this->list.getSize();
}