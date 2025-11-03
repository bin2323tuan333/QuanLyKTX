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
    LinkedList<Invoice*>* getList();

    void Add(const Invoice&);
    void Update(const Invoice&);
    void Delete(const Invoice&);
    Invoice* GetByInvoiceId(const int&);

    int GetSize();
};
