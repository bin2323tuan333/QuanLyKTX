#pragma once
#include "DB.h"

class BillingService
{
private:
    DB* database;

    const int ELECTRIC_PRICE = 3000;
    const int INTERNET_FEE = 50000;
    const int WATER_PRICE = 8000;
    const int ROOM_FEE = 200000;
public:
	BillingService();
	~BillingService();

    //// Invoice CRUD
    int createInvoice(const int&, const int&, const int&);
    Invoice* getInvoiceById(int);
    LinkedList<Invoice*> getInvoicesByStudent(int);
    LinkedList<Invoice*>* getAllInvoices();
    int autoGenId();
    void paidInvoice(const Invoice&);
    void printInvoice(const Invoice&);
    LinkedList<Invoice*> getUnpaidInvoices();
    LinkedList<Invoice*> getPaidInvoices();
};

