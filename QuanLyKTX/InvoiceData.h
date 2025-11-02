#pragma once
#include "Invoice.h"
#include "LinkedList.h"


class InvoiceData
{
private:
    string fileName;
    LinkedList<Invoice*> list;

public:
    InvoiceData(const string&);
    ~InvoiceData();

    void loadData();
    void saveData();

    void Add(const Invoice&);
    void Update(const Invoice&);
    void Delete(const Invoice&);
    Invoice* GetById(const int&);
    LinkedList<Invoice> GetAll();

    int GetSize();
};
