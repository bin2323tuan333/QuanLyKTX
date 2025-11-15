#pragma once
#include "IBillingService.h"
#include "DB.h"


class Invoice;
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
    Invoice* getInvoiceById(int) override;
    LinkedList<Invoice*> getInvoicesByStudent(int) override;
    LinkedList<Invoice*>* getAllInvoices() override;
    int autoGenId() override;
    void paidInvoice(const Invoice&) override;
    void printInvoice(const Invoice&) override;
    LinkedList<Invoice*> getUnpaidInvoices() override;
    LinkedList<Invoice*> getPaidInvoices() override;
};

