#include "InvoiceService.h"

InvoiceService::InvoiceService(InvoiceRepository& invRepo)
	:invoiceRepo(invRepo)
{
}

InvoiceService::~InvoiceService()
{
}


int InvoiceService::Add(const Invoice& temp)
{
	this->invoiceRepo.Add(temp);
	return 1;
}
Invoice* InvoiceService::SearchByID(const int& id)
{
	return this->invoiceRepo.GetById(id);
}
LinkedList<Invoice> InvoiceService::GetAll()
{
	return this->invoiceRepo.GetAll();
}
int InvoiceService::Update(const Invoice& temp)
{
	this->invoiceRepo.Update(temp);
	return 1;
}
int InvoiceService::Delete(const Invoice& temp)
{
	this->invoiceRepo.Delete(temp);
	return 1;
}