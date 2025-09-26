#pragma once
#include "Invoice.h"




class InvoiceRepository
{
private:
    Invoice* p;
    int n;

public:
    InvoiceRepository();
    ~InvoiceRepository();

    // Create
    void Add(const Invoice&);
    void Insert(const Invoice&, const int&);

    // Read
    void Show();
    int IndexOf(const int&);
    Invoice Search(const int&);

    // Update
    void Update(const int&);

    // Delete
    void Delete(const int&);

    void LoadDataFromFile();
    void SaveDateToFile();
};
