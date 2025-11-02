#include "InvoiceData.h"
#include <fstream>
#include <sstream>

InvoiceData::InvoiceData(const string& fileName)
    :fileName(fileName)
{
    this->loadData();
}
InvoiceData::~InvoiceData()
{
    this->saveData();
}

void InvoiceData::loadData()
{
    ifstream file(this->fileName);
    if (!file.is_open())
        return;
    
    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string token;
        Invoice* invoice = new Invoice();

        getline(ss, token, ';'); invoice->setInvoiceID(stoi(token));
        getline(ss, token, ';'); invoice->setRoomFee(stoi(token));
        getline(ss, token, ';'); invoice->setInternetFee(stoi(token));
        getline(ss, token, ';'); invoice->setElectricFee(stoi(token));
        getline(ss, token, ';'); invoice->setWaterFee(stoi(token));
        getline(ss, token, ';'); invoice->setTotalAmount(stoi(token));
        getline(ss, token, ';'); invoice->setCreatedDate(Date::stringToDate(token));

        this->list.add(invoice);
    }
    file.close();
}
void InvoiceData::saveData()
{
    ofstream file(this->fileName);
    if (!file.is_open()) 
        return;

    for (ListNode<Invoice*>* p = this->list.getHead(); p != nullptr; p = p->next)
    {
        file << p->value->getInvoiceID() << ";";
        file << p->value->getRoomFee() << ";";
        file << p->value->getInternetFee() << ";";
        file << p->value->getElectricFee() << ";";
        file << p->value->getWaterFee() << ";";
        file << p->value->getTotalAmount() << ";";
        file << p->value->getCreatedDate() << endl;
    }
    file.close();
}


//void InvoiceData::Add(const Invoice& invoice)
//{
//}
//
//void InvoiceData::Delete(const Invoice& invoice)
//{
//
//}
//void InvoiceData::Update(const Invoice& invoice)
//{
//
//}
//LinkedList<Invoice> InvoiceData::GetAll()
//{
//}
//Invoice* InvoiceData::GetById(const int& invoiceID)
//{
//
//}
//
//
//int InvoiceData::GetSize()
//{
//    return this->list.getSize();
//}