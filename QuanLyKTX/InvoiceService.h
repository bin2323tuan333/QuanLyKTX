#pragma once
#include "InvoiceRepository.h"

class InvoiceService {
private:
    InvoiceRepository& invoiceRepo;

public:
    InvoiceService(InvoiceRepository& invRepo);
    ~InvoiceService();

    int Add(const Invoice&);
    Invoice* SearchByID(const int&);
    LinkedList<Invoice> GetAll();
    int Update(const Invoice&);
    int Delete(const Invoice&);
};