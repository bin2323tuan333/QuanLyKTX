#pragma once
#include "IBillingService.h"
#include "DB.h"

class BillingService : public IBillingService
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
    int createInvoice(const int&, const int&, const int&) override;
    IInvoice* getInvoiceById(int) override;
    LinkedList<IInvoice*> getInvoicesByStudent(int) override;
    LinkedList<IInvoice*>* getAllInvoices() override;
    int autoGenId() override;
    void paidInvoice(const IInvoice&) override;
    void printInvoice(const IInvoice&) override;
    LinkedList<IInvoice*> getUnpaidInvoices() override;
    LinkedList<IInvoice*> getPaidInvoices() override;
};

