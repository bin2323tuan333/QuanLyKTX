#include "BillingService.h"
#include "fstream"
#include "iostream"
using namespace std;

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
int BillingService::createInvoice(const int& roomId, const int& elec, const int& water)
{
	Room* room = DB::Instance()->getRoomByRoomId(roomId);
	if (room == nullptr)
		return 0;
	LinkedList<Contract*>* contract = room->getContracts();
	for (ListNode<Contract*>* p = contract->getHead(); p != nullptr; p = p->next)
	{
		Invoice invoice;
		invoice.setInvoiceId(this->autoGenId());
		invoice.setContractId(p->value->getContractId());
		invoice.setCreatedDate(Date::getCurrentDay());
		invoice.setElectricFee(elec * this->ELECTRIC_PRICE / room->getCurrentOccupancy());
		invoice.setWaterFee(water * this->WATER_PRICE / room->getCurrentOccupancy());
		invoice.setInternetFee(this->INTERNET_FEE);
		invoice.setRoomFee(this->ROOM_FEE);
		DB::Instance()->addInvoice(invoice);
	}
	return 1;
}
int BillingService::autoGenId()
{
	int maxId = 0;
	for (ListNode<Invoice*>* p = DB::Instance()->getAllInvoices()->getHead(); p != nullptr; p = p->next)
	{
		if (p->value->getInvoiceId() > maxId) maxId = p->value->getInvoiceId();
	}
	return ++maxId;
}
void BillingService::paidInvoice(const Invoice& inv)
{
	Invoice* invoice = DB::Instance()->getInvoiceByInvoiceId(inv.getInvoiceId());
	if (invoice == nullptr) return;
	if (invoice->getisPaid() == false) invoice->setisPaid(true);
	return;
}


void BillingService::printInvoice(const Invoice& inv)
{
	Invoice* invoice = DB::Instance()->getInvoiceByInvoiceId(inv.getInvoiceId());
	ofstream outFile("C:/Users/Acer/Desktop/HoaDon/Invoice_" + to_string(inv.getInvoiceId()));
	outFile << "================================================\n";
	outFile << "              HOA DON KY TUC XA                 \n";
	outFile << "================================================\n";
	outFile << "Ma Hoa Don:              " << invoice->getInvoiceId() << "\n";
	outFile << "Ma Phong:                " << invoice->getContract()->getRoomId() << "\n";
	outFile << "Ma Sinh Vien:            " << invoice->getContract()->getStudentId() << "\n";
	outFile << "------------------------------------------------\n";
	outFile << "Tien Phong:              " << invoice->getRoomFee() << " VND\n";
	outFile << "Tien Dien:               " << invoice->getElectricFee() << " VND\n";
	outFile << "Tien Nuoc:               " << invoice->getWaterFee() << " VND\n";
	outFile << "Tien Internet:           " << invoice->getInternetFee() << " VND\n";
	outFile << "------------------------------------------------\n";
	outFile << "Tong Tien:               " << invoice->getTotalAmount() << " VND\n";
	outFile << "Ngay Lap Hoa Don:        " << invoice->getCreatedDate() << "\n";
	outFile << "Trang Thai:              " << (invoice->getisPaid() ? "Da Thanh Toan" : "Chua Thanh Toan") << "\n";
	outFile << "================================================\n";
	outFile.close();
}