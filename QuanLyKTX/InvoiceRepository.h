#pragma once
#include "Invoice.h"
#include "LinkedList.h"


class InvoiceRepository
{
private:
    string fileName;
    LinkedList<Invoice> list;

public:
    InvoiceRepository(const string&);
    ~InvoiceRepository();

    void loadData();
    void saveData();

    void Add(const Invoice&);
    void Update(const Invoice&);
    void Delete(const Invoice&);
    Invoice* GetById(const int&);
    LinkedList<Invoice> GetAll();

    int GetSize();
};
