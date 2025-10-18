#pragma once
#include "InvoiceRepository.h"

class InvoiceService {
private:
    InvoiceRepository& invoiceRepo;

public:
    InvoiceService(InvoiceRepository& invRepo);
    ~InvoiceService();

    //Invoice getInvoice(const string&, int, int);

    //bool CreateInvoice(const Invoice&);
    //bool UpdateInvoice(const Invoice&);
};