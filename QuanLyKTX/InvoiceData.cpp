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

        getline(ss, token, ';'); invoice->setInvoiceId(stoi(token));
        getline(ss, token, ';'); invoice->setContractId(stoi(token));
        getline(ss, token, ';'); invoice->setEmployeeId(stoi(token));
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
        file << p->value->getInvoiceId() << ";";
        file << p->value->getContractId() << ";";
        file << p->value->getEmployeeId() << ";";
        file << p->value->getRoomFee() << ";";
        file << p->value->getInternetFee() << ";";
        file << p->value->getElectricFee() << ";";
        file << p->value->getWaterFee() << ";";
        file << p->value->getTotalAmount() << ";";
        file << p->value->getCreatedDate() << endl;
    }
    file.close();
}

LinkedList<Invoice*>* InvoiceData::getList()
{
    return &(this->list);
}

void InvoiceData::Add(const Invoice& invoice)
{
    Invoice* newInvoice = new Invoice(invoice);
    this->list.add(newInvoice);
}

void InvoiceData::Delete(const Invoice& invoice)
{
    Invoice* inv = this->GetByInvoiceId(invoice.getInvoiceId());
    this->list.remove(inv);
    delete inv;
}
void InvoiceData::Update(const Invoice& invoice)
{
    Invoice* inv = this->GetByInvoiceId(invoice.getInvoiceId());
    *inv = invoice;
}

Invoice* InvoiceData::GetByInvoiceId(const int& invoiceID)
{
    for (ListNode<Invoice*>* p = this->list.getHead(); p != nullptr; p = p->next)
    {
        if (p->value->getInvoiceId() == invoiceID)
            return p->value;
    }
    return nullptr;
}


int InvoiceData::GetSize()
{
    return this->list.getSize();
}