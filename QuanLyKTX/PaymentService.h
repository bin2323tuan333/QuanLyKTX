#pragma once
#include "InvoiceRepository.h"

class PaymentService {
private:
    InvoiceRepository& invoiceRepo;

public:
    PaymentService(InvoiceRepository& invRepo);
    ~PaymentService();

    //Invoice getInvoice(const string&, int, int);

    //bool CreateInvoice(const Invoice&);
    //bool UpdateInvoice(const Invoice&);
};