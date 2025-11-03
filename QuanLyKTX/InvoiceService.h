#pragma once
#include "InvoiceData.h"

class InvoiceService {
private:
    InvoiceData& invoiceData;

public:
    InvoiceService(InvoiceData&);
    ~InvoiceService();

    //int Add(const Invoice&);
    //Invoice* SearchByID(const int&);
    //LinkedList<Invoice> GetAll();
    //int Update(const Invoice&);
    //int Delete(const Invoice&);
};