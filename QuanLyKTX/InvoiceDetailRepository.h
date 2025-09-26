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
    int IndexOf(const int&);
    InvoiceDetail Search(const int&);

    // Update
    void Update(const int&);

    // Delete
    void Delete(const int&);


    void LoadDataFromFile();
    void SaveDateToFile();
};