#include "InvoiceService.h"

InvoiceService::InvoiceService(InvoiceData& invData)
	:invoiceData(invData)
{
}

InvoiceService::~InvoiceService()
{
}


int InvoiceService::Add(const Invoice& temp)
{
	this->invoiceData.Add(temp);
	return 1;
}
Invoice* InvoiceService::SearchByID(const int& id)
{
	return this->invoiceData.GetByInvoiceId(id);
}
LinkedList<Invoice*>* InvoiceService::GetAll()
{
	return this->invoiceData.getList();
}
int InvoiceService::Update(const Invoice& temp)
{
	this->invoiceData.Update(temp);
	return 1;
}
int InvoiceService::Delete(const Invoice& temp)
{
	this->invoiceData.Delete(temp);
	return 1;
}