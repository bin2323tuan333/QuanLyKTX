#pragma once
#include "LinkedList.h"


class Invoice;
class IBillingService
{
public:
    virtual ~IBillingService();
    virtual int createInvoice(const int&, const int&, const int&) = 0;
    virtual int autoGenId() = 0;
    virtual void paidInvoice(const Invoice&) = 0;
    virtual void printInvoice(const Invoice&) = 0;

    virtual Invoice* getInvoiceById(int) = 0;
    virtual LinkedList<Invoice*> getInvoicesByStudent(int) = 0;
    virtual LinkedList<Invoice*>* getAllInvoices() = 0;
    virtual LinkedList<Invoice*> getUnpaidInvoices() = 0;
    virtual LinkedList<Invoice*> getPaidInvoices() = 0;
};