#pragma once
#include "InvoiceDetail.h"
#include <string>
using namespace std;


class InvoiceDetailRepository
{
private:
    InvoiceDetail* p;
    int n;

public:
    InvoiceDetailRepository();
    ~InvoiceDetailRepository();

    // Create
    void Add(const InvoiceDetail&);
    void Insert(const InvoiceDetail&, const int&);

    // Read
    void Show();
    int IndexOf(const int&, const int&);
    InvoiceDetail Search(const int&, const int&);

    // Update
    void Update(InvoiceDetail&);

    // Delete
    void Delete(const int&, const int&);


    void LoadDataFromFile();
    void SaveDateToFile();
};