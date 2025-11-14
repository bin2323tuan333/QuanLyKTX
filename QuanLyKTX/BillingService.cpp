#include "BillingService.h"
#include "Room.h"
#include "Invoice.h"
#include "Contract.h"
#include "Student.h"
#include <fstream>
#include <iostream>
using namespace std;

BillingService::BillingService()
{
	this->database = DB::Instance();
}
BillingService::~BillingService()
{
}

LinkedList<IInvoice*>* BillingService::getAllInvoices()
{
	return DB::Instance()->getAllInvoices();
}

LinkedList<IInvoice*> BillingService::getUnpaidInvoices()
{
	LinkedList<IInvoice*> tempList;
	for (ListNode<IInvoice*>* p = DB::Instance()->getAllInvoices()->getHead(); p != nullptr; p = p->next)
	{
		if (!p->value->getIsPaid()) tempList.add(p->value);
	}
	return tempList;
}
LinkedList<IInvoice*> BillingService::getPaidInvoices()
{
	LinkedList<IInvoice*> tempList;
	for (ListNode<IInvoice*>* p = DB::Instance()->getAllInvoices()->getHead(); p != nullptr; p = p->next)
	{
		if (p->value->getIsPaid()) tempList.add(p->value);
	}
	return tempList;
}

IInvoice* BillingService::getInvoiceById(int invoiceId)
{
	return DB::Instance()->getInvoiceByInvoiceId(invoiceId);
}
LinkedList<IInvoice*> BillingService::getInvoicesByStudent(int studentId)
{
	LinkedList<IInvoice*> tempList;
	IStudent* student = DB::Instance()->getStudentByStudentId(studentId);
	for (ListNode<IContract*>* p = student->getContracts()->getHead(); p != nullptr; p = p->next)
	{
		LinkedList<IInvoice*>* invoices = p->value->getInvoices();
		for (ListNode<IInvoice*>* i = invoices->getHead(); i != nullptr; i = i->next) tempList.add(i->value);
	}
	return tempList;
}
int BillingService::createInvoice(const int& roomId, const int& elec, const int& water)
{
	IRoom* room = DB::Instance()->getRoomByRoomId(roomId);
	if (room == nullptr)
		return 0;
	LinkedList<IContract*>* contract = room->getContracts();
	for (ListNode<IContract*>* p = contract->getHead(); p != nullptr; p = p->next)
	{
		IInvoice* invoice = new Invoice();
		invoice->setInvoiceId(this->autoGenId());
		invoice->setContractId(p->value->getContractId());
		invoice->setCreatedDate(Date::getCurrentDay());
		invoice->setElectricFee(elec * this->ELECTRIC_PRICE / room->getCurrentOccupancy());
		invoice->setWaterFee(water * this->WATER_PRICE / room->getCurrentOccupancy());
		invoice->setInternetFee(this->INTERNET_FEE);
		invoice->setRoomFee(this->ROOM_FEE);
		DB::Instance()->addInvoice(*invoice);
		delete invoice;
	}
	return 1;
}
int BillingService::autoGenId()
{
	int maxId = 0;
	for (ListNode<IInvoice*>* p = DB::Instance()->getAllInvoices()->getHead(); p != nullptr; p = p->next)
	{
		if (p->value->getInvoiceId() > maxId) maxId = p->value->getInvoiceId();
	}
	return ++maxId;
}
void BillingService::paidInvoice(const IInvoice& inv)
{
	IInvoice* invoice = DB::Instance()->getInvoiceByInvoiceId(inv.getInvoiceId());
	if (invoice == nullptr) return;
	if (invoice->getIsPaid() == false) invoice->setIsPaid(true);
	return;
}


void BillingService::printInvoice(const IInvoice& inv)
{
	IInvoice* invoice = DB::Instance()->getInvoiceByInvoiceId(inv.getInvoiceId());
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
	outFile << "Trang Thai:              " << (invoice->getIsPaid() ? "Da Thanh Toan" : "Chua Thanh Toan") << "\n";
	outFile << "================================================\n";
	outFile.close();
}