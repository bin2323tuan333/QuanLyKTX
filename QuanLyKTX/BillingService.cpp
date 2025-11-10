#include "BillingService.h"

BillingService::BillingService()
{
    this->database = DB::Instance();
}
BillingService::~BillingService()
{
}

LinkedList<Invoice*>* BillingService::getAllInvoices()
{
    return DB::Instance()->getAllInvoices();
}

LinkedList<Invoice*> BillingService::getUnpaidInvoices()
{
    LinkedList<Invoice*> tempList;
    for (ListNode<Invoice*>* p = DB::Instance()->getAllInvoices()->getHead(); p != nullptr; p = p->next)
    {
        if (!p->value->getisPaid()) tempList.add(p->value);
    }
    return tempList;
}
LinkedList<Invoice*> BillingService::getPaidInvoices()
{
    LinkedList<Invoice*> tempList;
    for (ListNode<Invoice*>* p = DB::Instance()->getAllInvoices()->getHead(); p != nullptr; p = p->next)
    {
        if (p->value->getisPaid()) tempList.add(p->value);
    }
    return tempList;
}

Invoice* BillingService::getInvoiceById(int invoiceId)
{
    return DB::Instance()->getInvoiceByInvoiceId(invoiceId);
}
LinkedList<Invoice*> BillingService::getInvoicesByStudent(int studentId)
{
    LinkedList<Invoice*> tempList;
    for (ListNode<Contract*>* p = DB::Instance()->getAllContracts()->getHead(); p != nullptr; p = p->next)
    {
        if (p->value->getStudentId() == studentId)
        {
            LinkedList<Invoice*>* invoices = p->value->getInvoices();
            for (ListNode<Invoice*>* i = invoices->getHead(); i != nullptr; i = i->next) tempList.add(i->value);
        }
    }
    return tempList;
}
int BillingService::createInvoice(const int& roomId, const int& elec, const int& water, const int& inter)
{
    Room* room = DB::Instance()->getRoomByRoomId(roomId);
    if (room == nullptr)
        return 0;
    LinkedList<Contract*>* contract = room->getContracts();
    Invoice* invoice = new Invoice();
    invoice->setCreatedDate(Date::getCurrentDay());
    invoice->setElectricFee(elec * this->ELECTRIC_PRICE / room->getCurrentOccupancy());
    invoice->setWaterFee(water * this->WATER_PRICE / room->getCurrentOccupancy());
    invoice->setInternetFee(inter / room->getCurrentOccupancy());
    invoice->setRoomFee(this->ROOM_FEE);
    for (ListNode<Contract*>* p = contract->getHead(); p != nullptr; p = p->next)
    {
        invoice->AddContract(p->value);
    }
    return 1;
}