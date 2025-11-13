#pragma once
#include "LinkedList.h"


class IInvoice;
class IBillingService
{
public:
    virtual ~IBillingService();
    virtual int createInvoice(const int&, const int&, const int&) = 0;
    virtual int autoGenId() = 0;
    virtual void paidInvoice(const IInvoice&) = 0;
    virtual void printInvoice(const IInvoice&) = 0;

    virtual IInvoice* getInvoiceById(int) = 0;
    virtual LinkedList<IInvoice*> getInvoicesByStudent(int) = 0;
    virtual LinkedList<IInvoice*>* getAllInvoices() = 0;
    virtual LinkedList<IInvoice*> getUnpaidInvoices() = 0;
    virtual LinkedList<IInvoice*> getPaidInvoices() = 0;
};