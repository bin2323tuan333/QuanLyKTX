#include "InvoiceService.h"

InvoiceService::InvoiceService(InvoiceRepository& invRepo)
	:invoiceRepo(invRepo)
{
}

InvoiceService::~InvoiceService()
{
}
